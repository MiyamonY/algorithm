///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 21:02:52 2018
//
package main

import (
	"fmt"
)

const names string = "MARCH"

var N int

func main() {
	fmt.Scan(&N)

	m := map[uint8]int{}
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		m[s[0]]++
	}

	patterns := 0
	for i := 0; i < (1 << uint(len(names))); i++ {
		count := 0
		pattern := 1
		for j := 0; j < len(names); j++ {
			if (i & (1 << uint(j))) != 0 {
				count++
				pattern *= m[names[j]]
			}
		}

		if count == 3 {
			patterns += pattern
		}
	}

	fmt.Println(patterns)
}
