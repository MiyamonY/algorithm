///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 14:32:33 2018
//
package main

import "fmt"
import "sort"

func main(){
	var N int
	fmt.Scan(&N)

	As := make([]int, N)
	for i:= 0; i < N; i++{
		fmt.Scan(&As[i])
	}
	sort.Ints(As)

	for i:= N -1;i >= 0;i--{
		if 	first := As[N -1]; first != As[i]{
			fmt.Println(As[i])
			return
		}
	}
}
