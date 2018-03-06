///
// File:  c.go
// Author: ymiyamoto
//
// Created on Mon Mar  5 01:28:26 2018
//
package main

import (
	"fmt"
)

type pos struct {
	x, y int
}

var H, W int
var graph []string

func bfs(start, goal pos) bool {
	visited := make([][]int, H)
	for i := range visited {
		visited[i] = make([]int, W)
		for j := range visited[i] {
			visited[i][j] = -1
		}
	}

	q := make([]pos, 0, 3000)
	visited[start.x][start.y] = 0
	q = append(q, start)

	for len(q) > 0 {
		p := q[0]
		q = q[1:]

		for _, d := range []pos{{x: 1, y: 0}, {x: -1, y: 0}, {x: 0, y: -1}, {x: 0, y: 1}} {
			x := p.x + d.x
			y := p.y + d.y
			if 0 <= x && x < H && 0 <= y && y < W && visited[x][y] == -1 {
				switch graph[x][y] {
				case '#':
					visited[x][y] = visited[p.x][p.y] + 1
					q = append(q, pos{x, y})
				case '.', 's', 'g':
					visited[x][y] = visited[p.x][p.y]
					q = append([]pos{{x, y}}, q...)
				}
			}
		}
	}

	for i := range visited {
		fmt.Println(visited[i])
	}

	return visited[goal.x][goal.y] <= 2
}

func main() {
	fmt.Scan(&H, &W)
	graph = make([]string, H)

	var start, goal pos
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

	if bfs(start, goal) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
