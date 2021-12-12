open StdLabels

let binary_search arr ~cmp =
  let rec aux l h =
    let m = (l + h) / 2 in
    if l + 1 = h then h
    else if cmp arr.(m) then aux m h
    else aux l m
  in
  aux (-1) @@ Array.length arr

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
      let i = binary_search arr ~cmp:(fun v -> v < x) in
      Printf.printf "%d\n" @@ n - i)
