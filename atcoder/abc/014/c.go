package main

import (
	"fmt"
)

func main(){
	var n int
	fmt.Scan(&n)
	colors := make([]int, 1000002)
	for i:= 0; i < n; i++{
		var a, b int
		fmt.Scan(&a, &b)
		colors[a]++
		colors[b+1]--
	}

	max_val := colors[0]
	for i := range(colors){
		if i+1 < 1000002{
			colors[i+1] += colors[i]
			if max_val < colors[i+1]{
				max_val = colors[i+1]
			}
		}
	}

	fmt.Println(max_val)
}
