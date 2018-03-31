///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Mar 31 21:39:35 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	var s, t string
	fmt.Scan(&N, &s, &t)

	count := len(t)
	for i := range s {
		valid := true
		for j := 0; i+j < len(s); j++ {
			if s[i+j] != t[j] {
				valid = false
			}
		}
		if valid {
			count = i
			break
		}
	}

	fmt.Println(len(s) + count)
}
