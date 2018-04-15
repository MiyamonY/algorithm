///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr 15 16:06:21 2018
//
package main

import (
	"fmt"
)

var X string
var s string

func main() {
	fmt.Scan(&X)
	fmt.Scan(&s)
	for i := range s {
		if string(s[i]) != X {
			fmt.Print(string(s[i]))
		}
	}
	fmt.Println()
}
