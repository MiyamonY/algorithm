///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr  1 19:11:47 2018
//
package main

import (
	"fmt"
	"sort"
)

var N, C, K int

func main() {
	fmt.Scan(&N, &C, &K)

	T := make([]int, N)
	for i := range T {
		fmt.Scan(&T[i])
	}
	sort.Ints(T)

	count := 0
	start := 0
	num := 0
	for i := range T {
		t := T[i]
		if start == 0 {
			start = t
			num++
			count++
		} else if start+K < t {
			start = t
			num = 1
			count++
		} else {
			if num == C {
				start = t
				num = 1
				count++
			} else {
				num++
			}
		}
	}

	fmt.Println(count)
}
