///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 00:26:09 2018
//
package main

import (
	"fmt"
)

var s string

func main() {
	fmt.Scan(&s)

	for i := range s {
		rev := len(s) - 1 - i
		if s[i] == '*' || s[rev] == '*' {
			continue
		} else {
			if s[i] != s[rev] {
				fmt.Println("NO")
				return
			}
		}
	}
	fmt.Println("YES")
}
