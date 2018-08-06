///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Apr 15 11:01:58 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var N, K int
var arr []int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func readLine() string {
	buf := make([]byte, 0, 10e6)

	rdr := bufio.NewReaderSize(os.Stdin, 10e6)
	for {
		l, p, e := rdr.ReadLine()
		if e != nil {
			panic(e)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

func main() {
	fmt.Scan(&N, &K)

	arr = make([]int, N+1)
	strs := strings.Split(readLine(), " ")
	for i := range strs {
		arr[i+1], _ = strconv.Atoi(strs[i])
	}

	sort.Ints(arr)

	left := 0
	right := N + 1
	dp := make([][]bool, N+1)
	for left+1 < right {
		for j := range dp {
			dp[j] = make([]bool, K+1)
		}
		dp[0][0] = true

		i := (left + right) / 2
		for num := 1; num <= N; num++ {
			if i == num {
				dp[num] = dp[num-1]
			} else {
				card := arr[num]
				for j := range dp[num] {
					if j-card >= 0 {
						dp[num][j] = dp[num][j] || dp[num-1][j-card]
					}
					dp[num][j] = dp[num][j] || dp[num-1][j]
				}
			}
		}

		var found bool
		for n := max(0, K-arr[i]); n < K; n++ {
			if dp[N][n] {
				found = true
			}
		}

		if found {
			right = i
		} else {
			left = i
		}
	}

	fmt.Println(left)
}
