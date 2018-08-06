///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 11 20:30:49 2018
//
package main

import (
	"fmt"
)

var N int
var s string

func main() {
	fmt.Scan(&N)

	fmt.Scan(&s)
	total := 0.0
	for i := range s {
		switch s[i] {
		case 'A':
			total += 4.0
		case 'B':
			total += 3.0
		case 'C':
			total += 2.0
		case 'D':
			total += 1.0
		default:
			total += 0.0
		}
	}
	fmt.Println(total / float64(N))
}
