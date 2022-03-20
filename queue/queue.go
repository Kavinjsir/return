package queue

type Queue interface {
	GetSize() int
	IsEmpty() bool
	Enqueue(e int)
	Dequeue() (int, error)
	GetFront() (int, error)
}
