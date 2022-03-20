package stack

type Stack interface {
	GetSize() int
	IsEmpty() bool
	Push(e int)
	Pop() (int, error)
	Peek() (int, error)
}
