///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Mar 25 19:32:13 2018
//
package main

import (
	"fmt"
	"strconv"
)

var A, B int

func is_palidrome(str string) bool {
	for i := range str {
		if str[i] != str[len(str)-1-i] {
			return false
		}
	}
	return true
}
func main() {
	fmt.Scan(&A, &B)

	count := 0
	for i := A; i <= B; i++ {
		str := strconv.Itoa(i)
		if is_palidrome(str) {
			count++
		}
	}
	fmt.Println(count)
}
