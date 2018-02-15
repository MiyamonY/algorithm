///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Feb 15 20:57:03 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	var start bool
	for _, token := range strings.Split(s.Text(), " ") {
		if start {
			fmt.Print(" ")
		}
		switch token {
		case "Left":
			fmt.Print("<")
		case "Right":
			fmt.Print(">")
		case "AtCoder":
			fmt.Print("A")
		}
		start = true
	}
	fmt.Println()
}
