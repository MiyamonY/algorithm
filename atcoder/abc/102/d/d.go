// Package main provides
//
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Aug  5 09:01:17 2018
//
package main

import "fmt"

var N int
var arr []int64

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func min(arr ...int64) int64 {
	var ret int64 = 1 << 60
	for _, a := range arr {
		if a < ret {
			ret = a
		}
	}
	return ret
}

func max(arr ...int64) int64 {
	var ret int64
	for _, a := range arr {
		if ret < a {
			ret = a
		}
	}
	return ret
}

func main() {
	fmt.Scan(&N)
	arr = make([]int64, N)
	for i := range arr {
		fmt.Scan(&arr[i])
	}

	for i := range arr {
		if i+1 < len(arr) {
			arr[i+1] += arr[i]
		}
	}

	p := 2
	pl := 1
	pr := 3
	var ans int64 = 1 << 60
	for p < len(arr)-1 {
		for pl < p-1 && abs(arr[pl]-(arr[p-1]-arr[pl])) < abs(arr[pl-1]-(arr[p-1]-arr[pl-1])) {
			pl++
		}

		for pr < len(arr)-1 && abs(arr[len(arr)-1]-arr[pr]-(arr[pr]-arr[p-1])) < abs(arr[len(arr)-1]-arr[pr-1]-(arr[pr-1]-arr[p-1])) {
			pr++
		}

		P := arr[pl-1]
		Q := arr[p-1] - arr[pl-1]
		R := arr[len(arr)-1] - arr[pr-1]
		S := arr[pr-1] - arr[p-1]
		ans = min(ans, abs(max(P, Q, R, S)-min(P, Q, R, S)))
		p++
	}

	fmt.Println(ans)
}
