///
// File:  d.go
// Author: ymiyamoto
//
// Created on Tue Apr  3 00:22:08 2018
//
package main

import (
	"fmt"
)

type edge struct {
	from, to, weight int
}

var N, M int
var graph [][]int
var dist []edge

func main() {
	fmt.Scan(&N, &M)

	graph = make([][]int, N)
	for i := range graph {
		graph[i] = make([]int, N)
		for j := range graph[i] {
			graph[i][j] = 1 << 30
		}
	}

	dist = make([]edge, M)
	for i := 0; i < M; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		a--
		b--
		dist[i].from = a
		dist[i].to = b
		dist[i].weight = c
		graph[a][b] = c
		graph[b][a] = c
	}

	for k := 0; k < N; k++ {
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				if graph[i][j] > graph[i][k]+graph[k][j] {
					graph[i][j] = graph[i][k] + graph[k][j]
				}
			}
		}
	}

	count := 0
	for i := range dist {
		d := dist[i]
		if graph[d.from][d.to] < d.weight {
			count++
		}
	}
	fmt.Println(count)
}
