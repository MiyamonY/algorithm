///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 15:28:38 2018
//
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	if N%3 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
