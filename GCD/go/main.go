// Package main provides
//
// File:  main.go
// Author: ymiyamoto
//
// Created on Sun Feb  2 12:42:05 2020
//
package main

const MOD = 1e9 + 7

func gcd(n, m int) int {
	if m == 0 {
		return n
	} else if n < m {
		return gcd(n, m%n)
	} else {
		return gcd(m, n%m)
	}
}

func main() {

}
