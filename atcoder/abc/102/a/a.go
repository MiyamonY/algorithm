// Package main provides
//
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Aug  4 19:15:43 2018
//
package main

import "fmt"

var N int

func main() {
	fmt.Scan(&N)
	if N%2 == 0 {
		fmt.Println(N)
		return
	}
	fmt.Println(2 * N)
}
