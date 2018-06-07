///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Jun  8 01:05:35 2018
//
package main

import "fmt"

var N, K int

func gcd(a, b int) int {
	if b > a {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	fmt.Scan(&N, &K)

	m := map[int]int{}
	for i := 0; i < N; i++ {
		var a int
		fmt.Scan(&a)
		m[gcd(a, K)]++
	}

	arr := make([]int, 0)
	for k := range m {
		arr = append(arr, k)
	}

	ans := 0
	for i := range arr {
		for j := i; j < len(arr); j++ {
			if arr[i]*arr[j]%K == 0 {
				if i == j {
					ans += m[arr[i]] * (m[arr[j]] - 1) / 2
				} else {
					ans += m[arr[i]] * m[arr[j]]
				}
			}
		}
	}

	fmt.Println(ans)
}
