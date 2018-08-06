///
// File:  d.go
// Author: ymiyamoto
//
// Created on Tue May 15 23:23:20 2018
//
package main

import (
	"fmt"
)

type tree []int

func root(v int) int {
	if seg_tree[v] == v {
		return v
	} else {
		seg_tree[v] = root(seg_tree[v])
		return seg_tree[v]
	}
}

func unite(v, w int) {
	x := root(v)
	y := root(w)
	if x == y {
		return
	}
	seg_tree[x] = y
}

type set map[int]struct{}

func (s set) intersection(s1 set) set {
	s2 := set{}

	for k, _ := range s {
		if _, ok := s1[k]; ok {
			s2[k] = struct{}{}
		}
	}

	return s2
}

var N, M int
var p []int
var seg_tree tree
var rank tree

func main() {
	fmt.Scan(&N, &M)

	p = make([]int, N+1)
	for i := 1; i < len(p); i++ {
		fmt.Scan(&p[i])
	}

	seg_tree = make(tree, N+1)
	rank = make(tree, N+1)
	for i := 1; i < len(seg_tree); i++ {
		seg_tree[i] = i
		rank[i] = 0
	}

	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		unite(x, y)
	}

	m := map[int]set{}
	m2 := map[int]set{}
	for i := 1; i < len(seg_tree); i++ {
		n := root(seg_tree[i])
		if _, ok := m[n]; !ok {
			m[n] = set{}
			m2[n] = set{}
		}
		m[n][i] = struct{}{}
		m2[n][p[i]] = struct{}{}
	}

	count := 0
	for k, v := range m {
		count += len(v.intersection(m2[k]))
	}
	fmt.Println(count)
}
