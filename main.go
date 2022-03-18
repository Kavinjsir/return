package main

import (
	"fmt"

	"github.com/Kavinjsir/return/array"
)

func main() {
	myArr := array.NewArray(
		array.SetCapcity(20),
	)

	for element := 0; element < 20; element++ {
		myArr.AddFirst(element)
	}

	fmt.Print(myArr)

	myArr = array.NewArray(
		array.SetCapcity(20),
	)

	for element := 0; element < 20; element++ {
		myArr.AddLast(element)
	}

	fmt.Print(myArr)

}
