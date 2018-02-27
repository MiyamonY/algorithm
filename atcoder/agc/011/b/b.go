///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Feb 25 23:06:21 2018
//
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	arr := make([]int, N)
	acc := make([]int, N)
	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		arr[i] = A
		acc[i] = A
	}
	sort.Ints(arr)
	sort.Ints(acc)

	for i := 1; i < N; i++ {
		acc[i] += acc[i-1]
	}

	count := -1
	for i := 0; i < N; i++ {
		if i+1 < N && 2*acc[i] < arr[i+1] {
			count = i
		}
	}

	fmt.Println(N - (count + 1))
}
