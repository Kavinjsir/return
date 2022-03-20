package main

import (
	"fmt"

	"github.com/Kavinjsir/return/stack"
)

func isValid(s string) bool {
	if s == "" {
		return true
	}
	pairs := map[rune]rune{
		'}': '{',
		']': '[',
		')': '(',
	}

	stk := stack.NewArrayStack(stack.SetCapcity(1))
	for _, ch := range s {
		switch ch {
		case 40, 123, 91:
			stk.Push(int(ch))
		default:
			top, err := stk.Pop()
			if err != nil || top != int(pairs[ch]) {
				return false
			}
		}
	}
	return stk.GetSize() == 0
}

func main() {
	fmt.Println(isValid("(){}[]"))
	fmt.Println(isValid("()"))
	fmt.Println(isValid("({)}[]"))
}
