///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 22:59:58 2018
//
package main

import (
	"fmt"
	"strconv"
	"strings"
)

var A, B int

func conv_upper(a int, at int) int {
	s := strings.Split(strconv.Itoa(a), "")
	s[at] = "9"
	v, _ := strconv.Atoi(strings.Join(s, ""))
	return v
}

func conv_lower(a int, at int) int {
	s := strings.Split(strconv.Itoa(a), "")
	if at == 0 {
		s[at] = "1"
	} else {
		s[at] = "0"
	}
	v, _ := strconv.Atoi(strings.Join(s, ""))
	return v
}

func main() {
	fmt.Scan(&A, &B)

	m := -1 << 30
	m = max(m, conv_upper(A, 0)-B)
	m = max(m, conv_upper(A, 1)-B)
	m = max(m, conv_upper(A, 2)-B)
	m = max(m, A-conv_lower(B, 0))
	m = max(m, A-conv_lower(B, 1))
	m = max(m, A-conv_lower(B, 2))

	fmt.Println(m)
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
