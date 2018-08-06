///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 23:24:48 2018
//
package main

import (
	"fmt"
	"sort"
)

var N, M int

type cake struct {
	x, y, z int
}

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &M)
	arr := make([]cake, N)
	for i := range arr {
		fmt.Scan(&arr[i].x, &arr[i].y, &arr[i].z)
	}

	var ans int64
	for i := 0; i < (1 << 4); i++ {
		s := [3]int{1, 1, 1}
		for j := uint8(0); j < 3; j++ {
			if i&(1<<j) != 0 {
				s[j] = -1
			}
		}

		a := make([]int, N)
		for j, c := range arr {

			a[j] = s[0]*c.x + s[1]*c.y + s[2]*c.z
		}
		sort.Ints(a)

		var count int64
		for i := 0; i < M; i++ {
			count += int64(a[len(a)-1-i])
		}
		ans = max(ans, count)
	}
	fmt.Println(ans)
}
