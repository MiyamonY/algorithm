///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Mar 28 21:33:25 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)
	var n, w, s, e bool

	for i := range S {
		if S[i] == 'N' {
			n = true
		} else if S[i] == 'W' {
			w = true
		} else if S[i] == 'S' {
			s = true
		} else {
			e = true
		}
	}
	if n == s && w == e {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
