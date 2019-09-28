const MOD: i64 = 1_000_000_007;

fn fact(n: i64) -> i64 {
    (1..n + 1).fold(1, |a, b| a * b % MOD)
}

fn pow(n: i64, k: i64) -> i64 {
    match k {
        0 => 1,
        a if a % 2 == 0 => pow(n * n % MOD, k / 2),
        _ => n * pow(n * n % MOD, k / 2) % MOD,
    }
}

fn combination(n: i64, k: i64) -> i64 {
    (fact(n) * pow(fact(k), MOD - 2) % MOD) * pow(fact(n - k), MOD - 2) % MOD
}

fn main() {
    println!("{}", combination(10, 3))
}

#[test]
fn test_fact() {
    assert_eq!(fact(5), 120);
    assert_eq!(fact(7), 5040);
}

#[test]
fn test_pow() {
    assert_eq!(pow(3, 3), 27);
    assert_eq!(pow(5, 4), 5 * 5 * 5 * 5);
}

#[test]
fn test_combination() {
    assert_eq!(combination(3, 1), 3);
    assert_eq!(combination(10, 2), 45);
    assert_eq!(combination(10, 3), 120);
}
