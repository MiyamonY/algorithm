package main

import (
	"fmt"
)

func min(a, b int64) int64{
	if a < b {
		return a
	}else {
		return b
	}
}

func main(){
	var R, B int64
	fmt.Scan(&R, &B)
	var x, y int64
	fmt.Scan(&x, &y)

	var left int64
	right := min(R, B)+1
	for left + 1 < right{
		mid := (left + right) /2
		num := (R - mid) / (x -1) + (B - mid) / (y -1)
		if mid <= num {
			left = mid
		} else {
			right = mid
		}
	}
	fmt.Println(left)
}
