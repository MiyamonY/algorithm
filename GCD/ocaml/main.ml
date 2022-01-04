let rec gcd n m =
  if m = 0 then n
  else if n < m then gcd n @@ m mod n
  else gcd m @@ n mod m
