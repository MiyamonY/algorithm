///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 16:40:12 2018
//
package main

import "fmt"

type direction struct {
	name string
	from float64
	to   float64
}

func round(val float64) float64 {
	fmt.Println(val, int(val*100), int(val*100)%10)
	if int(val*100)%10 <= 4 {
		return float64(int(val*10)) / 10
	}
	fmt.Println(float64(int(val*100+5)) / 100)
	return float64(int(val*100+5)) / 100
}

func main() {
	deg := 0.0
	dis := 0
	fmt.Scan(&deg, &dis)

	directions := []direction{
		direction{"NNE", 11.25, 33.75},
		direction{"NE", 33.75, 56.25},
		direction{"ENE", 56.25, 78.75},
		direction{"E", 78.75, 101.25},
		direction{"ESE", 101.25, 123.75},
		direction{"SE", 123.75, 146.25},
		direction{"SSE", 146.25, 168.75},
		direction{"S", 168.75, 191.25},
		direction{"SSW", 191.25, 213.75},
		direction{"SW", 213.75, 236.25},
		direction{"WSW", 236.25, 258.75},
		direction{"W", 258.75, 281.25},
		direction{"WNW", 281.25, 303.75},
		direction{"NW", 303.75, 326.25},
		direction{"NNW", 326.25, 348.75},
	}
	direction := "N"

	for _, dir := range directions {
		if dir.from*10 <= deg && deg < dir.to*10 {
			direction = dir.name
		}
	}

	strength := 12
	winds := []int{25, 155, 335, 545, 795, 1075, 1385, 1715, 2075, 2445, 2845, 3265}
	for pos, wind := range winds {
		if dis*10 < wind*6 {
			strength = pos
			break
		}
	}

	if strength == 0 {
		direction = "C"
	}
	fmt.Println(direction, strength)
}
