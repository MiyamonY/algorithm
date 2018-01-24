///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jan 24 22:23:05 2018
//
package main

import (
	"fmt"
)

type pos struct {
	x int
	y int
}

func wfs(maze []string, start, goal pos) int {
	row := len(maze)
	col := len(maze[0])

	dist := make([][]int, row)
	for i := 0; i < row; i++ {
		dist[i] = make([]int, col)
		for j := 0; j < col; j++ {
			dist[i][j] = -1
		}
	}

	q := make([]pos, 0)
	dist[start.y][start.x] = 0
	q = append(q, start)

	for len(q) > 0 {
		p := q[0]
		q = q[1:]

		for _, d := range []pos{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
			y := p.y + d.y
			x := p.x + d.x
			if 0 <= y && y < row && 0 <= x && x < col && dist[y][x] == -1 && string(maze[y][x]) == "." {
				dist[y][x] = dist[p.y][p.x] + 1
				q = append(q, pos{x, y})
			}
		}
	}

	return dist[goal.y][goal.x]
}

func main() {
	var R, C int
	fmt.Scan(&R, &C)

	var start, goal pos
	fmt.Scan(&start.y, &start.x)
	fmt.Scan(&goal.y, &goal.x)
	start.x--
	start.y--
	goal.x--
	goal.y--

	maze := make([]string, R)

	for i := 0; i < R; i++ {
		fmt.Scan(&maze[i])
	}

	fmt.Println(wfs(maze, start, goal))
}
