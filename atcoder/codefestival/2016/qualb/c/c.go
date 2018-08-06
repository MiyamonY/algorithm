///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jun 13 23:37:46 2018
//
package main

import (
	"fmt"
	"sort"
)

var W, H int64
var p, q []int

func main() {
	fmt.Scan(&W, &H)

	p = make([]int, W)
	q = make([]int, H)

	for i := range p {
		fmt.Scan(&p[i])
	}
	sort.Ints(p)

	for i := range q {
		fmt.Scan(&q[i])
	}
	sort.Ints(q)

	var h, w int64
	ans := int64(0)
	n := int64(W+1)*int64(H+1) - 1
	for n > 0 {
		if (h >= int64(len(q))) || (w < int64(len(p)) && p[w] < q[h]) {
			ans += int64(H+1-h) * int64(p[w])
			n -= H + 1 - h
			w++
		} else {
			ans += int64(W+1-w) * int64(q[h])
			n -= W + 1 - w
			h++
		}
	}

	fmt.Println(ans)
}
