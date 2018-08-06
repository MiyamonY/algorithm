///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May 12 20:36:32 2018
//
package main

import (
	"fmt"
)

var N, x int

func main() {
	fmt.Scan(&N, &x)

	if x == 1 || x == 2*N-1 {
		fmt.Println("No")
		return
	}

	arr := make([]int, 2*N-1)
	val := 1
	mid := (2*N - 1) / 2
	for i := 0; i < len(arr); i++ {
		if i == mid-1 {
			if x == 2 {
				arr[i] = x + 1
			} else {
				arr[i] = x - 2
			}
		} else if i == mid {
			if x == 2 {
				arr[i] = x
			} else {
				arr[i] = x + 1
			}
		} else if i == mid+1 {
			if x == 2 {
				arr[i] = x - 1
			} else {
				arr[i] = x
			}
		} else if i == mid+2 {
			if x == 2 {
				arr[i] = x + 2
			} else {
				arr[i] = x - 1
			}
		} else {
			if x == 2 {
				if val == x-1 {
					val = x + 3
				}
			} else {
				if val == x-2 {
					val = x + 2
				}
			}
			arr[i] = val
			val++
		}
	}

	fmt.Println("Yes")
	for i := range arr {
		fmt.Println(arr[i])
	}
}
