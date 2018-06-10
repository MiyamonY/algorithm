///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jun 10 21:02:32 2018
//
package main

import "fmt"

var a, b int

func main() {
	fmt.Scan(&a, &b)
	n := b - a - 1
	fmt.Println(n*(n+1)/2 - a)
}
