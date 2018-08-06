///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:25:17 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int
var ts []int

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func main() {
	fmt.Scan(&N)
	ts = make([]int, N)
	for i := range ts {
		fmt.Scan(&ts[i])
	}

	if N == 1 {
		fmt.Println(ts[0])
		return
	}

	sort.Ints(ts)
	a, b := ts[len(ts)-1], ts[len(ts)-2]
	for i := len(ts) - 3; i >= 0; i-- {
		if a < b {
			a += ts[i]
		} else {
			b += ts[i]
		}
	}

	fmt.Println(max(a, b))
}
