///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 21 16:42:50 2018
//
package main

import (
	"fmt"
)

var N, M int

func main() {
	fmt.Scan(&N, &M)
	for i := 1; i <= N; i++ {
		if i != M {
			fmt.Println(i)
			return
		}
	}
}
