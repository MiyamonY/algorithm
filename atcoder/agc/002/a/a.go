///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Mar 25 19:37:08 2018
//
package main

import (
	"fmt"
)

var a, b int

func main() {
	fmt.Scan(&a, &b)
	if 0 < a {
		fmt.Println("Positive")
	} else if b < 0 {
		if (-a+b+1)%2 == 0 {
			fmt.Println("Positive")
		} else {
			fmt.Println("Negative")
		}
	} else {
		fmt.Println("Zero")
	}
}
