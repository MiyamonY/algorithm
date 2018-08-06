///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 17:00:12 2018
//
package main

import "fmt"

var X, Y int64

func main() {
	fmt.Scan(&X, &Y)

	if X%Y == 0 {
		fmt.Println(-1)
		return
	}

	for i := int64(1); ; i++ {
		if X*i%Y != 0 {
			fmt.Println(X * i)
			return
		}
	}
}
