open StdLabels

module Graph = struct
  module Heap =
    Map.Make (struct
        type t = int * int
        let compare (a0, b0) (a1, b1)=
          let cmp = compare a0 a1 in
          if cmp = 0 then compare b0 b1 else cmp
      end)

  type t = int * int List.t Array.t

  let max_int = 1_000_000_000_000

  let make n = Array.make n []

  let add_route a b d g =
    g.(a) <- (d, b)::g.(a);
    g.(b) <- (d, a)::g.(b)

  let dikstra s g =
    let dists = Array.init (Array.length g)
                  ~f:(fun i -> if i = s then 0 else max_int) in
    let rec aux heap =
      match Heap.min_binding_opt heap with
      | None -> dists
      | Some ((d, f) as key , ()) ->
         let heap' = Heap.remove key heap in
         List.fold_left g.(f) ~init:heap'
           ~f:(fun h (d', t) ->
             let dist = d + d' in
             if dist < dists.(t) then
               (dists.(t) <- dist; Heap.add (dist, t) () h)
             else h) |> aux
    in aux Heap.(empty |> add (0, s) ())

end
