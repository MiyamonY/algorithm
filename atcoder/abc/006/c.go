///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jan 24 22:05:57 2018
//
package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	for y := 0; y < N; y++ {
		num := N - y
		foots := M - 3*y
		if foots-2*num < 0 || (foots-2*num)%2 != 0 {
			continue
		}
		z := (foots - 2*num) / 2
		x := num - z
		if x < 0 {
			continue
		}
		fmt.Println(x, y, z)
		return
	}

	fmt.Println(-1, -1, -1)
}
