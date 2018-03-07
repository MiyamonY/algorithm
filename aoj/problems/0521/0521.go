///
// File:  0521.go
// Author: ymiyamoto
//
// Created on Wed Mar  7 22:11:28 2018
//
package main

import (
	"fmt"
)

var money int

func main() {
	for {
		fmt.Scan(&money)
		if money == 0 {
			break
		}
		rem := 1000 - money

		count := 0
		for _, coin := range []int{500, 100, 50, 10, 5, 1} {
			count += rem / coin
			rem %= coin
		}
		fmt.Println(count)
	}
}
