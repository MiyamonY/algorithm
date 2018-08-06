///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Jun  1 21:57:47 2018
//
package main

import (
	"fmt"
	"strings"
)

var s string

func isPalidrome(s string) bool {
	for i := range s {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Scan(&s)

	t := strings.Replace(s, "x", "", -1)
	if !isPalidrome(t) {
		fmt.Println(-1)
		return
	}
	ans := 0
	left := 0
	right := len(s) - 1
	for left < len(s) || 0 <= right {
		if left < len(s) && 0 <= right && s[left] == s[right] {
			left++
			right--
		} else if left < len(s) && s[left] == 'x' {
			ans++
			left++
		} else if 0 <= right && s[right] == 'x' {
			ans++
			right--
		}
	}

	fmt.Println(ans / 2)
}
