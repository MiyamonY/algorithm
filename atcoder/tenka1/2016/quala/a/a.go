///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 11:54:34 2018
//
package main

import "fmt"

func main() {
	ans := 0
	for i := 1; i <= 100; i++ {
		if i%3 == 0 || i%5 == 0 {
		} else {
			ans += i
		}
	}
	fmt.Println(ans)
}
