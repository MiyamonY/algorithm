///
// File:  0546.go
// Author: ymiyamoto
//
// Created on Tue Mar  6 23:19:41 2018
//
package main

import (
	"fmt"
)

var n, k int

func perm(arr []int) [][]int {
	if len(arr) == 1 {
		return [][]int{arr}
	}

	p := perm(arr[1:])
	var ret [][]int
	for _, val := range p {
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

func permutation(n, k int) [][]int {
	ret := [][]int{}

	for i := 0; i < 1<<uint(n); i++ {
		var selects []int
		for j := 0; j < n; j++ {
			if (i>>uint(j))&1 == 1 {
				selects = append(selects, j)
			}
		}
		if len(selects) == k {
			ret = append(ret, perm(selects)...)
		}
	}

	return ret
}

func main() {
	for {
		fmt.Scan(&n, &k)
		if n == 0 && k == 0 {
			break
		}

		cards := make([]string, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&cards[i])
		}

		ret := permutation(len(cards), k)
		nums := map[string]bool{}
		for _, val := range ret {
			var num string
			for i := 0; i < len(val); i++ {
				num += cards[val[i]]
			}
			nums[num] = true
		}

		fmt.Println(len(nums))
	}
}
