///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr  8 17:50:48 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int
var s string

func main() {
	fmt.Scan(&N)
	fmt.Scan(&s)

	points := make([]int, 4)
	for i := range s {
		points[int(s[i]-'1')]++
	}
	sort.Ints(points)

	fmt.Println(points[len(points)-1], points[0])
}
