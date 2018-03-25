package main

import (
	"fmt"
)

var A, B, C, D int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&A, &B, &C, &D)
	fmt.Println(min(A, B) + min(C, D))
}
