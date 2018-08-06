///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May 26 22:02:28 2018
//
package main

import (
	"fmt"
)

var N int
var S string

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &S)
	ans := 0
	for i := 1; i < len(S)-2; i++ {
		s1 := S[:i]
		s2 := S[i:]
		m := map[uint8]bool{}
		for i := range s1 {
			m[s1[i]] = true
		}

		m2 := map[uint8]bool{}
		for i := range s2 {
			m2[s2[i]] = true
		}

		count := 0
		for k, _ := range m2 {
			if _, ok := m[k]; ok {
				count++
			}
		}
		ans = max(ans, count)
	}
	fmt.Println(ans)
}
