///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 17:26:23 2018
//
package main

import (
	"container/heap"
	"fmt"
)

type machine struct {
	next, span int64
}

var N, K int

type PQ []*machine

func (pq PQ) Len() int           { return len(pq) }
func (pq PQ) Less(i, j int) bool { return pq[i].next < pq[j].next }
func (pq PQ) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PQ) Push(x interface{}) {
	item := x.(*machine)
	*pq = append(*pq, item)
}
func (pq *PQ) Pop() interface{} {
	old, n := *pq, len(*pq)-1
	ret := old[n]
	*pq = old[0:n]
	return ret
}

func main() {
	fmt.Scan(&N, &K)

	pq := make(PQ, N)
	machines := make([]machine, N)
	for i := range machines {
		fmt.Scan(&machines[i].next, &machines[i].span)
		pq[i] = &machines[i]
	}
	heap.Init(&pq)

	time := int64(0)
	for i := 0; i < K; i++ {
		m := heap.Pop(&pq)
		time += m.(*machine).next
		m.(*machine).next += m.(*machine).span
		heap.Push(&pq, m)
	}

	fmt.Println(time)
}
