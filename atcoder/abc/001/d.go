///
// File:  d.go
// Author: ymiyamoto
//
// Created on Mon Jan 22 23:14:07 2018
//
package main

import "fmt"
import "strconv"

func main() {
	var N int
	fmt.Scan(&N)

	time := make([]int, 24*60+2)
	for i := 0; i < len(time); i++ {
		time[i] = 0
	}

	for i := 0; i < N; i++ {
		var Sh, Sm, Eh, Em string
		fmt.Scanf("%2s%2s-%2s%2s\n", &Sh, &Sm, &Eh, &Em)
		h, _ := strconv.Atoi(Sh)
		m, _ := strconv.Atoi(Sm)
		start := h*60 + m - m%5
		time[start]++
		h, _ = strconv.Atoi(Eh)
		m, _ = strconv.Atoi(Em)
		m += 4
		end := h*60 + m - m%5
		time[end+1]--
	}

	cur := 0
	for i := 0; i < len(time); i++ {
		if time[i] > 0 && cur == 0 {
			t := i
			fmt.Printf("%02d%02d-", t/60, t%60)
		} else if cur > 0 && time[i] == 0 {
			t := i - 1
			fmt.Printf("%02d%02d\n", t/60, t%60)
		}
		cur = time[i]

		if i+1 < len(time) {
			time[i+1] += time[i]
		}

	}
}
