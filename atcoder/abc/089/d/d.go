///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 21:14:02 2018
//
package main

import (
	"fmt"
)

func abs(a int) int {
	if 0 < a {
		return a
	} else {
		return -a
	}
}

type pos struct {
	x, y int
}

func (p pos) dist(q pos) int {
	return abs(p.x-q.x) + abs(p.y-q.y)
}

var H, W, D int
var Q int
var poss []pos

func main() {
	fmt.Scan(&H, &W, &D)

	poss = make([]pos, H*W+1)
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			var val int
			fmt.Scan(&val)
			poss[val] = pos{i + 1, j + 1}
		}
	}

	dp := make([]int, H*W+1)
	for i := D + 1; i <= H*W; i++ {
		dp[i] = dp[i-D] + poss[i].dist(poss[i-D])
	}

	fmt.Scan(&Q)
	for i := 0; i < Q; i++ {
		var L, R int
		fmt.Scan(&L, &R)
		fmt.Println(dp[R] - dp[L])
	}
}
