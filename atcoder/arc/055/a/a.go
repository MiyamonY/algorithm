///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Feb 13 21:49:51 2018
//
package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	fmt.Print("1")
	for i := 0; i < N-1; i++ {
		fmt.Print("0")
	}
	fmt.Println("7")
}
