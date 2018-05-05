///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 10:32:24 2018
//
package main

import (
	"fmt"
	"sort"
)

var L, R int
var l, r []int

func main() {
	fmt.Scan(&L, &R)
	l = make([]int, L)
	r = make([]int, R)

	for i := range l {
		fmt.Scan(&l[i])
	}
	for i := range r {
		fmt.Scan(&r[i])
	}

	sort.Ints(l)
	sort.Ints(r)

	count := 0
	index := 0
	for i := range l {
		for j := index; j < len(r); j++ {
			if l[i] == r[j] {
				index = j + 1
				count++
				break
			}
		}
	}
	fmt.Println(count)
}
