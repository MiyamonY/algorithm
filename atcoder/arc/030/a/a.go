///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 20:18:07 2018
//
package main

import (
	"fmt"
)

var n, k int

func main() {
	fmt.Scan(&n, &k)

	if k <= n/2 {
		fmt.Println("YES")
		return
	}
	fmt.Println("NO")
}
