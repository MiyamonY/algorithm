///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr  7 20:59:43 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)

	kind := make([]bool, 3)
	for i := range S {
		if int(S[i]-'a') > 2 || kind[int(S[i]-'a')] {
			fmt.Println("No")
			return
		}
		kind[int(S[i]-'a')] = true
	}

	fmt.Println("Yes")
}
