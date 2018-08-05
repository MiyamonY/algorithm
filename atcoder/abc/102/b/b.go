// Package main provides
//
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Aug  4 19:16:48 2018
//
package main

import "fmt"

var N int
var arr []int64

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func abs(a int64) int64 {
	if a > 0 {
		return a
	}
	return -a
}

func main() {
	fmt.Scan(&N)
	arr = make([]int64, N)

	for i := range arr {
		fmt.Scan(&arr[i])
	}

	var m int64
	for i := range arr {
		for j := i + 1; j < len(arr); j++ {
			m = max(m, abs(arr[i]-arr[j]))
		}
	}
	fmt.Println(m)
}
