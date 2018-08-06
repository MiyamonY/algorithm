///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed May 30 20:13:57 2018
//
package main

import "fmt"

var s string

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Scan(&s)

	a := 0
	b := 0
	c := 0

	for i := range s {
		switch s[i] {
		case 'a':
			a++
		case 'b':
			b++
		case 'c':
			c++
		}
	}

	if abs(a-b) <= 1 && abs(b-c) <= 1 && abs(c-a) <= 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
