///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr  2 21:09:46 2018
//
package main

import (
	"fmt"
)

var H, W int

func main() {
	fmt.Scan(&H, &W)

	var count int
	for i := 0; i < H; i++ {
		var s string
		fmt.Scan(&s)
		for j := range s {
			if s[j] == '#' {
				count++
			}
		}
	}

	if count == H+W-1 {
		fmt.Println("Possible")
	} else {
		fmt.Println("Impossible")
	}
}
