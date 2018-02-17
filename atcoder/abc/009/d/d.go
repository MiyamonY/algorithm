///
// File:  d.go
// Author: ymiyamoto
//
// Created on Fri Feb 16 21:52:31 2018
//
package main

import (
	"fmt"
)

func prod(A, B [][]uint32) [][]uint32 {
	C := make([][]uint32, len(A))
	for i := range C {
		C[i] = make([]uint32, len(A))
	}

	for i := range A {
		for j := range B {
			var tmp uint32
			for k := range A[i] {
				tmp ^= A[i][k] & B[k][j]
			}
			C[i][j] = tmp
		}
	}
	return C
}

func fast_pow(Cs [][]uint32, K uint64) [][]uint32 {
	A := Cs
	ans := make([][]uint32, len(Cs))
	for i := range ans {
		ans[i] = make([]uint32, len(Cs))
		ans[i][i] = 0xFFFFFFFF
	}

	for K > 0 {
		if (K & 1) == 1 {
			ans = prod(ans, A)
		}
		A = prod(A, A)
		K >>= 1
	}

	return ans
}

func main() {
	var K, M int
	fmt.Scan(&K, &M)

	A := make([][]uint32, K)
	for i := range A {
		A[i] = make([]uint32, K)
	}
	for i := range A {
		fmt.Scan(&A[K-1-i][0])
	}

	C := make([][]uint32, K)
	for i := range C {
		C[i] = make([]uint32, K)
	}
	for i := range C {
		fmt.Scan(&C[0][i])
		if i+1 < len(C) {
			C[i+1][i] = 0xFFFFFFFF
		}
	}

	if M-K > 0 {
		D := fast_pow(C, uint64(M-K))
		fmt.Println(prod(D, A)[0][0])
	} else {
		fmt.Println(A[K-M][0])
	}
}
