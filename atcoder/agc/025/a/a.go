///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 21:07:03 2018
//
package main

import (
	"fmt"
	"strconv"
)

var N int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)

	v := 1 << 30
	for i := 1; i < N; i++ {
		var val int
		s := strconv.Itoa(i)
		for j := range s {
			val += int(s[j] - '0')
		}
		s = strconv.Itoa(N - i)
		for j := range s {
			val += int(s[j] - '0')
		}
		v = min(v, val)
	}

	fmt.Println(v)
}
