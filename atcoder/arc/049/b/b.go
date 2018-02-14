///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed Feb 14 21:12:17 2018
//
package main

import (
	"fmt"
	"math"
)

type pos_t struct {
	x float64
	y float64
	c float64
}

func max(a, b float64) float64 {
	if a < b {
		return b
	} else {
		return a
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	poss := make([]pos_t, N)
	for i := range poss {
		fmt.Scan(&poss[i].x, &poss[i].y, &poss[i].c)
	}

	left := 0.0
	right := 1e9
	for (right - left) > 1e-5 {
		mid := (left + right) / 2

		valid := true
		for j := range poss {
			for k := range poss {
				if max(math.Abs(poss[j].x-poss[k].x), math.Abs(poss[j].y-poss[k].y)) > (1/poss[j].c+1/poss[k].c)*mid {
					valid = false
					goto invalid
				}
			}
		}

	invalid:
		if valid {
			right = mid
		} else {
			left = mid
		}
	}

	fmt.Printf("%.010f", left)
}
