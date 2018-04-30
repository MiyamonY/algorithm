///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:12:00 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)
	fmt.Println(N * (N + 1) / 2)
}
