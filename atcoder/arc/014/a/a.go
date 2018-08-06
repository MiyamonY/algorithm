///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Apr 20 21:58:44 2018
//
package main

import "fmt"

var N int

func main() {
	fmt.Scan(&N)

	if N%2 == 1 {
		fmt.Println("Red")
	} else {
		fmt.Println("Blue")
	}
}
