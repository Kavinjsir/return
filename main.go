package main

import (
	"fmt"
	// "log"

	// "github.com/Kavinjsir/return/array"
	"github.com/Kavinjsir/return/stack"
)

func main() {
	var myStack stack.Stack

	myStack = stack.NewArrayStack(
		stack.SetCapcity(5),
	)

	for i := 0; i < 5; i++ {
		myStack.Push(i)
		fmt.Println(myStack)
	}

	myStack.Pop()
	fmt.Println(myStack)

	/*
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

		for element := 100; element < 133; element++ {
			myArr.AddLast(element)
		}
		fmt.Print(myArr)

		size := myArr.GetSize()
		for i := 0; i < size-4; i++ {
			myArr.RemoveLast()
		}
		fmt.Print(myArr)
	*/

}
