///
// File:  c.go
// Author: ymiyamoto
//
// Created on Thu Feb  1 21:42:30 2018
//
package main

import (
	"fmt"
)

type town struct {
	from int
	to   int
}

func main() {
	var N, D, K int
	fmt.Scan(&N, &D, &K)

	towns := make([]town, D)
	for i := 0; i < D; i++ {
		t := town{}
		fmt.Scan(&t.from, &t.to)
		towns[i] = t
	}

	for i := 0; i < K; i++ {
		var S, T int
		fmt.Scan(&S, &T)

		pos := S
		for j := range towns {
			if S < T {
				if towns[j].from <= pos && pos <= towns[j].to {
					pos = towns[j].to
				}
				if T <= pos {
					fmt.Println(j + 1)
					break
				}
			} else {
				if towns[j].from <= pos && pos <= towns[j].to {
					pos = towns[j].from
				}
				if pos <= T {
					fmt.Println(j + 1)
					break
				}
			}
		}
	}
}
