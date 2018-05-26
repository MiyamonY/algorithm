///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri May 25 00:05:10 2018
//
package main

import (
	"fmt"
)

var N, M int
var visited []bool
var graph [][]int
var graph2 [][]int

func dfs(root int) {
	visited[root] = true

	for _, r := range graph[root] {
		if !visited[r] {
			dfs(r)
		}
	}
}

func main() {
	fmt.Scan(&N, &M)

	graph = make([][]int, N+M)
	for i := range graph {
		graph[i] = make([]int, 0)
	}

	for i := 0; i < N; i++ {
		var K int
		fmt.Scan(&K)
		for j := 0; j < K; j++ {
			var L int
			fmt.Scan(&L)
			L--
			graph[i] = append(graph[i], N+L)
			graph[N+L] = append(graph[N+L], i)
		}
	}

	//fmt.Println(graph)

	visited = make([]bool, N+M)
	dfs(0)

	for i := 0; i < N; i++ {
		if !visited[i] {
			fmt.Println("NO")
			return
		}
	}

	fmt.Println("YES")
}
