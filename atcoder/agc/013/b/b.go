///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed Jun  6 18:50:20 2018
//
package main

import "fmt"

var N, M int

var graph [][]int
var path []int
var visited []bool

func remove(v, w int) {
	for i, x := range graph[v] {
		if w == x {
			graph[v] = append(graph[v][:i], graph[v][i+1:]...)
		}
	}
}

func reverse(path []int) {
	for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
		path[i], path[j] = path[j], path[i]
	}
}

func extend() {
	for {
		edge := path[len(path)-1]
		appended := false
		for _, n := range graph[edge] {
			if !visited[n] {
				visited[n] = true
				path = append(path, n)
				remove(edge, n)
				remove(n, edge)
				appended = true
				break
			}
		}

		if !appended {
			return
		}
	}
}

func main() {
	fmt.Scan(&N, &M)

	graph = make([][]int, N+1)
	for i := range graph {
		graph[i] = make([]int, 0)
	}

	for i := 0; i < M; i++ {
		var A, B int
		fmt.Scan(&A, &B)
		graph[A] = append(graph[A], B)
		graph[B] = append(graph[B], A)
	}

	next := graph[1][0]
	path = []int{1, next}
	visited = make([]bool, N+1)
	visited[1], visited[next] = true, true

	extend()
	reverse(path)
	extend()

	fmt.Println(len(path))
	for i, v := range path {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}
