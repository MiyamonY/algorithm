///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Jun 10 21:21:55 2018
//
package main

import "fmt"

var N, C int

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
func main() {
	fmt.Scan(&N, &C)

	colors := make([][]int, C+1)
	for i := 1; i <= C; i++ {
		colors[i] = make([]int, C+1)
		for j := 1; j <= C; j++ {
			fmt.Scan(&colors[i][j])
		}
	}

	g0 := map[int]int{}
	g1 := map[int]int{}
	g2 := map[int]int{}
	for i := 1; i <= N; i++ {
		for j := 1; j <= N; j++ {
			var c int
			fmt.Scan(&c)
			switch (i + j) % 3 {
			case 0:
				g0[c]++
			case 1:
				g1[c]++
			case 2:
				g2[c]++
			}
		}
	}

	ans := int64(1 << 30)
	for i := 1; i <= C; i++ {
		for j := 1; j <= C; j++ {
			for l := 1; l <= C; l++ {
				if i != j && j != l && l != i {
					var tmp int64
					for k, v := range g0 {
						tmp += int64(colors[k][i] * v)
					}
					for k, v := range g1 {
						tmp += int64(colors[k][j] * v)
					}
					for k, v := range g2 {
						tmp += int64(colors[k][l] * v)
					}
					ans = min(ans, tmp)
				}
			}
		}
	}
	fmt.Println(ans)
}
