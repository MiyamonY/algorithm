///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat May  5 21:11:32 2018
//
package main

import (
	"fmt"
)

var N int

func isPrime(n int) bool {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func primes5() []int {
	arr := make([]int, 0)
	index := 2
	for len(arr) < N {
		if isPrime(index) && (index%5) == 1 {
			arr = append(arr, index)
		}
		index++
	}
	return arr
}

func main() {
	fmt.Scan(&N)

	arr := primes5()
	for i := 0; i < N; i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(arr[i])
	}
	fmt.Println()
}
