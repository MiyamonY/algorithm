package main

import (
	"fmt"
	"sort"
)

type set struct {
	s []int
}

var N, K int
var S string

func remove(set []int, a int) []int {
	s := make([]int, len(set))
	copy(s, set)
	for i := range s {
		if a == s[i] {
			return append(s[:i], s[i+1:]...)
		}
	}
	panic("not found")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}

func diffs(T []int, rests []int) bool {
	same := 0
	for i := range T {
		if int(S[i]) == T[i] {
			same++
		}
	}

	setS := map[int]int{}
	setRests := map[int]int{}
	for i := len(T); i < len(S); i++ {
		setS[int(S[i])]++
	}

	for i := range rests {
		setRests[int(rests[i])]++
	}

	for key, val := range setS {
		same += min(val, setRests[key])
	}

	return len(S)-same <= K
}

func main() {
	fmt.Scan(&N, &K)
	fmt.Scan(&S)

	var set []int
	for i := range S {
		set = append(set, int(S[i]))
	}
	sort.Ints(set)

	var T []int
	for j := 0; j < len(S); j++ {
		for _, s := range set {
			remSet := remove(set, s)
			if diffs(append(T, s), remSet) {
				T = append(T, s)
				set = remSet
				goto next
			}
		}
		T = append(T, set[0])
		set = remove(set, int(set[0]))
	next:
	}

	for _, t := range T {
		fmt.Print(string(uint8(t)))
	}
	fmt.Println()
}
