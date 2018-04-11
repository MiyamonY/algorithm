///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 11 21:04:52 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)
	strs := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&strs[i])
		if i == N-1 {
			strs[i] = strs[i][:len(strs[i])-1]
		}
	}

	count := 0
	for _, s := range strs {
		if s == "TAKAHASHIKUN" || s == "Takahashikun" || s == "takahashikun" {
			count++
		}
	}
	fmt.Println(count)
}
