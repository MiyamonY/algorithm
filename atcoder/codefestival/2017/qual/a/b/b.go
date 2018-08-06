///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 15:28:55 2018
//
package main

import "fmt"

var N, M, K int

func main() {
	fmt.Scan(&N, &M, &K)
	for i := 0; i <= M; i++ {
		for j := 0; j <= N; j++ {
			if K == i*N+j*M-2*i*j {
				fmt.Println("Yes")
				return
			}
		}
	}
	fmt.Println("No")
}
