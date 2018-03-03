///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Mar  3 18:36:14 2018
//
package main

import (
	"fmt"
)

func dfs(relations [][]bool, group *[]int, parent, index int) {
	(*group)[parent] = index

	for i := range relations[parent] {
		if relations[parent][i] && (*group)[i] == -1 {
			dfs(relations, group, i, index)
		}
	}
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	relations := make([][]bool, N)
	for i := range relations {
		relations[i] = make([]bool, N)
		relations[i][i] = true
	}

	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		relations[x][y] = true
		relations[y][x] = true
	}

	max := 0
	for i := 0; i < (1 << uint(N)); i++ {
		var members []int
		for j := 0; j < N; j++ {
			if i&(1<<uint(j)) != 0 {
				members = append(members, j)
			}
		}

		valid := true
		for _, m1 := range members {
			for _, m2 := range members {
				if !relations[m1][m2] {
					valid = false
				}
			}
		}

		if valid && max < len(members) {
			max = len(members)
		}
	}

	fmt.Println(max)
}
