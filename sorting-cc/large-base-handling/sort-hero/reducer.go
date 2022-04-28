package main

type Node struct {
	fp, value int
}

type NodeHeapBuffer []Node

func (h NodeHeapBuffer) Len() int {
	return len(h)
}

func (h NodeHeapBuffer) Less(i, j int) bool {
	return h[i].value < h[j].value
}

func (h NodeHeapBuffer) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *NodeHeapBuffer) Push(x interface{}) {
	*h = append(*h, x.(Node))
}

func (h *NodeHeapBuffer) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
