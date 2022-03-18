package main

import (
	"fmt"
	"log"

	"github.com/Kavinjsir/return/array"
)

func main() {
	myArr := array.NewArray(
		array.SetCapcity(20),
	)

	for element := 0; element < 10; element++ {
		myArr.AddLast(element)
	}
	fmt.Print(myArr)

	myArr.Insert(100, 1)
	fmt.Println(myArr)

	myArr.AddFirst(-1)
	fmt.Println(myArr)

	myArr.Remove(2)
	fmt.Println(myArr)

	myArr.RemoveFirst()
	fmt.Println(myArr)

	myArr.RemoveLast()
	fmt.Println(myArr)

	myArr.Set(66, 8)
	fmt.Println(myArr.Contains(66))
	fmt.Println(myArr)

	targetIndex := myArr.Find(1)
	if targetIndex >= 0 {
		_, err := myArr.Remove(targetIndex)
		if err != nil {
			log.Fatalln("Failed to remove element at, ", targetIndex, err)
		}
	}
	fmt.Println(myArr)

}
