///
// File:  0582.go
// Author: ymiyamoto
//
// Created on Wed Feb 28 22:51:48 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	steep = iota
	orth
	obtuse
)

func max(a, b, c int) (int, int, int) {
	if a < b {
		if b < c {
			return c, a, b
		} else {
			return b, c, a
		}
	} else {
		if a < c {
			return c, a, b
		} else {
			return a, b, c
		}
	}
}

func triangle(a, b, c int) int {
	if a*a == b*b+c*c {
		return orth
	} else if b*b+c*c-a*a > 0 {
		return steep
	} else {
		return obtuse
	}
}

func main() {
	s := bufio.NewScanner(os.Stdin)

	var num, st, or, ob int
	for s.Scan() {
		var a, b, c int
		fmt.Sscan(s.Text(), &a, &b, &c)

		m, n1, n2 := max(a, b, c)
		if m < n1+n2 {
			switch triangle(m, n1, n2) {
			case steep:
				st++
			case orth:
				or++
			case obtuse:
				ob++
			}
			num++
		} else {
			break
		}
	}
	fmt.Println(num, or, st, ob)
}
