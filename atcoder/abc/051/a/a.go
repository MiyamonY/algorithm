///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Apr  3 00:41:46 2018
//
package main

import (
	"fmt"
	"strings"
)

var s string

func main() {
	fmt.Scan(&s)

	fmt.Println(strings.Join(strings.Split(s, ","), " "))
}
