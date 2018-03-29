///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Mar 28 21:40:07 2018
//
package main

import (
	"fmt"
)

var X string

func main() {
	fmt.Scan(&X)

	count := 0
	ss := 0
	for i := range X {
		if X[i] == 'S' {
			ss++
		} else {
			if ss > 0 {
				ss--
			} else {
				count++
			}
		}
	}

	ts := 0
	for i := range X {
		if X[len(X)-1-i] == 'T' {
			ts++
		} else {
			if ts > 0 {
				ts--
			} else {
				count++
			}
		}
	}
	fmt.Println(count)
}
