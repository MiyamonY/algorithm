///
// File:  c.go
// Author: ymiyamoto
//
// Created on Thu Feb 15 21:48:37 2018
//
package main

import (
	"fmt"
)

type point_t struct {
	r int
	c int
}

func main() {
	var R, C, K, N int
	fmt.Scan(&R, &C, &K, &N)

	rs := make([]int, R)
	cs := make([]int, C)
	points := make([]point_t, N)
	for i := 0; i < N; i++ {
		var r, c int
		fmt.Scan(&r, &c)
		r--
		c--
		points[i] = point_t{r: r, c: c}
		rs[r]++
		cs[c]++
	}

	rcount := map[int]int{}
	for i := range rs {
		rcount[rs[i]]++
	}

	ccount := map[int]int{}
	for i := range cs {
		ccount[cs[i]]++
	}

	count := 0
	for k, v := range rcount {
		count += ccount[K-k] * v
	}

	for _, p := range points {
		if rs[p.r]+cs[p.c] == K {
			count--
		} else if rs[p.r]+cs[p.c] == K+1 {
			count++
		}
	}

	fmt.Println(count)
}
