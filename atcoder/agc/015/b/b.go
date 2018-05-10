///
// File:  b.go
// Author: ymiyamoto
//
// Created on Thu May 10 21:00:10 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)

	var count int64
	N := int64(len(S))
	for i := range S {
		n := int64(i)
		switch S[i] {
		case 'U':
			count += (N - n - 1) + 2*n
		case 'D':
			count += 2*(N-n-1) + n
		}
	}

	fmt.Println(count)
}
