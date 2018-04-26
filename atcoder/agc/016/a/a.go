///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 10:52:34 2018
//
package main

import (
	"fmt"
	"strings"
)

var s string

func check(s []string) bool {
	for i := 0; i < len(s)-1; i++ {
		if s[i] != s[i+1] {
			return false
		}
	}
	return true
}

func shrink(c string, s []string) []string {
	ret := []string{}
	for i := 0; i < len(s)-1; i++ {
		if s[i] == c || s[i+1] == c {
			ret = append(ret, c)
		} else {
			ret = append(ret, s[i])
		}
	}

	return ret
}

func main() {
	fmt.Scan(&s)

	ss := strings.Split(s, "")
	if check(ss) {
		fmt.Println(0)
		return
	}

	min := 1 << 30
	for i := 'a'; i <= 'z'; i++ {
		ss := strings.Split(s, "")
		for j := 1; j <= len(ss); j++ {
			ss = shrink(string(i), ss)
			if check(ss) {
				if j < min {
					min = j
				}
				break
			}

		}
	}

	fmt.Println(min)
}
