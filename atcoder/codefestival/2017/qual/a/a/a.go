///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri May 25 00:02:20 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)
	if len(S) < 4 {
		fmt.Println("No")
		return
	}

	if S[:4] == "YAKI" {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
