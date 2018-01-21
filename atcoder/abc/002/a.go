///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 16:28:44 2018
//
package main

import "fmt"

func main() {
	var X, Y int
	fmt.Scan(&X, &Y)

	bigger := 0
	if Y < X {
		bigger = X
	} else {
		bigger = Y
	}
	fmt.Println(bigger)
}
