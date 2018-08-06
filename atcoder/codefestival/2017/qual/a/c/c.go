///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed May 30 22:17:54 2018
//
package main

import "fmt"

var H, W int

func main() {
	fmt.Scan(&H, &W)

	m := map[uint8]int{}
	for i := 0; i < H; i++ {
		var s string
		fmt.Scan(&s)
		for j := range s {
			m[s[j]]++
		}
	}

	counts := make([]int, 0)
	for _, v := range m {
		counts = append(counts, v)
	}

	var g4, g2, g1 int
	g4 = (H / 2) * (W / 2)
	if H%2 == 1 {
		g2 += W / 2
	}
	if W%2 == 1 {
		g2 += H / 2
	}
	if H%2 == 1 && W == 1 {
		g1 = 1
	}

	// fmt.Println(counts)
	// fmt.Println(g4, g2, g1)
	for g4 > 0 {
		var found bool
		for i := range counts {
			if counts[i] >= 4 {
				counts[i] -= 4
				g4--
				found = true
			}
		}
		if !found {
			fmt.Println("No")
			return
		}
	}

	for g2 > 0 {
		var found bool
		for i := range counts {
			if counts[i] >= 2 {
				counts[i] -= 2
				g2--
				found = true
			}
		}
		if !found {
			fmt.Println("No")
			return
		}
	}

	for g1 > 0 {
		var found bool
		for i := range counts {
			if counts[i] >= 1 {
				counts[i]--
				g1--
				found = true
			}
		}
		if !found {
			fmt.Println("No")
			return
		}

	}
	fmt.Println("Yes")
}
