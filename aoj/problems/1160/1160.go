///
// File:  1160.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 20:45:57 2018
//
package main

import (
	"fmt"
)

var w, h int
var graph [][]string

func dfs(visited [][]bool, x, y int) {
	visited[x][y] = true

	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			dx := x + i
			dy := y + j
			if 0 <= dx && dx < h && 0 <= dy && dy < w && graph[dx][dy] == "1" && !visited[dx][dy] {
				dfs(visited, dx, dy)
			}
		}
	}
}

func main() {
	for {
		fmt.Scan(&w, &h)
		if w == 0 && h == 0 {
			break
		}

		graph = make([][]string, h)
		for i := range graph {
			graph[i] = make([]string, w)
		}

		for i := 0; i < h; i++ {
			for j := 0; j < w; j++ {
				var s string
				fmt.Scan(&s)
				graph[i][j] = s
			}
		}

		visited := make([][]bool, h)
		for i := range visited {
			visited[i] = make([]bool, w)
		}

		count := 0
		for i := range graph {
			for j := range graph[i] {
				if graph[i][j] == "1" && !visited[i][j] {
					dfs(visited, i, j)
					count++
				}
			}
		}

		fmt.Println(count)
	}
}
