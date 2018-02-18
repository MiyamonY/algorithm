///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Feb 18 21:21:33 2018
//
package main

import (
	"fmt"
)

type pos struct {
	x int
	y int
}

func dfs(board []string) int {
	visited := make([][]int, len(board))
	for i := range visited {
		visited[i] = make([]int, len(board[i]))
		for j := 0; j < len(board[i]); j++ {
			visited[i][j] = -1
		}
	}

	q := make([]pos, 0)

	q = append(q, pos{0, 0})
	visited[0][0] = 0
	for len(q) > 0 {
		p := q[0]
		q = q[1:]

		x := p.x
		y := p.y
		for _, d := range [4]pos{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
			dx := d.x + x
			dy := d.y + y
			if 0 <= dx && dx < len(board) && 0 <= dy && dy < len(board[0]) && board[dx][dy] == '.' && visited[dx][dy] == -1 {
				visited[dx][dy] = visited[x][y] + 1
				q = append(q, pos{dx, dy})
			}
		}
	}

	return visited[len(board)-1][len(board[0])-1]
}

func main() {
	var H, W int
	fmt.Scan(&H, &W)
	board := make([]string, H)

	for i := range board {
		fmt.Scan(&board[i])
	}

	whites := 0
	for i := range board {
		for j := range board[i] {
			if board[i][j] == '.' {
				whites++
			}
		}
	}

	len := dfs(board)
	if len == -1 {
		fmt.Println(-1)
	} else {
		fmt.Println(whites - 1 - len)
	}
}
