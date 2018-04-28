///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 18:32:27 2018
//
package main

import (
	"fmt"
)

var S string

func ispalidrome(s string) bool {
	for i := range s {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func reverse(s string) (rev string) {
	for _, v := range s {
		rev = string(v) + rev
	}
	return
}

func main() {
	fmt.Scan(&S)
	min := 100
	for i := range S {
		if ispalidrome(S + reverse(S[0:i])) {
			if i < min {
				min = i
			}
		}
	}
	fmt.Println(min)
}
