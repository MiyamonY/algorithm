///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 19:52:00 2018
//
package main

import "fmt"

var S string

func main() {
	fmt.Scan(&S)

	if S[:3] == "yah" && S[3] == S[4] {
		fmt.Println("YES")
		return
	}
	fmt.Println("NO")
}
