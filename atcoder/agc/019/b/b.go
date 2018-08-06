///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 23:44:53 2018
//
package main

import "fmt"

var A string

func main() {
	fmt.Scan(&A)
	m := map[uint8]int64{}
	for i := range A {
		m[A[i]]++
	}

	num := int64(len(A)) * int64(len(A)-1) / 2
	for _, v := range m {
		num -= v * (v - 1) / 2
	}

	fmt.Println(num + 1)
}
