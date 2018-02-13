///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Feb 14 00:18:37 2018
//
package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S)

	for i := range S {
		if '0' <= S[i] && S[i] <= '9' {
			fmt.Print(string(S[i]))
			if i+1 < len(S) && '0' <= S[i+1] && S[i+1] <= '9' {
				fmt.Println(string(S[i+1]))
			} else {
				fmt.Println()
			}
			return
		}
	}
}
