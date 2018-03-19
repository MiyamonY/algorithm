package main

import (
	"fmt"
	"sort"
)

var n int

func main() {
	fmt.Scan(&n)

	var arr []int
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		arr = append(arr, a)
	}

	var lis []int
	lis = append(lis, arr[0])
	for i := 1; i < len(arr); i++ {
		if val, last := arr[i], lis[len(lis)-1]; val == last {
		} else if last < val {
			lis = append(lis, val)
		} else {
			f := func(j int) bool {
				return val < lis[j]
			}
			index := sort.Search(len(lis), f)
			if index == 0 || lis[index-1] != val {
				lis[index] = val
			}
		}
	}
	fmt.Println(len(lis))
}
