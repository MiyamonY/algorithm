///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Feb 26 09:32:07 2018
//
package main

import (
	"fmt"
)

func main() {
	var x, y, k int
	fmt.Scan(&x, &y, &k)

	if y <= k {
		fmt.Println(x + y - (k - y))
	} else {
		fmt.Println(x + k)
	}
}
