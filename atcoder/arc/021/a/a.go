///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 11:13:55 2018
//
package main

import (
	"fmt"
)

type pair struct {
	x, y int
}

var graph [][]int

func main() {
	graph = make([][]int, 4)
	for i := range graph {
		graph[i] = make([]int, 4)
		for j := range graph[i] {
			fmt.Scan(&graph[i][j])
		}
	}

	for i := range graph {
		for j := range graph[i] {
			for _, p := range []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
				x := i + p.x
				y := j + p.y
				if 0 <= x && x < 4 && 0 <= y && y < 4 && graph[i][j] == graph[x][y] {
					fmt.Println("CONTINUE")
					return
				}
			}
		}
	}
	fmt.Println("GAMEOVER")
}
