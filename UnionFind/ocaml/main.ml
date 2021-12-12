open StdLabels

module UnionFind = struct
  type elem = {root: int; size: int}

  let make n = Array.init n ~f:(fun i -> {root=i; size=1})

  let root t n =
    let rec aux c =
      if c = t.(c).root then c
      else let p = aux t.(c).root in
        t.(c) <- {t.(c) with root=p}; p in
    aux n

  let size t v = t.(root t v).size

  let unite t v0 v1 =
    let w0 = root t v0 in
    let w1 = root t v1 in
    let s = (size t w0)+(size t w1) in
    t.(w1) <- {root=w0; size=s};
    t.(w0) <- {t.(w0) with size=s}

  let same t v0 v1 = root t v0 = root t v1
end

let () =
  let (n, q) = Scanf.scanf "%d %d" (fun a b -> (a, b)) in
  let uf = UnionFind.make n in
  List.iter (List.init ~len:q ~f:(fun v -> v)) ~f:(fun _ ->
      let (q, a, b) = Scanf.sscanf (read_line ()) "%d %d %d" (fun a b c -> (a, b, c)) in
      if q = 0 then
        UnionFind.unite uf a b
      else
      if UnionFind.same uf a b then
        Printf.printf "1\n"
      else Printf.printf "0\n")
