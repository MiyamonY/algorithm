///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 17:52:31 2018
//
package main

import (
	"fmt"
	"strings"
)

var S string

type stack struct {
	top *node
	len int
}

type node struct {
	val  string
	prev *node
}

func create() *stack {
	return &stack{nil, 0}
}

func (s *stack) push(tok string) {
	s.top = &node{val: tok, prev: s.top}
	s.len++
}

func (s *stack) pop() string {
	top := s.top
	s.top = s.top.prev
	s.len--
	return top.val
}

func (s *stack) peek() string {
	return s.top.val
}

func reverse(s []string) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func main() {
	fmt.Scan(&S)

	stack := create()
	var buf string
	for _, c := range S {
		switch c {
		case '+', '-', '*', '/':
			stack.push(string(c))
		case '(':
			stack.push(string(c))
		case ')':
			if buf != "" {
				stack.push(buf)
				buf = ""
			}
			vals := make([]string, 0)
			for stack.peek() != "(" {
				vals = append(vals, stack.pop())
			}
			reverse(vals)
			stack.pop()
			op := stack.pop()
			exp := "(" + strings.Join(vals, op) + ")"
			stack.push(exp)
		case ',':
			if buf != "" {
				stack.push(buf)
				buf = ""
			}
		default:
			buf += string(c)
		}
	}

	if buf != "" {
		stack.push(buf)
		buf = ""
	}

	fmt.Println(stack.pop())
}
