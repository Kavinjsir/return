package main

import (
	"bufio"
	"container/heap"
	"errors"
	"fmt"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"time"
)

const ChunkNum = 10
const ChunkSize = 1000000

const Asset = "asset"
const Input = Asset + "/input"
const Output = Asset + "/output"

func prepareTestData(chunkNum int, chunkSize int, directory string, inputPath string) {
	CleanupFolder(directory)

	f, err := os.Create(inputPath)
	if err != nil {
		fmt.Println("Unable to create the file", err)
		return
	}
	// UPDATE: close after checking error
	defer f.Close() //Do not forget to close the file

	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	w := bufio.NewWriter(f)
	for i := 0; i < chunkNum*chunkSize; i++ {
		fmt.Fprintf(w, "%v ", r.Int31())
	}

	w.Flush() // Don't forget to flush!
}

func createChunks(inputPath string, chunkSize int, folder string) (int, error) {
	f, err := os.Open(inputPath)
	if err != nil {
		fmt.Println("Unable to read input file", err)
		return 0, err
	}

	defer f.Close()

	fileCount := 0
	record := []int{}

	scanner := bufio.NewScanner(f)
	// Set the split function for the scanning operation.
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			return fileCount, err
		}

		record = append(record, num)
		if len(record) == chunkSize {
			// 0. Sort array
			sort.Sort(sort.IntSlice(record))

			// 1. Write array to file ${fileCount}
			outPath := folder + "/" + strconv.Itoa(fileCount)
			WriteIntArrToFile(outPath, record)

			// 2. Cleanup result
			record = nil

			// 3. Update fileCount
			fileCount++
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}

	return fileCount - 1, nil
}

func mergeChunks(fileCount int, folder string, outputPath string) error {
	// 1. Open chunk files
	fps := make([]*bufio.Scanner, fileCount+1)
	for i := 0; i <= fileCount; i++ {
		path := folder + "/" + strconv.Itoa(i)

		f, err := os.OpenFile(path, os.O_RDONLY, 0444)

		if err != nil {
			return errors.New("Unable to read chunk file: " + path + " \n" + err.Error())
		}

		defer f.Close()

		fps[i] = bufio.NewScanner(f)
		fps[i].Split(bufio.ScanWords)
	}

	// 2. Create a Min Heap
	hp := &NodeHeapBuffer{}
	heap.Init(hp)

	// 3. Loop fps, load value and store into heap
	for i, v := range fps {
		if v == nil || !v.Scan() {
			continue
		}

		num, err := strconv.Atoi(v.Text())
		if err != nil {
			return err
		}

		heap.Push(hp, Node{fp: i, value: num})
	}

	// 4. Loop til heap is empty, pop min value, write to output
	f, err := os.Create(outputPath)
	if err != nil {
		fmt.Println("Unable to create the file", err)
		return err
	}
	defer f.Close() //Do not forget to close the file

	w := bufio.NewWriter(f)

	for hp.Len() > 0 {
		var min = heap.Pop(hp).(Node)

		fmt.Fprintf(w, "%v ", min.value)

		// fmt.Println(min)

		if fps[min.fp].Scan() {
			num, err := strconv.Atoi(fps[min.fp].Text())
			if err != nil {
				return err
			}
			heap.Push(hp, Node{fp: min.fp, value: num})
		}
	}

	w.Flush()

	return nil
}

func main() {
	prepareTestData(ChunkNum, ChunkSize, Asset, Input)

	fileCount, err := createChunks(Input, ChunkSize, Asset)
	if err != nil {
		fmt.Println("Error When making chunks:\n" + err.Error())
		return
	}

	err = mergeChunks(fileCount, Asset, Output)
	if err != nil {
		fmt.Println("Error happens when merginc chunks:\n" + err.Error())
		return
	}
}
