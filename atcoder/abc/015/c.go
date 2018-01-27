///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jan 27 17:52:27 2018
//
package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	T := make([][]int, N)
	for i := range T {
		T[i] = make([]int, K)
	}

	for i := range T {
		for j := range T[0] {
			fmt.Scan(&T[i][j])
		}
	}

	for i := 0; i < int(math.Pow(float64(K), float64(N))); i++ {
		var ans int
		index := i
		for j := range T {
			ans ^= T[j][index%K]
			index /= K
		}

		if ans == 0 {
			fmt.Println("Found")
			return
		}
	}

	fmt.Println("Nothing")
}
