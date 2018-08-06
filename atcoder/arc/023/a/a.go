///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 10:50:41 2018
//
package main

import (
	"fmt"
)

var y, m, d int

func days(y, m, d int) int {
	return 365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429
}

func main() {
	fmt.Scan(&y, &m, &d)
	if m == 1 || m == 2 {
		fmt.Println(days(2014, 5, 17) - days(y-1, m+12, d))
	} else {
		fmt.Println(days(2014, 5, 17) - days(y, m, d))
	}
}
