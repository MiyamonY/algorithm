///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 13:04:24 2018
//
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var total = 0
	for i := 0; i < n; i++ {
		var a int
		switch fmt.Scan(&a); a{
		case 2:
			total++
		case 4:
			total++
		case 8:
			total++
		case 5:
			total += 2
		case 6:
			total += 3
		}
	}

	fmt.Println(total)
}
