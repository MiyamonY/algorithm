///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 21 16:44:45 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	for i := 2; i*i <= N; i++ {
		if N%i == 0 {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
