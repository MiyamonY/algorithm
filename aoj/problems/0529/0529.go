///
// File:  0529.go
// Author: ymiyamoto
//
// Created on Wed Feb 28 20:39:28 2018
//
package main

import (
	"fmt"
	"sort"
)

func max(n, m int64) int64 {
	if n < m {
		return m
	} else {
		return n
	}
}

func main() {
	for {
		var N int
		var M int64
		fmt.Scan(&N, &M)
		if N == 0 && M == 0 {
			break
		}

		arr := make([]int64, N+1)
		for i := 1; i <= N; i++ {
			fmt.Scan(&arr[i])
		}
		sort.Slice(arr, func(i, j int) bool { return arr[i] < arr[j] })

		sums := make([]int64, len(arr)*len(arr))
		for i := 0; i < len(arr); i++ {
			for j := 0; j < len(arr); j++ {
				sums[i*len(arr)+j] = arr[i] + arr[j]
			}
		}

		sort.Slice(sums, func(i, j int) bool { return sums[i] < sums[j] })
		var m int64 = 0
		for _, val := range sums {
			rem := M - val
			if rem >= 0 {
				index := sort.Search(len(sums), func(i int) bool { return sums[i] > rem }) - 1
				if index >= 0 {
					m = max(m, val+sums[index])
				}
			}
		}
		fmt.Println(m)
	}
}
