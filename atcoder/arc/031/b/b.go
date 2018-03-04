///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Mar  3 23:06:41 2018
//
package main

import (
	"fmt"
	"strings"
)

var islands [][]string

func dfs(x, y int, visited [][]bool) {
	visited[x][y] = true

	for _, p := range [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}} {
		dx := x + p[0]
		dy := y + p[1]
		if 0 <= dx && dx < 10 && 0 <= dy && dy < 10 && islands[dx][dy] == "o" && !visited[dx][dy] {
			dfs(dx, dy, visited)
		}
	}
}

func one_island() bool {
	visited := make([][]bool, 10)
	for i := range visited {
		visited[i] = make([]bool, 10)
	}

	count := 0
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if !visited[i][j] && islands[i][j] == "o" {
				dfs(i, j, visited)
				count++
			}
		}
	}

	return count == 1
}

func main() {
	islands = make([][]string, 10)
	for i := range islands {
		islands[i] = make([]string, 10)
	}

	for i := range islands {
		var s string
		fmt.Scan(&s)
		islands[i] = strings.Split(s, "")
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if islands[i][j] == "x" {
				islands[i][j] = "o"
				if one_island() {
					fmt.Println("YES")
					return
				}
				islands[i][j] = "x"
			}
		}
	}

	fmt.Println("NO")
}
