///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Mar  7 22:23:32 2018
//
package main

import (
	"fmt"
)

var n int

func main() {
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		count := 0
		for j := 0; j < len(s); {
			if j+len("kyoto") <= len(s) && s[j:j+len("kyoto")] == "kyoto" {
				j += len("kyoto")
				count++
			} else if j+len("tokyo") <= len(s) && s[j:j+len("tokyo")] == "tokyo" {
				j += len("tokyo")
				count++
			} else {
				j++
			}
		}
		fmt.Println(count)
	}
}
