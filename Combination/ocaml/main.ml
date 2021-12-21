open Batteries

module CombMemo = struct
  let prime = 1_000_000_007
  let size = 2*1_00_000

  let memo = let arr = Array.make size None in
    arr.(0) <- Some 1;
    arr

  let ( *% ) a b = a * b mod prime
  let (-%) a b = (a+prime - b) mod prime
  let (+%) a b = (a + b) mod prime

  let rec pow n m =
    if m = 0 then 1
    else if m mod 2 = 0 then pow (n*%n) (m/2)
    else n *% pow (n*%n) (m/2)

  let rec fact n =
    match memo.(n) with
    | None ->
      let m = n *% fact (n-1) in
      memo.(n) <- Some m;
      m
    | Some a -> a

  let comb n k =
    fact n *% (pow (fact k) (prime-2)) *% (pow (fact (n - k)) (prime-2))
end

module Comb = struct
  let prime = 1_000_000_007

  let ( * ) a b = a * b mod prime

  let rec pow n m =
    if m = 0 then 1
    else if m mod 2 = 0 then pow (n*n) (m/2)
    else n * pow (n*n) (m/2)

  let fact n =
    let rec aux m acc =
      if m = 0 then acc
      else aux (pred m) @@ m * acc
    in aux n 1

  let comb n k =
    if n <= 0 || k <= 0 then 1
    else
      fact n * (pow (fact k) (prime-2)) * (pow (fact (n - k)) (prime-2))
end
