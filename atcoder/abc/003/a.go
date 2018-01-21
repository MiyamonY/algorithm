///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 16:04:06 2018
//
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	total := 0
	for i := 1; i <= N; i++ {
		total += i * 10000
	}
	fmt.Println(total / N)
}
