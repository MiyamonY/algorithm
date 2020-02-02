// Package main provides
//
// File:  main.go
// Author: ymiyamoto
//
// Created on Sun Feb  2 15:06:11 2020
//
package main

const MOD = 1e9+7

func primeFactorization(n int)map[int]int{
    m := map[int]int{}
    for i:= 2;i*i <= n; i++{
        if n / i== 0{
            m[i]++
            n /= i
        }
    }
    m[n]++
    return m
}

func main(){

}
