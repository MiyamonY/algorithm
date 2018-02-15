package main

import (
	"fmt"
)

type cove_t struct {
	left int
	right int
	score int
}

func main(){
	var N, M int
	fmt.Scan(&N, &M)

	total := 0
	scores := make([]int, M+2)
	for i:= 0; i < N; i++{
		var l, r, s int
		fmt.Scan(&l, &r, &s)
		scores[l] += s
		scores[r+1] -= s
		total += s
	}

	for i:= 0; i < len(scores)-1; i++{
		scores[i+1] += scores[i]
	}

	min := 1 << 30
	for i:= 1; i <= M;  i++{
		if scores[i] < min {
			min = scores[i]
		}
	}
	fmt.Println(total - min)
}
