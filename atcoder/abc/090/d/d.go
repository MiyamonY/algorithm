///
// File:  d.go
// Author: ymiyamoto
//
// Created on Tue May 22 00:16:32 2018
//
package main

import (
	"fmt"
)

type node struct {
	to, weight int
}

var N, M int
var vals []int
var graph [][]node

func dfs(root, val int) bool {
	if vals[root] == -(1 << 30) {
		vals[root] = val
	} else {
		if vals[root] != val {
			return false
		}
		return true
	}

	for i := range graph[root] {
		n := graph[root][i]
		to := n.to
		weight := n.weight
		if !dfs(to, vals[root]+weight) {
			return false
		}
	}
	return true
}

func main() {
	fmt.Scan(&N, &M)

	graph = make([][]node, N+1)
	for i := range graph {
		graph[i] = make([]node, 0)
	}

	for i := 0; i < M; i++ {
		var L, R, D int
		fmt.Scan(&L, &R, &D)
		graph[L] = append(graph[L], node{to: R, weight: D})
		graph[R] = append(graph[R], node{to: L, weight: -D})
	}

	vals = make([]int, N+1)
	for i := range vals {
		vals[i] = -(1 << 30)
	}

	for i := 1; i <= N; i++ {
		if vals[i] == -(1<<30) && !dfs(i, 0) {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}
