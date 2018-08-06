///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 18:51:32 2018
//
package main

import (
	"fmt"
	"strings"
)

var N int64
var S string

func main() {
	fmt.Scan(&N, &S)

	alla := true
	for i := range S {
		if S[i] == 'B' {
			alla = false
		}
	}

	if alla {
		n := int64(len(S))
		fmt.Println(N * n * (N*n + 1) / 2)
		return
	}

	t := strings.Split(S, "B")
	var ans int64
	for i := range t {
		n := int64(len(t[i]))
		ans += n * (n + 1) / 2
	}

	var aux int64
	if S[0] == 'A' && S[len(S)-1] == 'A' {
		n, m := int64(len(t[0])), int64(len(t[len(t)-1]))
		aux = (n+m)*(n+m+1)/2 - n*(n+1)/2 - m*(m+1)/2
	}
	fmt.Println(N*ans + (N-1)*aux)
}
