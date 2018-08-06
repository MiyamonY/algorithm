///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 16:08:03 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func nextLine() string {
	sc.Scan()
	return sc.Text()
}

func main() {
	buf := make([]byte, 1e7)
	sc.Buffer(buf, 1e7)

	nextLine()
	line := nextLine()
	arr := strings.Split(line, " ")
	m := map[int]int{}
	for i := range arr {
		v, _ := strconv.Atoi(arr[i])
		m[v]++
	}

	nextLine()
	line = nextLine()
	arr = strings.Split(line, " ")
	for i := range arr {
		t, _ := strconv.Atoi(arr[i])
		if m[t] > 0 {
			m[t]--
		} else {
			fmt.Println("NO")
			return
		}
	}

	fmt.Println("YES")
}
