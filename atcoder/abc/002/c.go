///
// File:  c.go
// Author: ymiyamoto
//
// Created on Tue Jan 23 01:19:53 2018
//
package main

import "fmt"
import "math"

func main() {
	var xa, ya, xb, yb, xc, yc float64
	fmt.Scan(&xa, &ya, &xb, &yb, &xc, &yc)
	fmt.Printf("%.5f\n", math.Abs((xb-xa)*(yc-ya)-(yb-ya)*(xc-xa))/2)
}
