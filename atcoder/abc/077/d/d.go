///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Apr 14 19:24:32 2018
//
package main

import (
	"fmt"
)

var K int

type route struct {
	to     int
	weight int
}

type deque struct {
	q []int
}

func create_deque(cap int) deque {
	var q deque
	q.q = make([]int, 0, cap)
	return q
}

func (q *deque) push_back(a int) {
	q.q = append(q.q, a)
}

func (q *deque) push_front(a int) {
	q.q = append([]int{a}, q.q...)
}

func (q *deque) pop() int {
	ret := q.q[0]
	q.q = q.q[1:]
	return ret
}

func (q deque) empty() bool {
	return len(q.q) == 0
}

func bfs(graph [][]route) int {
	q := create_deque(len(graph))

	weights := make([]int, len(graph))
	for i := range weights {
		weights[i] = 1 << 30
	}

	q.push_front(1)
	weights[1] = 0
	for !q.empty() {
		from := q.pop()
		for _, r := range graph[from] {
			to := r.to
			weight := r.weight
			if weights[from]+weight < weights[to] {
				weights[to] = weights[from] + weight
				if weight == 0 {
					q.push_front(to)
				} else {
					q.push_back(to)
				}
			}
		}
	}

	return weights[0]
}

func main() {
	fmt.Scan(&K)

	graph := make([][]route, K+1)

	for i := 1; i <= K; i++ {
		graph[i] = append(graph[i], route{to: (i + 1) % K, weight: 1})
		graph[i] = append(graph[i], route{to: (10 * i) % K})
	}

	fmt.Println(bfs(graph) + 1)
}
