///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 19:48:48 2018
//
package main

import (
	"fmt"
	"sort"
)

var N, M int

var arr []int

type pair struct {
	v, pri int
}

type PrioritySort []pair

func (p PrioritySort) Len() int {
	return len(p)
}
func (p PrioritySort) Less(i, j int) bool {
	return p[i].pri > p[j].pri
}
func (p PrioritySort) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func main() {
	fmt.Scan(&N, &M)

	arr := make([]int, N)
	for i := range arr {
		arr[i] = N - 1 - i
	}

	index := N
	for i := 0; i < M; i++ {
		var a int
		fmt.Scan(&a)
		arr[a-1] = index
		index++
	}

	p := make(PrioritySort, N)
	for v, pri := range arr {
		p[v] = pair{v: v, pri: pri}
	}
	sort.Sort(p)

	for i := range p {
		fmt.Println(p[i].v + 1)
	}
}
