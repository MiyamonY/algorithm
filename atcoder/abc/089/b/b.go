///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 21:01:07 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	m := map[string]int{}
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		m[s]++
	}

	if len(m) == 3 {
		fmt.Println("Three")
	} else {
		fmt.Println("Four")
	}
}
