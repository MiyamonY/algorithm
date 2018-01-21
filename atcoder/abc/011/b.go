///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 12:33:21 2018
//
package main

import "fmt"
import "strings"

func main() {
	var S string
	fmt.Scan(&S)

	if len(S) == 1 {
		fmt.Println(strings.ToUpper(S[0:1]))
	}else{
		fmt.Println(strings.ToUpper(S[0:1]) + strings.ToLower(S[1:]))
	}
}
