///
// File:  d.go
// Author: ymiyamoto
//
// Created on Tue May 22 22:21:04 2018
//
package main

import (
	"fmt"
)

var N int
var ts []float64
var vs []float64

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)

	ts = make([]float64, N)
	vs = make([]float64, N)

	for i := range ts {
		fmt.Scan(&ts[i])
		ts[i] *= 2
		if i != 0 {
			ts[i] += ts[i-1]
		}
	}

	for i := range vs {
		fmt.Scan(&vs[i])
	}

	equations := make([][]float64, N+2)
	for i := range equations {
		equations[i] = make([]float64, int(ts[len(ts)-1])+1)
	}

	for i := 0; i < N; i++ {
		for j := range equations[i] {
			if i == 0 {
				if 0 <= j && float64(j) <= ts[i] {
					equations[i][j] = vs[i]
				} else if ts[i] < float64(j) {
					equations[i][j] = equations[i][j-1] + 0.5
				}
			} else {
				if ts[i-1] <= float64(j) && float64(j) <= ts[i] {
					equations[i][j] = vs[i]
				} else if ts[i] < float64(j) {
					equations[i][j] = equations[i][j-1] + 0.5
				} else {
					equations[i][j] = vs[i] + (ts[i-1]-float64(j))/2
				}
			}
		}
	}

	for j := range equations[N] {
		equations[N][j] = float64(j) / 2
		equations[N+1][j] = float64(len(equations[N])-1-j) / 2
	}

	time := make([]float64, int(ts[len(ts)-1])+1)
	for i := range time {
		time[i] = 1 << 30
		for n := range equations {
			time[i] = min(time[i], equations[n][i])
		}
	}

	ans := 0.0
	for i := range time {
		if i != 0 {
			ans += float64(time[i-1]+time[i]) * 0.25
		}
	}
	fmt.Println(ans)
}
