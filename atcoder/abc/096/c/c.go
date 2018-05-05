///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat May  5 21:05:21 2018
//
package main

import (
	"fmt"
)

type pair struct {
	x, y int
}

var H, W int

func main() {
	fmt.Scan(&H, &W)

	graph := make([]string, H)
	for i := range graph {
		fmt.Scan(&graph[i])
	}

	for i := range graph {
		for j := range graph[i] {
			if graph[i][j] == '#' {
				invalid := true
				for _, p := range []pair{{-1, 0}, {1, 0}, {0, 1}, {0, -1}} {
					x := i + p.x
					y := j + p.y
					if 0 <= x && x < H && 0 <= y && y < W && graph[x][y] == '#' {
						invalid = false
					}
				}
				if invalid {
					fmt.Println("No")
					return
				}
			}
		}
	}
	fmt.Println("Yes")
}
