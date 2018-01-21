///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 14:58:25 2018
//
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	m := make(map[string]int)
	max_num := 0
	var max_name string

	for i := 0; i < N; i++ {
		var name string
		fmt.Scan(&name)
		if elem, ok := m[name]; ok {
			m[name] = elem + 1
		} else {
			m[name] = 1
		}
		if max_num < m[name] {
			max_num = m[name]
			max_name = name
		}
	}

	fmt.Println(max_name)
}
