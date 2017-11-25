local n = io.read('*n')

for i = 1, n do
   local a, b, c = io.read('*n', '*n', '*n')
   if math.abs(a - c) == math.abs(b - c) then
      print('Mouse C')
   elseif math.abs(a - c) < math.abs(b - c) then
      print('Cat A')
   else
      print('Cat B')
   end
end
