module type PrimeType = sig val prime: int end

module MakeModInt =
  functor(Elt: PrimeType) ->
  struct
    let ( +% ) a b = (a + b) mod Elt.prime
    let ( -% ) a b = (a + Elt.prime - b) mod Elt.prime
    let ( *% ) a b = (a * b) mod Elt.prime

    let pow n m =
      let rec aux n m =
        if m = 0 then 1
        else if m mod 2 = 0 then aux (n*%n) (m/2)
        else n *% aux (n*%n) (m/2)
      in aux (n mod Elt.prime) m

    let ( **% ) n m = pow n m

    let rec fact n =
      if n = 0 then 1
      else n *% fact (n - 1)

    let comb n k =
      fact n *% ((fact k) **% (Elt.prime-2)) *% ((fact @@ n - k) **% (Elt.prime-2))
  end

let prime = 998244353

module ModInt = MakeModInt(struct let prime = prime end)

let () =
  let open MakeModInt(struct let prime = prime end) in
  Printf.printf "%d" @@ 100_000_000 **% 100_000_000
