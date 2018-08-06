///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 25 08:30:38 2018
//
package main

import (
	"fmt"
)

var s string

func main() {
	fmt.Scan(&s)
	for i := range s {
		fmt.Print(string(s[i]))
		if i == 3 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}
