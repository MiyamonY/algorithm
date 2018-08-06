///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:38:36 2018
//
package main

import (
	"fmt"
)

var h, m int

func main() {
	fmt.Scan(&h, &m)

	fmt.Println(18*60 - (h*60 + m))
}
