package array

import (
	"errors"
	"fmt"
)

type MyArray struct {
	data []int
	size int
}

const DEFAULT_CAPACITY int = 10

type SetArrayOption func(*MyArray)

func NewArray(opts ...SetArrayOption) *MyArray {
	arr := &MyArray{
		data: make([]int, DEFAULT_CAPACITY),
		size: 0,
	}

	for _, setOption := range opts {
		setOption(arr)
	}

	return arr
}

func SetCapcity(capacity int) SetArrayOption {
	return func(arr *MyArray) {
		arr.data = make([]int, capacity)
	}
}

func (arr *MyArray) Insert(element int, index int) error {
	if arr.size == cap(arr.data) {
		return errors.New("Exceed Capacity Limit.")
	}

	if index > arr.size || index < 0 {
		return errors.New("Index outof Range.")
	}

	for pos := arr.size; pos > index; pos-- {
		arr.data[pos] = arr.data[pos-1]
	}

	arr.data[index] = element
	arr.size = arr.size + 1

	return nil
}

func (arr *MyArray) AddFirst(element int) error {
	return arr.Insert(0, element)
}

func (arr *MyArray) AddLast(element int) error {
	return arr.Insert(arr.size, element)
}

func (arr *MyArray) GetCapacity() int {
	return cap(arr.data)
}

func (arr *MyArray) GetSize() int {
	return arr.size
}

func (arr *MyArray) IsEmpty() bool {
	return arr.size == 0
}

func (arr *MyArray) ShowMeta() {
	fmt.Printf("Capacity: %v, Size: %v, IsEmpty: %v\n", cap(arr.data), arr.size, arr.IsEmpty())
}