package main

import (
	"fmt"
)

var n int

func main() {
	fmt.Scan(&n)
	var weights []int
	for i := 0; i < n; i++ {
		var w int
		fmt.Scan(&w)
		weights = append(weights, w)
	}

	var heap [50][]int
	for i := 0; i < 50; i++ {
		heap[i] = make([]int, 1)
		heap[i][0] = 1 << 30
	}
	count := 0
	for _, weight := range weights {
		last := 1 << 30
		index := -1
		for i, h := range heap {
			l := h[len(h)-1]
			if weight <= l && l < last {
				last = l
				index = i
			}
		}
		if index == -1 {
			heap[count][0] = weight
			count++
		} else {
			heap[index] = append(heap[index], weight)
		}
	}

	fmt.Println(count)
}
