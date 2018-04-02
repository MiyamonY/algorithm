///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr  2 21:43:58 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int
var a []int

func main() {
	fmt.Scan(&N)

	a := make([]int, 3*N)
	for i := range a {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)

	var count int64
	for i := 0; i < N; i++ {
		count += int64(a[len(a)-1-1-2*i])
	}
	fmt.Println(count)
}
