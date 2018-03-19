package main

import (
	"fmt"
	"sort"
)

var N int
var L []int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)

	L = make([]int, 2*N)
	for i := 0; i < 2*N; i++ {
		fmt.Scan(&L[i])
	}
	sort.Ints(L)

	count := 0
	for i := 0; i < 2*N; i += 2 {
		count += min(L[i], L[i+1])
	}

	fmt.Println(count)
}
