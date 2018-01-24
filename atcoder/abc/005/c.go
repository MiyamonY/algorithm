///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jan 24 21:45:11 2018
//
package main

import (
	"fmt"
)

func main() {
	var T int
	fmt.Scan(&T)

	var N, M int
	fmt.Scan(&N)
	times := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&times[i])
	}

	fmt.Scan(&M)
	persons := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&persons[i])
	}

	for len(persons) > 0 {
		p := persons[0]
		found := false
		for len(times) > 0 {
			t := times[0]
			times = times[1:]
			if t <= p && p-t <= T {
				found = true
				break
			}
		}

		if !found {
			fmt.Println("no")
			return
		}

		persons = persons[1:]
	}

	fmt.Println("yes")
}
