///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed Jun  6 17:21:24 2018
//
package main

import "fmt"

var N, M int

func main() {
	fmt.Scan(&N, &M)

	arr := make([]int, N+1)
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		arr[a]++
		arr[b]++
	}

	for _, v := range arr {
		if v%2 == 1 {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
