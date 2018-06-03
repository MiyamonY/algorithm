///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 21:13:15 2018
//
package main

import (
	"fmt"
	"sort"
)

var N, D int

func main() {
	fmt.Scan(&N, &D)
	cities := make([]int, N)
	for i := range cities {
		fmt.Scan(&cities[i])
	}

	lefts := make([]int, N)
	rights := make([]int, N)
	for i := range cities {
		left := sort.Search(len(cities), func(j int) bool {
			return cities[j]+D >= cities[i]
		})
		if left == len(cities) {
			lefts[i] = 0
		} else {
			lefts[i] = i - left
		}
		right := sort.Search(len(cities), func(j int) bool {
			return cities[i]+D < cities[j]
		})
		if right == len(cities) && cities[len(cities)-1] <= cities[i]+D {
			rights[i] = len(cities) - 1 - i
		} else if right == len(cities) {
			rights[i] = 0
		} else {
			rights[i] = right - 1 - i
		}
	}
	//fmt.Println(lefts)
	//fmt.Println(rights)
	ans := 0
	for i := range cities {
		ans += lefts[i] * rights[i]
	}

	for i := range cities {
		n := rights[i]
		ans -= n * (n - 1) / 2
	}

	fmt.Println(ans)
}
