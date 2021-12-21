open StdLabels

module BinarySearch = struct
  let search n ~f =
    let rec aux l h =
      let m = (l + h) / 2 in
      if h - l = 1 then h
      else if f m then aux l m
      else aux m h
    in aux (-1) n

  let array arr ~f =
    let rec aux l h =
      let m = (l + h) / 2 in
      if l + 1 = h then h
      else if f arr.(m) then aux m h
      else aux l m
    in aux (-1) @@ Array.length arr
end

let () =
  let (n, q) = Scanf.scanf "%d %d" (fun a b -> (a, b)) in
  let arr =
    Str.split (Str.regexp_string " ") @@ read_line ()
    |> List.map ~f:int_of_string
    |> Array.of_list
  in
  Array.sort ~cmp:compare arr;
  List.iter (List.init q (fun _ -> 0)) ~f:(fun _ ->
      let x = Scanf.scanf "%d" (fun x -> x) in
      let i = BinarySearch.array arr ~f:(fun v -> v < x) in
      Printf.printf "%d\n" @@ n - i)
