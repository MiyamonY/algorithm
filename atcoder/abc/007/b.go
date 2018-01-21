///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 15:15:27 2018
//
package main

import "fmt"

func main() {
	var A string
	fmt.Scan(&A)

	if A == "a" {
		fmt.Println(-1)
	} else {
		fmt.Println("a")
	}
}
