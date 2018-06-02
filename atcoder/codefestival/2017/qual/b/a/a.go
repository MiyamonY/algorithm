///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 14:32:53 2018
//
package main

import "fmt"

var S string

func main() {
	fmt.Scan(&S)
	fmt.Println(S[:len(S)-8])
}
