///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Feb 28 21:28:09 2018
//
package main

import (
	"fmt"
	"math"
)

type pos struct {
	x float64
	y float64
}

func (a pos) dist(b pos) float64 {
	dx := a.x - b.x
	dy := a.y - b.y
	return math.Sqrt(dx*dx + dy*dy)
}

func max(x, y float64) float64 {
	if x < y {
		return y
	} else {
		return x
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	arr := make([]pos, N)
	for i := range arr {
		fmt.Scan(&arr[i].x, &arr[i].y)
	}

	m := 0.0
	for i := range arr {
		for j := range arr {
			m = max(m, arr[i].dist(arr[j]))
		}
	}
	fmt.Println(m)
}
