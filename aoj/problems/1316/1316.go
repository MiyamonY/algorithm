package main

import "fmt"

var H, W int

type point struct {
	x, y int
}

func (p *point) add(q point) {
	p.x += q.x
	p.y += q.y
	if p.x < 0 {
		p.x += H
	}
	if p.y < 0 {
		p.y += W
	}
	p.x %= H
	p.y %= W
}

func isPalindrome(str string) bool {
	for i, j := 0, len(str)-1; i < j; i, j = i+1, j-1 {
		if str[i] != str[j] {
			return false
		}
	}
	return true
}

func magicSpel(arr []string) string {
	var ans string
	m := map[string]int{}
	for i := range arr {
		for j := range arr[i] {
			for _, d := range []point{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}} {
				cur := point{x: i, y: j}
				str := string(arr[cur.x][cur.y])
				cur.add(d)
				for i != cur.x || j != cur.y {
					str += string(arr[cur.x][cur.y])
					cur.add(d)
					if isPalindrome(str) {
						m[str] += 2
					} else {
						m[str]++
					}
				}
			}
		}
	}
	for s, v := range m {
		if 1 < v {
			if len(ans) < len(s) {
				ans = s
			} else if len(ans) == len(s) && s < ans {
				ans = s
			}
		}
	}

	if len(ans) == 0 {
		return "0"
	}

	return ans
}

func main() {
	for {
		fmt.Scan(&H, &W)
		if H == 0 && W == 0 {
			break
		}

		var arr []string

		for i := 0; i < H; i++ {
			var s string
			fmt.Scan(&s)
			arr = append(arr, s)
		}

		fmt.Println(magicSpel(arr))
	}
}
