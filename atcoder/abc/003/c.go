///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jan 24 01:24:42 2018
//
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	videos := make([]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&videos[i])
	}

	sort.Float64s(videos)

	rate := 0.0
	for i := N - K; i < N; i++ {
		rate = (rate + videos[i]) / 2
	}

	fmt.Printf("%.8f\n", rate)
}
