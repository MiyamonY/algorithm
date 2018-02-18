///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Feb 18 21:01:52 2018
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
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}
	sort.Ints(arr)

	alice := 0
	bob := 0
	count := 0
	for i := N - 1; i >= 0; i-- {
		if count%2 == 0 {
			alice += arr[i]
		} else {
			bob += arr[i]
		}
		count++
	}
	fmt.Println(alice - bob)
}
