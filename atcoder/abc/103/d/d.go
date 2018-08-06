// Package main provides
//
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Aug  4 05:07:15 2018
//
package main

import (
	"fmt"
	"sort"
)

type pair struct {
	a, b int
}

type pairs []pair

func (p pairs) Len() int {
	return len(p)
}

func (p pairs) Less(i, j int) bool {
	return p[i].b < p[j].b
}

func (p pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

var N, M int
var ps pairs

func main() {
	fmt.Scan(&N, &M)
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		ps = append(ps, pair{a, b})
	}

	sort.Sort(ps)

	x := 0
	count := 0
	for i := range ps {
		if ps[i].a > x {
			count++
			x = ps[i].b - 1
		}
	}
	fmt.Println(count)
}
