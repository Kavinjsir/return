package queue

import (
	"errors"
	"fmt"
	"strings"

	"github.com/Kavinjsir/return/array"
)

type ArrayQueue struct {
	arr array.MyArray
}

type SetArrayQueueOption func(*ArrayQueue)

const DEFAULT_CAPACITY int = 1

func NewArrayQueue(opts ...SetArrayQueueOption) *ArrayQueue {

	s := &ArrayQueue{
		arr: *array.NewArray(array.SetCapcity(DEFAULT_CAPACITY)),
	}

	for _, setOption := range opts {
		setOption(s)
	}

	return s
}

func SetCapcity(capacity int) SetArrayQueueOption {
	return func(s *ArrayQueue) {
		s.arr = *array.NewArray(array.SetCapcity(capacity))
	}
}

func (s *ArrayQueue) GetSize() int {
	return s.arr.GetSize()
}

func (s *ArrayQueue) IsEmpty() bool {
	return s.arr.IsEmpty()
}

func (s *ArrayQueue) GetCapacity() int {
	return s.arr.GetCapacity()
}

func (s *ArrayQueue) Enqueue(element int) {
	s.arr.AddLast(element)
}

func (s *ArrayQueue) Dequeue() (int, error) {
	head, err := s.arr.RemoveFirst()
	if err != nil {
		msg := fmt.Sprintf("Failed to head value:\n%v", err.Error())
		return 0, errors.New(msg)
	}
	return head, nil
}

func (s *ArrayQueue) GetFront() (int, error) {
	head, err := s.arr.Get(0)
	if err != nil {
		msg := fmt.Sprintf("Failed to get head value:\n%v", err.Error())
		return 0, errors.New(msg)
	}
	return head, nil
}

func (s *ArrayQueue) String() string {
	var sb strings.Builder
	sb.WriteString("ArrayQueue: Head(front)[ ")
	size := s.arr.GetSize()
	for i := 0; i < size; i++ {
		elem, _ := s.arr.Get(i)
		sb.WriteString(fmt.Sprintf("%v", elem))

		if i != size-1 {
			sb.WriteString(", ")
		}
	}
	sb.WriteString(" ] tail.\n")
	return sb.String()
}
