package main

import (
	"fmt"
)

var X, Y int64

func main() {
	fmt.Scan(&X, &Y)
	cur := X
	for i := int64(1); ; i++ {
		cur *= 2
		if Y < cur {
			fmt.Println(i)
			break
		}
	}
}
