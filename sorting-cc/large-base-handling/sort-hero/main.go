package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"sort"
	"strconv"
)

const ChunkNum = 10
const ChunkSize = 1000

const Asset = "asset"
const Input = Asset + "/input"

// const Output = "output";

func prepareTestData(chunkNum int, chunkSize int, directory string, inputPath string) {
	CleanupFolder(directory)

	f, err := os.Create(inputPath)
	if err != nil {
		fmt.Println("Unable to create the file", err)
		return
	}
	// UPDATE: close after checking error
	defer f.Close() //Do not forget to close the file

	r := rand.New(rand.NewSource(99))
	w := bufio.NewWriter(f)
	for i := 0; i < chunkNum*chunkSize; i++ {
		fmt.Fprintf(w, "%v ", r.Int31())
	}

	w.Flush() // Don't forget to flush!
}

func createChunks(inputPath string, chunkSize int, folder string) error {
	f, err := os.Open(inputPath)
	if err != nil {
		fmt.Println("Unable to read input file", err)
		return err
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
			return err
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

	return nil
}

func main() {
	prepareTestData(ChunkNum, ChunkSize, Asset, Input)
	createChunks(Input, ChunkSize, Asset)
}
