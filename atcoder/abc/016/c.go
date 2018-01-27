///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jan 27 18:10:52 2018
//
package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	dist := make([][]int, N)
	for i := range dist {
		dist[i] = make([]int, N)
		for j := range dist[i] {
			dist[i][j] = 1 << 20
			dist[i][i] = 0
		}
	}

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		dist[a][b] = 1
		dist[b][a] = 1
	}

	for k := 0; k < N; k++ {
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
			}
		}
	}

	for i := 0; i < N; i++ {
		var count int
		for j := 0; j < N; j++ {
			if dist[i][j] == 2 {
				count++
			}
		}
		fmt.Println(count)
	}
}
