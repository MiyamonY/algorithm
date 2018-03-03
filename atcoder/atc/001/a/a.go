///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Mar  3 22:33:22 2018
//
package main

import (
	"fmt"
)

type pos struct {
	x, y int
}

func dfs(graph []string, visited [][]bool, start, goal pos) bool {
	if start.x == goal.x && start.y == goal.y {
		return true
	}

	ret := false
	for _, dp := range []pos{{1, 0}, {-1, 0}, {0, 1}, {0, -1}} {
		x := start.x + dp.x
		y := start.y + dp.y
		if 0 <= x && x < len(graph) && 0 <= y && y < len(graph[0]) && graph[x][y] != '#' && !visited[x][y] {
			visited[x][y] = true
			ret = ret || dfs(graph, visited, pos{x, y}, goal)
		}
	}

	return ret
}

func main() {
	var H, W int
	fmt.Scan(&H, &W)

	var start, goal pos

	graph := make([]string, H)
	for i := range graph {
		fmt.Scan(&graph[i])
		for j := range graph[i] {
			if graph[i][j] == 's' {
				start.x = i
				start.y = j
			} else if graph[i][j] == 'g' {
				goal.x = i
				goal.y = j
			}
		}
	}

	visited := make([][]bool, H)
	for i := range visited {
		visited[i] = make([]bool, W)
	}

	if dfs(graph, visited, start, goal) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
