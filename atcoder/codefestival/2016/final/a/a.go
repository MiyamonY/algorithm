///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Apr  3 01:05:17 2018
//
package main

import (
	"fmt"
)

var H, W int

func main() {
	fmt.Scan(&H, &W)

	graph := make([][]string, H)
	for i := range graph {
		graph[i] = make([]string, W)
		for j := range graph[i] {
			fmt.Scan(&graph[i][j])
		}
	}
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if graph[i][j] == "snuke" {
				fmt.Printf("%s%d\n", string(j+'A'), i+1)
				return
			}
		}
	}
}
