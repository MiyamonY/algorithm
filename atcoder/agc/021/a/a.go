///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Feb 24 21:00:50 2018
//
package main

import (
	"fmt"
)

func max(N string) bool {
	for i := 1; i < len(N); i++ {
		if N[i] != '9' {
			return false
		}
	}
	return true
}

func main() {
	var N string
	fmt.Scan(&N)

	count := 0
	if max(N) {
		for i := range N {
			count += int(N[i] - '0')
		}
		fmt.Println(count)
		return
	}

	if N[0] != '9' {
		count += int(N[0]-'1') + (len(N)-1)*9
		fmt.Println(count)
		return
	}

	prefix := true
	for i := range N {
		if N[i] == '9' {
			count += 9
		} else if prefix {
			count += 8
			prefix = false
		} else {
			count += 9
		}
	}
	fmt.Println(count)
}
