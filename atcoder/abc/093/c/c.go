///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Apr  7 21:08:55 2018
//
package main

import (
	"fmt"
	"sort"
)

var nums []int

func main() {
	nums = make([]int, 3)
	fmt.Scan(&nums[0], &nums[1], &nums[2])
	sort.Ints(nums)

	count := 0
	count += nums[2] - nums[1]
	nums[0] += count

	if (nums[2]-nums[0])%2 == 1 {
		count++
		nums[2]++
	}
	count += (nums[2] - nums[0]) / 2

	fmt.Println(count)
}
