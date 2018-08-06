///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 20:31:52 2018
//
package main

import (
	"fmt"
)

var A, B int
var S string

func main() {
	fmt.Scan(&A, &B)
	fmt.Scan(&S)

	if A <= len(S) && len(S) <= B {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
