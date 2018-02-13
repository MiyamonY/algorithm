///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Feb 13 22:47:49 2018
//
package main

import (
	"fmt"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)

	if H == 1 && W == 1 {
		fmt.Println(0)
	} else if H == 1 {
		fmt.Println(W - 1)
	} else if W == 1 {
		fmt.Println(H - 1)
	} else {
		fmt.Println((H-1)*W + H*(W-1))
	}
}
