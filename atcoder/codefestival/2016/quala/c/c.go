///
// File:  c.go
// Author: ymiyamoto
//
// Created on Mon May 28 00:14:40 2018
//
package main

import (
	"fmt"
)

var s string
var k int

func count2a(c uint8) int {
	if c == 'a' {
		return 0
	}
	return int(26 - (c - 'a'))
}

func main() {
	_, _ = fmt.Scan(&s)
	_, _ = fmt.Scan(&k)

	for i := 0; i < len(s)-1; i++ {
		if count2a(s[i]) <= k {
			fmt.Print("a")
			k -= count2a(s[i])
		} else {
			fmt.Print(string(s[i]))
		}
	}

	if k > 0 {
		fmt.Print(string(uint8(((int(s[len(s)-1]) + k - int('a')) % 26) + 'a')))
	} else {
		fmt.Println(string(s[len(s)-1]))
	}

	fmt.Println()
}
