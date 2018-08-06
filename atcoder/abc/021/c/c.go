///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed May 23 01:48:33 2018
//
package main

import (
	"fmt"
)

var N, M int
var a, b int
var graph [][]int
var sorted []int
var visited []bool

const MOD int64 = 1e9 + 7

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func dfs(a int) {
	for i := range graph[a] {
		if !visited[i] && graph[a][i] == 1 {
			visited[i] = true
			dfs(i)
		}
	}
	sorted = append(sorted, a)
}

func main() {
	fmt.Scan(&N, &a, &b, &M)
	graph = make([][]int, N+1)
	for i := range graph {
		graph[i] = make([]int, N+1)
	}

	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		graph[x][y] = 1
		graph[y][x] = 1
	}

	dist := make([][]int, N+1)
	for i := range dist {
		dist[i] = make([]int, N+1)
		for j := range dist[i] {
			dist[i][j] = 1 << 30
			if i == j {
				dist[i][j] = 0
			}
			if graph[i][j] == 1 {
				dist[i][j] = 1
			}
		}
	}

	for k := 1; k <= N; k++ {
		for i := 1; i <= N; i++ {
			for j := 1; j <= N; j++ {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
			}
		}
	}
	for i := range graph {
		for j := range graph[i] {
			if graph[i][j] == 1 {
				if dist[a][j]-dist[a][i] != 1 {
					graph[i][j] = 0
				}
			}
		}
	}

	sorted = make([]int, N)
	visited = make([]bool, N+1)

	dfs(a)

	for i, j := 0, len(sorted)-1; i < j; i, j = i+1, j-1 {
		sorted[i], sorted[j] = sorted[j], sorted[i]
	}

	dp := make([]int64, N+1)
	dp[a] = 1
	for _, s := range sorted {
		for j := range graph[s] {
			if graph[s][j] == 1 {
				dp[j] += dp[s]
				dp[j] %= MOD
			}
		}
	}
	// fmt.Println(dist)
	// fmt.Println(graph)
	// fmt.Println(sorted)
	// fmt.Println(dp)

	fmt.Println(dp[b] % MOD)
}
