///
// File:  0558.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 20:58:45 2018
//
package main

import (
	"fmt"
	"strconv"
	"strings"
)

type pos struct {
	x, y int
}

var H, W, N int
var graph [][]string

func wfs(p pos, index int) (int, pos) {
	var q []pos
	dists := make([][]int, H)
	for i := range dists {
		dists[i] = make([]int, W)
	}

	q = append(q, p)
	for len(q) > 0 {
		p := q[0]
		dist := dists[p.x][p.y]
		q = q[1:]

		for _, d := range []pos{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
			x := p.x + d.x
			y := p.y + d.y
			if 0 <= x && x < H && 0 <= y && y < W && graph[x][y] != "X" && dists[x][y] == 0 {
				dists[x][y] = dist + 1
				q = append(q, pos{x, y})
			}
		}
	}

	for i := range graph {
		for j := range graph[i] {
			if graph[i][j] == strconv.Itoa(index) {
				return dists[i][j], pos{i, j}
			}
		}
	}

	panic("not found")
}

func main() {
	fmt.Scan(&H, &W, &N)

	var start pos

	graph = make([][]string, H)
	for i := range graph {
		var s string
		fmt.Scan(&s)
		graph[i] = strings.Split(s, "")
		for j := range graph[i] {
			if graph[i][j] == "S" {
				start.x = i
				start.y = j
			}
		}
	}

	count := 0
	for i := 1; i <= N; i++ {
		c, s := wfs(start, i)
		start = s
		count += c
	}

	fmt.Println(count)
}
