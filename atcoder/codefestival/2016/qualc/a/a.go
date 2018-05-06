///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun May  6 11:39:16 2018
//
package main

import (
	"fmt"
)

var s string

func main() {
	fmt.Scan(&s)

	found := false
	for i := range s {
		if s[i] == 'C' {
			found = true
		}
		if found && s[i] == 'F' {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}
