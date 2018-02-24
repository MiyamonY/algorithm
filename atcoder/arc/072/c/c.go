///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Feb 24 20:05:30 2018
//
package main

import (
	"fmt"
)

func abs(a int) int {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	arr := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}

	Sn1 := 0
	Sn2 := 0
	count1 := 0
	count2 := 0
	for i := 0; i < N; i++ {
		if i%2 == 0 {
			if Sn1+arr[i] < 1 {
				count1 += abs(1 - arr[i] - Sn1)
				Sn1 = 1
			} else {
				Sn1 += arr[i]
			}

			if Sn2+arr[i] > -1 {
				count2 += abs(-1 - Sn2 - arr[i])
				Sn2 = -1
			} else {
				Sn2 += arr[i]
			}
		} else {
			if Sn1+arr[i] > -1 {
				count1 += abs(-1 - Sn1 - arr[i])
				Sn1 = -1
			} else {
				Sn1 += arr[i]
			}

			if Sn2+arr[i] < 1 {
				count2 += abs(1 - arr[i] - Sn2)
				Sn2 = 1
			} else {
				Sn2 += arr[i]
			}
		}
	}

	if count1 < count2 {
		fmt.Println(count1)
	} else {
		fmt.Println(count2)
	}
}
