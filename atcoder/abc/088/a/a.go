///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Feb 18 21:00:18 2018
//
package main

import (
	"fmt"
)

func main() {
	var N, A int
	fmt.Scan(&N, &A)
	if N%500 <= A {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
