package main

import (
	"github.com/Kavinjsir/return/array"
)

func main() {
	myArr := array.NewArray()
	myArr.ShowMeta()

	myArr = array.NewArray(
		array.SetCapcity(20),
	)
	myArr.ShowMeta()
}
