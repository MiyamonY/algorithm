///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Mar 25 21:02:59 2018
//
package main

import (
	"fmt"
)

var N int
var D, X int

func main() {
	fmt.Scan(&N)
	fmt.Scan(&D, &X)

	days := make([]int, N)
	for i := range days {
		fmt.Scan(&days[i])
	}

	count := 0
	for i := range days {
		count += (D-1)/days[i] + 1
	}

	fmt.Println(count + X)
}
