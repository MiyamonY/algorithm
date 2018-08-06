///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 14:36:05 2018
//
package main

import "fmt"

var N, A, B int
var S string

func main() {
	fmt.Scan(&N, &A, &B)
	fmt.Scan(&S)

	b := 1
	count := 0
	for _, s := range S {
		switch s {
		case 'a':
			if count < A+B {
				fmt.Println("Yes")
				count++
			} else {
				fmt.Println("No")
			}
		case 'b':
			if count < A+B && b <= B {
				fmt.Println("Yes")
				count++
				b++
			} else {
				fmt.Println("No")
			}
		case 'c':
			fmt.Println("No")
		}
	}
}
