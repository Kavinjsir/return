package queue

import (
	"errors"
	"fmt"
	"strings"
)

type LoopQueue struct {
	data  []int
	front int
	tail  int
	size  int // TODO: we don't necessarily need this.
}

const LOOP_QUEUE_DEFAULT_CAPACITY = 5

type SetLoopQueueOption func(*LoopQueue)

func NewLoopQueue(opts ...SetLoopQueueOption) *LoopQueue {
	q := &LoopQueue{
		data:  make([]int, LOOP_QUEUE_DEFAULT_CAPACITY),
		front: 0,
		tail:  0,
		size:  0,
	}

	for _, setOption := range opts {
		setOption(q)
	}

	return q
}

func SetLoopQueueCapcity(capacity int) SetLoopQueueOption {
	return func(q *LoopQueue) {
		q.data = make([]int, capacity)
	}
}

func (q *LoopQueue) GetCapacity() int {
	// Array cannot be fulfilled,
	// `front` == `tail` only when size is "empty".
	return len(q.data) - 1
}

func (q *LoopQueue) IsEmpty() bool {
	return q.front == q.tail
}

func (q *LoopQueue) GetSize() int {
	return q.size
}

func (q *LoopQueue) Enqueue(element int) {
	fmt.Println(q.front, q.tail, q.data)
	// Expand data size if tail is about to meet front
	if (q.tail+1)%len(q.data) == q.front {
		q.resize(q.GetCapacity() * 2)
	}
	fmt.Println("[Enqueue] [tail]", q.tail)

	// Add element at tail
	q.data[q.tail] = element
	// Update tail, (bascially += 1, but apply % len(q.data) to avoid overflow)
	q.tail = (q.tail + 1) % len(q.data)
	fmt.Println("[Updated][Enqueue] [tail]", q.tail)
	// Update size
	q.size++
}

func (q *LoopQueue) Dequeue() (int, error) {
	if q.IsEmpty() == true {
		return 0, errors.New("Failed to dequeue, queue is empty.")
	}

	head := q.data[q.front]
	q.data[q.front] = 0
	q.front = (q.front + 1) % len(q.data)
	q.size--

	capacity := q.GetCapacity()
	if q.size == capacity/4 && capacity/2 > 0 {
		q.resize(capacity / 2)
	}

	return head, nil
}

func (q *LoopQueue) GetFront() (int, error) {
	if q.IsEmpty() {
		return 0, errors.New("Empty queue.")
	}
	return q.data[q.front], nil
}

func (q *LoopQueue) resize(newCap int) {
	fmt.Println("Trigger resize", newCap)
	newData := make([]int, newCap)
	for i := 0; i < q.size; i++ {
		newData[i] = q.data[(i+q.front)%len(q.data)]
	}
	q.data = newData
	fmt.Println("New data", newData)
	fmt.Println("queue data", q.data)
	q.front = 0
	q.tail = q.size
}

func (q *LoopQueue) String() string {
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("LoopQueue: size = %d, capacity = %d\n", q.size, q.GetCapacity()))
	sb.WriteString("Front[ ")
	for i := q.front; i != q.tail; i = (i + 1) % len(q.data) {
		sb.WriteString(fmt.Sprintf("%v", q.data[i]))

		if (i+1)%len(q.data) != q.tail {
			sb.WriteString(", ")
		}
	}

	sb.WriteString(" ] tail.\n")
	return sb.String()
}
