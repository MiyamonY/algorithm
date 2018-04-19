///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 19 23:19:48 2018
//
package main

import (
	"fmt"
)

var n, m, N int

func main() {
	fmt.Scan(&m, &n, &N)

	pencils := N
	rest := 0
	ans := 0
	for pencils > 0 {
		ans += pencils
		pencils, rest = ((pencils+rest)/m)*n, (pencils+rest)%m
	}

	fmt.Println(ans)
}
