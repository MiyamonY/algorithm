///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr 29 12:28:08 2018
//
package main

import (
	"fmt"
)

var S string

const s string = "CODEFESTIVAL2016"

func main() {
	fmt.Scan(&S)
	count := 0
	for i := range S {
		if S[i] != s[i] {
			count++
		}
	}
	fmt.Println(count)
}
