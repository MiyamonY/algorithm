///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 21:02:05 2018
//
package main

import (
	"fmt"
)

var H, B float64

func main() {
	fmt.Scan(&H, &B)

	fmt.Println(H * H / (100 * 100) * B)
}
