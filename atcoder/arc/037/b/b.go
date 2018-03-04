///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 20:27:56 2018
//
package main

import (
	"fmt"
)

var N, M int
var graph [][]bool

func dfs(visited []bool, parent, to int) bool {
	visited[to] = true

	ret := true
	for i := 0; i < N; i++ {
		if graph[to][i] {
			if i != parent {
				if visited[i] {
					return false
				} else {
					ret = ret && dfs(visited, to, i)
				}
			}
		}
	}
	return ret
}

func main() {
	fmt.Scan(&N, &M)
	graph = make([][]bool, N)

	for i := range graph {
		graph[i] = make([]bool, N)
	}

	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		graph[u][v] = true
		graph[v][u] = true
	}

	count := 0
	visited := make([]bool, N)
	for i := 0; i < N; i++ {
		if !visited[i] {
			if dfs(visited, i, i) {
				count++
			}
		}
	}

	fmt.Println(count)
}
