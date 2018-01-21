///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 15:52:41 2018
//
package main

import "fmt"

func main() {
	board := make([][]string, 4)
	for i := 0; i < 4; i++ {
		board[i] = make([]string, 4)
	}

	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			fmt.Scan(&board[i][j])
		}
	}

	for i := 3; i > -1; i-- {
		for j := 3; j > -1; j-- {
			if j != 3 {
				fmt.Print(" ")
			}
			fmt.Print(board[i][j])
		}
		fmt.Println()
	}
}
