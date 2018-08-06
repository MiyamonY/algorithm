///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 11:01:25 2018
//
package main

import (
	"fmt"
	"sort"
)

var N, K int
var A []int

func gcd(a, b int) int {
	if b > a {
		return gcd(b, a)
	}

	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	fmt.Scan(&N, &K)

	A = make([]int, N)
	for i := range A {
		fmt.Scan(&A[i])
	}

	sort.Ints(A)
	max := A[len(A)-1]
	if max < K {
		fmt.Println("IMPOSSIBLE")
		return
	}

	if N == 1 {
		if A[0] == K {
			fmt.Println("POSSIBLE")
			return
		}
		fmt.Println("IMPOSSIBLE")
		return
	}

	g := gcd(A[0], A[1])
	for i := 2; i < len(A)-1; i++ {
		g = gcd(g, A[i])
	}
	if K%g == 0 {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}
