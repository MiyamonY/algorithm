///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Mar 25 18:42:19 2018
//
package main

import (
	"fmt"
)

func main() {
	matrix := make([]string, 3)
	for i := 0; i < 3; i++ {
		fmt.Scan(&matrix[i])
	}
	for i := 0; i < 3; i++ {
		fmt.Print(string(matrix[i][i]))
	}
	fmt.Println()
}
