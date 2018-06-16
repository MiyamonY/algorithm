///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 11:56:53 2018
//
package main

import "fmt"

type node struct {
	parent   int
	children []int
	weight   int
}

var N, M int

type tree []node

var t tree

func dfs(r int) {
	for _, c := range t[r].children {
		dfs(c)
	}

	min := 1 << 30
	if len(t[r].children) > 0 && r != 0 {
		for _, c := range t[r].children {
			if t[c].weight < min {
				min = t[c].weight
			}
		}
		t[r].weight = min
		for _, c := range t[r].children {
			t[c].weight -= min
		}
	}
}

func main() {
	fmt.Scan(&N, &M)
	t = make(tree, N)

	t[0].parent = 0

	for i := 1; i <= N-1; i++ {
		var parent int
		fmt.Scan(&parent)
		t[i].parent = parent
		t[parent].children = append(t[parent].children, i)
	}

	for i := 0; i < M; i++ {
		var n, w int
		fmt.Scan(&n, &w)
		t[n].weight = w
	}

	dfs(0)

	ans := 0
	for i := 1; i < N; i++ {
		ans += t[i].weight
	}
	fmt.Println(ans)
}
