///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 25 08:26:35 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)
	ans := 700
	for i := range S {
		if S[i] == 'o' {
			ans += 100
		}
	}
	fmt.Println(ans)
}
