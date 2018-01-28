///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jan 27 18:44:00 2018
//
package main

import (
	"fmt"
)

type route struct {
	to  int
	len int
}

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
			dist[i][j] = 1 << 30
		}
		dist[i][i] = 0
	}

	var neighbors []route
	for i := 0; i < M; i++ {
		var u, v, l int
		fmt.Scan(&u, &v, &l)
		u--
		v--
		if u == 0 {
			neighbors = append(neighbors, route{v, l})
		} else if v == 0 {
			neighbors = append(neighbors, route{u, l})
		} else {
			dist[u][v] = l
			dist[v][u] = l
		}
	}

	for k := 0; k < N; k++ {
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
			}
		}
	}

	min_length := 1 << 30
	for i := 0; i < len(neighbors); i++ {
		for j := i + 1; j < len(neighbors); j++ {
			length := 0
			from := neighbors[i].to
			length += neighbors[i].len
			to := neighbors[j].to
			length += neighbors[j].len
			min_length = min(min_length, length+dist[from][to])
		}
	}

	if min_length == 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(min_length)
	}
}
