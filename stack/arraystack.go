package stack

import (
	"errors"
	"fmt"
	"strings"

	"github.com/Kavinjsir/return/array"
)

type ArrayStack struct {
	arr array.MyArray
}

type SetArrayStackOption func(*ArrayStack)

const DEFAULT_CAPACITY int = 10

func NewArrayStack(opts ...SetArrayStackOption) *ArrayStack {
	s := &ArrayStack{
		arr: *array.NewArray(array.SetCapcity(DEFAULT_CAPACITY)),
	}

	for _, setOption := range opts {
		setOption(s)
	}

	return s
}

func SetCapcity(capacity int) SetArrayStackOption {
	return func(s *ArrayStack) {
		s.arr = *array.NewArray(array.SetCapcity(capacity))
	}
}

func (s *ArrayStack) GetSize() int {
	return s.arr.GetSize()
}

func (s *ArrayStack) IsEmpty() bool {
	return s.arr.IsEmpty()
}

func (s *ArrayStack) GetCapacity() int {
	return s.arr.GetCapacity()
}

func (s *ArrayStack) Push(element int) {
	s.arr.AddLast(element)
}

func (s *ArrayStack) Pop() (int, error) {
	top, err := s.arr.RemoveLast()
	if err != nil {
		msg := fmt.Sprintf("Failed to pop value:\n%v", err.Error())
		return 0, errors.New(msg)
	}
	return top, nil
}

func (s *ArrayStack) Peek() (int, error) {
	top, err := s.arr.Get(s.arr.GetSize() - 1)
	if err != nil {
		msg := fmt.Sprintf("Failed to get top value:\n%v", err.Error())
		return 0, errors.New(msg)
	}
	return top, nil
}

func (s *ArrayStack) String() string {
	var sb strings.Builder
	sb.WriteString("ArrayStack: [ ")
	size := s.arr.GetSize()
	for i := 0; i < size; i++ {
		elem, _ := s.arr.Get(i)
		sb.WriteString(fmt.Sprintf("%v", elem))

		if i != size-1 {
			sb.WriteString(", ")
		}
	}
	sb.WriteString(" ] top.\n")
	return sb.String()
}
