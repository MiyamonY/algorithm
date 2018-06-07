///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Jun  8 00:02:13 2018
//
package main

import "fmt"

var N, L int
var a []int

func main() {
	fmt.Scan(&N, &L)
	a = make([]int, N)

	var valid bool
	var index int
	for i := range a {
		fmt.Scan(&a[i])

		if i-1 >= 0 && a[i-1]+a[i] >= L {
			valid = true
			index = i
		}
	}

	if valid {
		fmt.Println("Possible")
		for i := 1; i < index; i++ {
			fmt.Println(i)
		}
		for i := N - 1; i >= index; i-- {
			fmt.Println(i)
		}
	} else {
		fmt.Println("Impossible")
	}
}
