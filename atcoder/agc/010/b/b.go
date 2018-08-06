///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed Jun  6 20:42:36 2018
//
package main

import "fmt"

var N int64
var arr []int64

func main() {
	fmt.Scan(&N)

	arr := make([]int64, N)
	var total int64
	for i := range arr {
		fmt.Scan(&arr[i])
		total += arr[i]
	}

	sums := N * (N + 1) / 2
	if total%sums != 0 {
		fmt.Println("NO")
		return
	}

	m := total / sums
	diff := make([]int64, N)
	for i := int64(0); i < N; i++ {
		diff[i] = arr[(i+1)%N] - arr[i] - m
	}

	//fmt.Println(diff)

	total = 0
	for _, v := range diff {
		if v > 0 || (-v)%N != 0 {
			fmt.Println("NO")
			return
		}
		total += v
	}

	if (-total)/N == m {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
