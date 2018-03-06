///
// File:  c.go
// Author: ymiyamoto
//
// Created on Tue Mar  6 22:15:13 2018
//
package main

import (
	"fmt"
)

var N, M int
var graph [][]bool

func permutations(n int) [][]int {
	if n == 1 {
		return [][]int{{1}}
	}

	ret := [][]int{}
	perm := permutations(n - 1)
	for i := 0; i < len(perm); i++ {
		for j := 0; j <= len(perm[i]); j++ {
			p := make([]int, len(perm[i]))
			copy(p, perm[i])
			ret = append(ret, append(p[:j], append([]int{n}, p[j:]...)...))
		}
	}
	return ret
}

func main() {
	fmt.Scan(&N, &M)

	graph = make([][]bool, N+1)
	for i := 0; i < N+1; i++ {
		graph[i] = make([]bool, N+1)
	}

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graph[a][b] = true
		graph[b][a] = true
	}

	count := 0
	for _, val := range permutations(N) {
		if val[0] == 1 {
			invalid := false
			for i := range val {
				if i+1 < len(val) {
					if !graph[val[i]][val[i+1]] {
						invalid = true
					}
				}
			}
			if !invalid {
				count++
			}
		}
	}
	fmt.Println(count)
}
