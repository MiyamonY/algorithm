///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 21:11:57 2018
//
package main

import (
	"fmt"
)

var N int
var S []string

func is_valid(i, j int) bool {
	arr := make([][]uint8, N)
	for i := range arr {
		arr[i] = make([]uint8, N)
	}

	for x := 0; x < N; x++ {
		for y := 0; y < N; y++ {
			k, l := (x+i)%N, (y+j)%N
			arr[x][y] = S[k][l]
		}
	}

	for x := 0; x < N; x++ {
		for y := 0; y < N; y++ {
			if arr[x][y] != arr[y][x] {
				return false
			}
		}
	}
	return true
}

func main() {
	fmt.Scan(&N)
	S = make([]string, N)
	for i := range S {
		fmt.Scan(&S[i])
	}

	count := 0
	for i := range S {
		if is_valid(i, 0) {
			count += N
		}
	}
	fmt.Println(count)
}
