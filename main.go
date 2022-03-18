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

	for element := 0; element < 20; element++ {
		myArr.AddFirst(element)
	}

	fmt.Print(myArr)

	value, err := myArr.Get(11)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(value)

	myArr = array.NewArray(
		array.SetCapcity(20),
	)

	for element := 0; element < 20; element++ {
		myArr.AddLast(element)
	}

	fmt.Print(myArr)

	value, err = myArr.Get(11)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(value)

}
