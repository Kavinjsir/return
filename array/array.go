package array

import (
	"errors"
	"fmt"
	"strings"
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

func (arr *MyArray) Set(element int, index int) error {
	if index >= arr.size || index < 0 {
		return errors.New("Index out of range.")
	}

	arr.data[index] = element
	return nil
}

func (arr *MyArray) Contains(element int) bool {
	for _, value := range arr.data {
		if value == element {
			return true
		}
	}

	return false
}

func (arr *MyArray) Find(element int) int {
	for idx, value := range arr.data {
		if value == element {
			return idx
		}
	}

	return -1
}

func (arr *MyArray) Remove(index int) (targetElement int, err error) {
	if index < 0 || index >= arr.size {
		return 0, errors.New("Index out of range.")
	}

	targetElement = arr.data[index]
	err = nil

	for i := index + 1; i < arr.size; i++ {
		arr.data[i-1] = arr.data[i]
	}

	arr.size = arr.size - 1

	// Resize array in "lazy" mode
	// Reduce amortized time complexity
	if arr.size*4 < cap(arr.data) && cap(arr.data)/2 > 0 {
		targetLength := cap(arr.data) / 2
		arr.Resize(targetLength)
	}

	return
}

func (arr *MyArray) RemoveFirst() (targetElement int, err error) {
	return arr.Remove(0)
}

func (arr *MyArray) RemoveLast() (targetElement int, err error) {
	return arr.Remove(arr.size - 1)
}

// TODO: Design func RemoveElement(targetElement int)

func (arr *MyArray) Insert(element int, index int) error {
	if index > arr.size || index < 0 {
		return errors.New("Index out of range.")
	}

	if arr.size == cap(arr.data) {
		err := arr.Resize(2 * cap(arr.data))
		if err != nil {
			return errors.New(fmt.Sprintf("Failed to expand array for insertion:\n%v", err))
		}
	}

	for pos := arr.size; pos > index; pos-- {
		arr.data[pos] = arr.data[pos-1]
	}

	arr.data[index] = element
	arr.size = arr.size + 1

	return nil
}

func (arr *MyArray) AddFirst(element int) error {
	return arr.Insert(element, 0)
}

func (arr *MyArray) AddLast(element int) error {
	return arr.Insert(element, arr.size)
}

func (arr *MyArray) GetCapacity() int {
	return cap(arr.data)
}

func (arr *MyArray) Get(index int) (int, error) {
	if index < 0 || index >= arr.size {
		return 0, errors.New("Index out of range.")
	}

	return arr.data[index], nil
}

func (arr *MyArray) GetSize() int {
	return arr.size
}

func (arr *MyArray) IsEmpty() bool {
	return arr.size == 0
}

func (arr *MyArray) Resize(targetLength int) error {
	if targetLength <= 0 {
		return errors.New("Illegal resize length.(Should be positive integer)")
	}

	newData := make([]int, targetLength)
	copy(newData, arr.data)
	arr.data = newData

	return nil
}

func (arr *MyArray) GetMeta() string {
	return fmt.Sprintf("Capacity: %v, Size: %v, IsEmpty: %v\n", cap(arr.data), arr.size, arr.IsEmpty())
}

func (arr *MyArray) String() string {
	var sb strings.Builder

	sb.WriteString(arr.GetMeta())

	sb.WriteString("[ ")

	for i, val := range arr.data {
		if i >= arr.size {
			break
		}

		sb.WriteString(fmt.Sprintf("%v", val))

		if i != arr.size-1 {
			sb.WriteString(", ")
		}
	}

	sb.WriteString(" ]\n")

	return sb.String()
}

func (arr *MyArray) ShowMeta() {
	fmt.Print(arr.GetMeta())
}
