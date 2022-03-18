package main

import (
	"fmt"

	"github.com/Kavinjsir/return/array"
)

func main() {
	myArr := array.NewArray()
	fmt.Print(myArr)

	myArr = array.NewArray(
		array.SetCapcity(20),
	)
	fmt.Print(myArr)
}
