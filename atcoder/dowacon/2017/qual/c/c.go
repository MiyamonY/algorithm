///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 13:02:27 2018
//
package main

import "fmt"

var N int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N)

	m := [5]int{}
	for i := 0; i < N; i++ {
		var n int
		fmt.Scan(&n)
		m[n]++
	}

	ans := 0
	ans += m[4]
	ans += m[3]
	m[1] = max(0, m[1]-m[3])
	ans += m[2] / 2
	if m[2]%2 == 1 {
		m[1] = max(0, m[1]-2)
		ans++
	}
	ans += m[1] / 4
	if m[1]%4 > 0 {
		ans++
	}
	fmt.Println(ans)
}
