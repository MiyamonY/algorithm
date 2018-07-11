// Package main provides
//
// File:  1237.go
// Author: ymiyamoto
//
// Created on Wed Jul 11 10:35:26 2018
//
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func comb(ns []string, aux [][]string) [][]string {
	if len(ns) == 0 {
		return aux
	}
	v := ns[0]
	a := [][]string{}
	for _, au := range aux {
		tmp := make([]string, len(au))
		copy(tmp, au)
		tmp[len(tmp)-1] += v
		a = append(a, tmp)

		au = append(au, v)
		a = append(a, au)
	}

	return comb(ns[1:], a)
}

func main() {
	for {
		var d int
		var num string
		fmt.Scan(&d, &num)
		if d == 0 {
			break
		}

		var min int
		ns := strings.Split(num, "")
		for i := range ns {
			v, _ := strconv.Atoi(ns[i])
			min += v
		}

		var ans int
		var pat []string
		var hasSame bool
		for _, c := range comb(ns[1:], [][]string{{ns[0]}}) {
			var total int
			for _, v := range c {
				n, _ := strconv.Atoi(v)
				total += n
			}
			if ans == total {
				hasSame = true
			} else if ans < total && total <= d {
				ans = total
				pat = c
				hasSame = false
			}
		}

		if ans == 0 {
			fmt.Println("error")
		} else if hasSame {
			fmt.Println("rejected")
		} else {
			fmt.Println(ans, strings.Join(pat, " "))
		}
	}
}
