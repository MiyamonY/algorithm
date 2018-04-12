///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 12 21:20:56 2018
//
package main

import (
	"fmt"
)

var B int

func main() {
	var arr, arr1 [10]bool

	for i := 0; i < 6; i++ {
		var a int
		fmt.Scan(&a)
		arr[a] = true
	}

	fmt.Scan(&B)

	for i := 0; i < 6; i++ {
		var a int
		fmt.Scan(&a)
		arr1[a] = true
	}

	count := 0
	for i := range arr {
		if arr[i] && arr1[i] {
			count++
		}
	}

	switch count {
	case 6:
		fmt.Println(1)
	case 5:
		if arr1[B] {
			fmt.Println(2)
		} else {
			fmt.Println(3)
		}
	case 4:
		fmt.Println(4)
	case 3:
		fmt.Println(5)
	default:
		fmt.Println(0)
	}
}
