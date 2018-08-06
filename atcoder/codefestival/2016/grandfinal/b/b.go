///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 10:51:31 2018
//
package main

import (
	"fmt"
	"math"
)

type arg float64

type point struct {
	x, y float64
}

func (p point) diff(q point) point {
	return point{x: p.x - q.x, y: p.y - q.y}
}

func (p point) abs() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p point) inner(q point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p point) arg(q, r point) arg {
	p0 := q.diff(p)
	p1 := r.diff(p)

	return arg(math.Acos(p0.inner(p1) / (p0.abs() * p1.abs())))
}

func main() {
	points := [3]point{}
	for i := 0; i < len(points); i++ {
		fmt.Scan(&points[i].x)
		fmt.Scan(&points[i].y)
	}

	theta0 := points[0].arg(points[1], points[2])
	theta1 := points[1].arg(points[2], points[0])
	theta2 := points[2].arg(points[0], points[1])
	var x, y point
	var thetax, thetay arg
	if theta0 < theta1 {
		if theta1 < theta2 {
			x = points[1]
			thetax = theta1
			y = points[0]
			thetay = theta0
		} else {
			x = points[2]
			thetax = theta2
			y = points[0]
			thetay = theta0
		}
	} else {
		if theta0 < theta2 {
			x = points[1]
			thetax = theta1
			y = points[0]
			thetay = theta0
		} else {
			x = points[1]
			thetax = theta1
			y = points[2]
			thetay = theta2
		}
	}

	r := x.diff(y)
	d := r.abs()

	fmt.Println(d / (2 + 1/math.Tan(float64(thetax/2)) + 1/math.Tan(float64(thetay/2))))
}
