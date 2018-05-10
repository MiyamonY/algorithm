///
// File:  b.go
// Author: ymiyamoto
//
// Created on Thu May 10 21:12:14 2018
//
package main

import (
	"fmt"
)

type pair struct {
	x, y int
}

var H, W, N int
var arr []pair

func main() {
	fmt.Scan(&H, &W, &N)

	arr = make([]pair, N)
	count := int64((H-1)*W + H*(W-1))
	for i := range arr {
		var x, y int
		fmt.Scan(&x, &y)
		if H == 1 {
			if y == 1 || y == W {
				count -= 1
			} else {
				count -= 2
			}
		} else if W == 1 {
			if x == 1 || x == H {
				count -= 1
			} else {
				count -= 2
			}
		} else {
			if (x == 1 && y == 1) || (x == 1 && y == W) || (x == H && y == 1) || (x == H && y == W) {
				count -= 2
			} else if x == 1 || x == H || y == 1 || y == W {
				count -= 3
			} else {
				count -= 4
			}
			arr[i].x = x
			arr[i].y = y

		}
	}

	for i := range arr {
		x := arr[i].x
		y := arr[i].y

		for j := range arr {
			if ((arr[j].x == x+1) && arr[j].y == y) || (arr[j].x == x && (arr[j].y == y+1)) {
				count += 1
			}
		}
	}
	if count > 0 {
		fmt.Println(count)
	} else {
		fmt.Println(0)
	}
}
