///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr 29 12:24:52 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	max := 0.0
	for i := 0; i < N; i++ {
		var a, b, c, d, e float64
		fmt.Scan(&a, &b, &c, &d, &e)
		total := a + b + c + d + e*110/900
		if max < total {
			max = total
		}
	}
	fmt.Println(max)
}
