///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Mar 24 02:14:06 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int

type point struct {
	x, y int
}

func (p point) isLessThan(q point) bool {
	if p.x < q.x && p.y < q.y {
		return true
	}
	return false
}

type points []point

type reds struct {
	points
}

func (p reds) Len() int {
	return len(p.points)
}

func (p reds) Swap(i, j int) {
	p.points[i], p.points[j] = p.points[j], p.points[i]
}

func (p reds) Less(i, j int) bool {
	return p.points[j].y < p.points[i].y
}

type blues struct {
	points
}

func (p blues) Len() int {
	return len(p.points)
}

func (p blues) Swap(i, j int) {
	p.points[i], p.points[j] = p.points[j], p.points[i]
}

func (p blues) Less(i, j int) bool {
	return p.points[i].x < p.points[j].x
}

func main() {
	fmt.Scan(&N)

	ps := make(points, N)
	for i := range ps {
		fmt.Scan(&ps[i].x, &ps[i].y)
	}
	reds := reds{ps}
	sort.Sort(reds)

	ps = make(points, N)
	for i := range ps {
		fmt.Scan(&ps[i].x, &ps[i].y)
	}
	blues := blues{ps}
	sort.Sort(blues)

	count := 0
	pairs := make([]bool, N)
	for _, r := range reds.points {
		for i, b := range blues.points {
			if !pairs[i] && r.isLessThan(b) {
				count++
				pairs[i] = true
				break
			}
		}
	}

	fmt.Println(count)
}
