///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Jun 14 23:23:31 2018
//
package main

import (
	"fmt"
	"sort"
)

const MOD int = 1e9 + 7

var N int
var a, b []int

func main() {
	fmt.Scan(&N)
	a = make([]int, N)
	b = make([]int, N)
	for i := range a {
		fmt.Scan(&a[i])
	}
	for i := range b {
		fmt.Scan(&b[i])
	}
	sort.Ints(a)
	sort.Ints(b)

	ans := 1
	seta := make([]int, 0)
	setb := make([]int, 0)
	indexa := 0
	indexb := 0
	for i := 0; i < 2*N; i++ {
		if indexb >= len(b) || (indexa < len(a) && a[indexa] < b[indexb]) {
			if len(setb) > 0 {
				ans *= len(setb)
				ans %= MOD
				setb = setb[1:]
			} else {
				seta = append(seta, a[indexa])
			}
			indexa++
		} else {
			if len(seta) > 0 {
				ans *= len(seta)
				ans %= MOD
				seta = seta[1:]
			} else {
				setb = append(setb, b[indexb])
			}
			indexb++
		}
	}
	fmt.Println(ans)
}
