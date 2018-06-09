///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 00:27:55 2018
//
package main

import "fmt"

var N int

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Scan(&N)

	var sleft, sright string

	left := 0
	right := N - 1
	fmt.Println(left)
	fmt.Scan(&sleft)
	if sleft == "Vacant" {
		return
	}
	fmt.Println(right)
	fmt.Scan(&sright)
	if sright == "Vacant" {
		return
	}

	for {
		mid := (left + right) / 2
		fmt.Println(mid)
		var s string
		fmt.Scan(&s)
		if s == "Vacant" {
			return
		}
		if (abs(mid-left)%2 == 0 && sleft != s) || (abs(mid-left)%2 == 1 && sleft == s) {
			right = mid
			sright = s
		} else {
			left = mid
			sleft = s
		}
	}
}
