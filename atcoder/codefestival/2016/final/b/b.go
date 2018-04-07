///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Apr  7 17:26:27 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int

func main() {
	fmt.Scan(&N)

	arr := make([]int, N)
	for i := 0; i < N; i++ {
		arr[i] = i + 1
	}

	f := func(i int) bool {
		rest := N
		for j := i; j >= 0; j-- {
			if rest-arr[j] == 0 {
				return true
			} else if rest-arr[j] > 0 {
				rest -= arr[j]
			}
		}
		return false
	}

	i := sort.Search(len(arr)-1, f)
	for j := i; j >= 0; j-- {
		if N-arr[j] == 0 {
			fmt.Println(arr[j])
			break
		} else if N-arr[j] > 0 {
			fmt.Println(arr[j])
			N -= arr[j]
		}
	}
}
