// Package main provides
//
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Aug  4 19:19:34 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int
var arr []int

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Scan(&N)
	arr = make([]int, N)
	for i := range arr {
		fmt.Scan(&arr[i])
		arr[i] = arr[i] - (i + 1)
	}

	sort.Ints(arr)
	b := arr[(0+len(arr))/2]
	var min int64
	for i := range arr {
		min += int64(abs(arr[i] - b))
	}

	fmt.Println(min)
}
