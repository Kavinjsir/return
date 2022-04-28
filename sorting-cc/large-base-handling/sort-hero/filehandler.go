package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
)

func Exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}

	if os.IsNotExist(err) {
		return false, nil
	}

	return false, err
}

func CleanupFolder(path string) error {
	// exists returns whether the given file or directory exists
	assetExist, _ := Exists(path)
	if assetExist {
		os.RemoveAll(path)
	}

	err := os.Mkdir(path, 0750)
	if err != nil {
		return errors.New("Unable to create the directory: " + path + ".\n" + err.Error())
	}

	return nil
}

func WriteIntArrToFile(path string, arr []int) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}

	defer f.Close()

	w := bufio.NewWriter(f)
	for _, v := range arr {
		fmt.Fprintf(w, "%v ", v)
	}

	w.Flush()

	return nil

}
