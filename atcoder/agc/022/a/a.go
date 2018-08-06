///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 21:15:23 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)

	exists := make([]bool, 26)
	if len(S) == 26 {
		for index := 25; index >= 0; index-- {
			last := S[index]
			for c := last + 1; c <= 'z'; c++ {
				used := false
				for j := index; j >= 0; j-- {
					if c == S[j] {
						used = true
					}
				}
				if !used {
					fmt.Println(S[:index] + string(c))
					return
				}
			}
		}
		fmt.Println(-1)
	} else {
		for i := range S {
			exists[S[i]-'a'] = true
		}
		fmt.Print(S)
		for i, e := range exists {
			if !e {
				fmt.Println(string('a' + i))
				return
			}
		}
	}
}
