///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Apr 10 22:28:09 2018
//
package main

import (
	"fmt"
)

var Y int

func main() {
	fmt.Scan(&Y)

	if Y%400 == 0 {
		fmt.Println("YES")
		return
	} else if Y%100 == 0 {
		fmt.Println("NO")
		return
	} else if Y%4 == 0 {
		fmt.Println("YES")
		return
	}

	fmt.Println("NO")
}
