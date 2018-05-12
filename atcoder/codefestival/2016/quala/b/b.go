///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May 12 10:23:57 2018
//
package main

import (
	"fmt"
)

var N int
var arr []int

func main() {
	fmt.Scan(&N)

	arr = make([]int, N)
	for i := range arr {
		fmt.Scan(&arr[i])
		arr[i]--
	}

	var count int
	for i := range arr {
		j := arr[arr[i]]
		if i < arr[i] && j == i {
			count++
		}
	}
	fmt.Println(count)
}
