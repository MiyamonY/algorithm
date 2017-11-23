local x1, v1, x2, v2 = io.read('*n', '*n', '*n', '*n')

if x2 < x1 then
   x1, x2 = x2, x1
   v1, v2 = v2, v1
end

local found = false
if v1 > v2 then
   local diff = x2 - x1
   if diff % (v1 - v2) == 0 then
      found = true
   end
end

if found then
   print("YES")
else
   print("NO")
end
