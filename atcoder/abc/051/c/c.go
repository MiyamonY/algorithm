///
// File:  c.go
// Author: ymiyamoto
//
// Created on Tue Apr  3 00:47:31 2018
//
package main

import (
	"fmt"
)

func main() {
	var sx, sy, tx, ty int
	fmt.Scan(&sx, &sy, &tx, &ty)

	for i := 0; i < tx-sx; i++ {
		fmt.Print("R")
	}
	for i := 0; i < ty-sy; i++ {
		fmt.Print("U")
	}
	for i := 0; i < tx-sx; i++ {
		fmt.Print("L")
	}
	for i := 0; i < ty-sy; i++ {
		fmt.Print("D")
	}
	fmt.Print("D")
	for i := 0; i < tx-sx+1; i++ {
		fmt.Print("R")
	}
	for i := 0; i < ty-sy+1; i++ {
		fmt.Print("U")
	}
	fmt.Print("L")

	fmt.Print("U")
	for i := 0; i < tx-sx+1; i++ {
		fmt.Print("L")
	}
	for i := 0; i < ty-sy+1; i++ {
		fmt.Print("D")
	}
	fmt.Print("R")
	fmt.Println()
}
