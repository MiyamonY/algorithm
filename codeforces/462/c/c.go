///
// File:  c.go
// Author: ymiyamoto
//
// Created on Tue Mar 13 22:21:00 2018
//
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var N int
var arr []int

var reader = bufio.NewReaderSize(os.Stdin, 1000000)

func readLine() string {
	buf := make([]byte, 0, 1000000)
	for {
		l, p, _ := reader.ReadLine()
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

func main() {
	fmt.Scan(&N)
	fmt.Println()

	arr = make([]int, N)
	for i, v := range strings.Split(readLine(), " ") {
		arr[i], _ = strconv.Atoi(v)
	}

	sort.Ints(arr)

	var count int64
	for i, v := range arr {
		count += int64((2 + i) * v)
	}
	count -= int64(arr[len(arr)-1])

	fmt.Println(count)
}
