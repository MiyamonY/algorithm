///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Jun 10 21:01:20 2018
//
package main

import "fmt"

var s int

func main() {
	fmt.Scan(&s)
	if s < 1000 {
		fmt.Println("ABC")
	} else {
		fmt.Println("ABD")
	}

}
