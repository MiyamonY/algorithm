///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 16:32:30 2018
//
package main

import (
	"fmt"
	"strings"
)

func main() {
	var W string

	fmt.Scan(&W)
	for _, char := range W {
		if !strings.Contains("aiueo", string(char)) {
			fmt.Print(string(char))
		}
	}
	fmt.Println()
}
