package main

import (
	"fmt"
	"math"
)

func main(){
	var n, m, k int
	for {
		fmt.Scan(&n, &m, &k)
		if n == 0 && m == 0 && k == 0{
			break
		}

		dp := make([][]int, n+1)
		for i:= 0; i < n+1; i++{
			dp[i] = make([]int, m*n + 1)
		}

		for i := 1; i <=m ; i++{
			dp[1][i] = 1
		}

		for i:= 1; i < n; i++{
			for j := 0; j <= i * m; j++{
				for k := 1; k <= m; k++{
					dp[i+1][j+k] += dp[i][j]
				}
			}
		}

		count := 0.0
		div := math.Pow(float64(m), float64(n))
		for i := 0; i <= n * m; i++{
			bill := 0.0
			if i <= k{
				bill = 1.0
			} else {
				bill = float64(i - k)
			}
			count += bill * float64(dp[n][i]) / div
		}
		fmt.Printf("%.010f\n", count)
	}
}
