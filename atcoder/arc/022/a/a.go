///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 10:55:04 2018
//
package main

import (
	"fmt"
	"strings"
)

var S string

func main() {
	fmt.Scan(&S)
	s := strings.ToUpper(S)

	const ICT string = "ICT"
	index := 0
	for i := range ICT {
		found := false
		for j := index; j < len(s); j++ {
			if ICT[i] == s[j] {
				index = j + 1
				found = true
				break
			}
		}
		if !found {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
