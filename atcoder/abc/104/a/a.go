// Package main provides
//
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Aug  6 00:33:42 2018
//
package main

import "fmt"

var R int

func main() {
	fmt.Scan(&R)
	if R < 1200 {
		fmt.Println("ABC")
	} else if R < 2800 {
		fmt.Println("ARC")
	} else {
		fmt.Println("AGC")
	}
}
