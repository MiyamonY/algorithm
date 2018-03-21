///
// File:  0528.go
// Author: ymiyamoto
//
// Created on Thu Mar 22 01:52:09 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
)

var S, T string
var dp [4001][4001]int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		S = scanner.Text()
		if len(S) == 0 {
			return
		}

		scanner.Scan()
		T = scanner.Text()

		for i := range dp {
			for j := range dp[i] {
				dp[i][j] = 0
			}
		}

		dp[0][0] = 0
		for i := range S {
			for j := range T {
				if S[i] == T[j] {
					dp[i+1][j+1] = dp[i][j] + 1
				} else {
					dp[i+1][j+1] = 0
				}
			}
		}

		var m int
		for i := range dp {
			for j := range dp[i] {
				m = max(m, dp[i][j])
			}
		}
		fmt.Println(m)
	}
}
