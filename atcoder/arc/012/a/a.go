///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Apr 20 00:07:17 2018
//
package main

import (
	"fmt"
)

var day string

func main() {
	fmt.Scan(&day)

	var rest int
	switch day {
	case "Sunday":
		rest = 0
	case "Monday":
		rest = 5
	case "Tuesday":
		rest = 4
	case "Wednesday":
		rest = 3
	case "Thursday":
		rest = 2
	case "Friday":
		rest = 1
	case "Saturday":
		rest = 0
	}

	fmt.Println(rest)
}
