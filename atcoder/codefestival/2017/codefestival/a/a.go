///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 18:44:31 2018
//
package main

import (
	"fmt"
	"sort"
)

func main() {
	a := make([]int, 8)
	for i := range a {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)
	fmt.Println(a[len(a)-1])
}
