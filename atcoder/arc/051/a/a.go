package main

import (
	"fmt"
	"math"
)

func in(x1, y1, x2, y2, r float64) bool {
	d1 := x1 - x2
	d2 := y1 - y2
	return math.Sqrt(d1*d1+d2*d2) <= r
}

func main() {
	var x1, y1, r float64
	fmt.Scan(&x1, &y1, &r)

	var x2, y2, x3, y3 float64
	fmt.Scan(&x2, &y2, &x3, &y3)

	if x1+r <= x2 || x3 <= x1-r || y1+r <= y2 || y3 <= y1-r {
		fmt.Println("YES")
		fmt.Println("YES")
	} else {
		if x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3 {
			fmt.Println("NO")
			fmt.Println("YES")
		} else if in(x1, y1, x2, y2, r) && in(x1, y1, x2, y3, r) && in(x1, y1, x3, y2, r) && in(x1, y1, x3, y3, r) {
			fmt.Println("YES")
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
			fmt.Println("YES")
		}
	}

}
