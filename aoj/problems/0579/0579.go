///
// File:  0579.go
// Author: ymiyamoto
//
// Created on Mon Mar 19 18:46:50 2018
//
package main

import (
	"fmt"
)

var D, N int

type cloth struct {
	A, B, C int
}

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&D, &N)
	thermals := make([]int, D+1)

	for i := 1; i <= D; i++ {
		fmt.Scan(&thermals[i])
	}

	clothes := make([]cloth, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&clothes[i].A, &clothes[i].B, &clothes[i].C)
	}

	dp := make([][]int, D+1)
	for i := range dp {
		dp[i] = make([]int, N)
	}

	for i := 1; i < D; i++ {
		for j := 0; j < N; j++ {
			for k := 0; k < N; k++ {
				t1 := thermals[i]
				t2 := thermals[i+1]
				if clothes[j].A <= t2 && t2 <= clothes[j].B && clothes[k].A <= t1 && t1 <= clothes[k].B {
					dp[i+1][j] = max(dp[i+1][j], dp[i][k]+abs(clothes[j].C-clothes[k].C))
				}
			}
		}
	}

	val := 0
	for _, v := range dp[D] {
		val = max(val, v)
	}

	fmt.Println(val)
}
