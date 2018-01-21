///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 15:42:42 2018
//
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	Ts := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&Ts[i])
	}

	sort.Ints(Ts)
	fmt.Println(Ts[0])
}
