///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 16:06:39 2018
//
package main

import (
	"fmt"
	"strings"
)

func main() {
	var S, T string
	fmt.Scan(&S, &T)

	for i := 0; i < len(S); i++ {
		if S[i] == '@' {
			if !strings.Contains("atcoder@", string(T[i])) {
				fmt.Println("You will lose")
				return
			}
		} else if T[i] == '@' {
			if !strings.Contains("atcoder@", string(S[i])) {
				fmt.Println("You will lose")
				return
			}
		} else if S[i] != T[i] {
			fmt.Println("You will lose")
			return
		}
	}

	fmt.Println("You can win")
}
