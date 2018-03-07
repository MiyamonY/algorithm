///
// File:  133.go
// Author: ymiyamoto
//
// Created on Tue Mar  6 23:44:21 2018
//
package main

import (
	"fmt"
)

var N int

func perm(arr []int) [][]int {
	if len(arr) == 1 {
		return [][]int{arr}
	}

	per := perm(arr[1:])

	var ret [][]int
	for _, val := range per {
		for i := 0; i <= len(val); i++ {
			tmp := make([]int, len(val))
			copy(tmp, val)
			tmp = append(tmp, 0)
			copy(tmp[i+1:], tmp[i:])
			tmp[i] = arr[0]
			ret = append(ret, tmp)
		}
	}

	return ret
}

func main() {
	fmt.Scan(&N)

	A := make([]int, N)
	B := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < N; i++ {
		fmt.Scan(&B[i])
	}

	permA := perm(A)
	permB := perm(B)

	var winA, winB int
	for i := 0; i < len(permA); i++ {
		for j := 0; j < len(permB); j++ {
			var a, b int

			for k := 0; k < len(permA[i]); k++ {
				if permA[i][k] > permB[j][k] {
					a++
				} else {
					b++
				}
			}

			if a > b {
				winA++
			} else {
				winB++
			}
		}
	}

	fmt.Println(float64(winA) / float64(winA+winB))
}
