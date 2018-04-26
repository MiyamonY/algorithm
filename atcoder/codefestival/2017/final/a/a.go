///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 25 08:34:24 2018
//
package main

import (
	"fmt"
	"strings"
)

var S string

func main() {
	fmt.Scan(&S)

	for i := 0; i < 1<<4; i++ {
		str := []string{""}
		if i&(1<<0) != 0 {
			str = append(str, "A")
		}
		str = append(str, "KIH")
		if i&(1<<1) != 0 {
			str = append(str, "A")

		}
		str = append(str, "B")
		if i&(1<<2) != 0 {
			str = append(str, "A")

		}
		str = append(str, "R")
		if i&(1<<3) != 0 {
			str = append(str, "A")
		}
		if strings.Join(str, "") == S {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}
