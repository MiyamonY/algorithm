///
// File:  c.go
// Author: ymiyamoto
//
// Created on Thu Jan 25 21:53:15 2018
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

func (p pos) Distance(q pos) float64 {
	dx := p.x - q.x
	dy := p.y - q.y
	return math.Sqrt(dx*dx + dy*dy)
}

const PREC = 10e-6

func main() {
	var a, b pos
	fmt.Scan(&a.x, &a.y, &b.x, &b.y)

	var T, V float64
	fmt.Scan(&T, &V)

	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var p pos
		fmt.Scan(&p.x, &p.y)

		if p.Distance(a)+p.Distance(b) <= T*V+PREC {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
}
