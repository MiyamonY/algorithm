///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:20:03 2018
//
package main

import "fmt"

var N string

func isPalidrome(n string) bool {
	for i := range n {
		if n[i] != n[len(n)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Scan(&N)

	if isPalidrome(N) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
