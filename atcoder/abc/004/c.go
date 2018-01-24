///
// File:  c.go
// Author: ymiyamoto
//
// Created on Wed Jan 24 21:31:29 2018
//
package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	rotate := (N / 5) % 6
	move := N % 5

	nums := []int{1, 2, 3, 4, 5, 6}
	for i := 0; i < rotate; i++ {
		nums = append(nums[1:], nums[0])
	}

	for i := 0; i < move; i++ {
		nums[i], nums[i+1] = nums[i+1], nums[i]
	}

	for _, n := range nums {
		fmt.Print(n)
	}
	fmt.Println()
}
