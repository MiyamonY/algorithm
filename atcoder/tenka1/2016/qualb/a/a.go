///
// File:  b.go
// Author: ymiyamoto
//
// Created on Mon Jun 18 17:16:03 2018
//
package main

import (
	"fmt"
	"math"
)

func f(n float64) float64 {
	return math.Floor((n*n + 4.0) / 8.0)
}

func main() {
	fmt.Println(f(f(f(20))))
}
