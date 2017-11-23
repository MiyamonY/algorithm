local n = io.read('*n')

local t = {}
for i = 1, n do
   table.insert(t, io.read('*n'))
end

local d, m = io.read('*n', '*n')

local count = 0
for i = 1, #t do
   local val = 0
   for j = 0, m - 1 do
      if i + j > #t then
         val = 0
         break
      end
      val = val + t[i+j]
   end
   if val == d then
      count = 1 + count
   end
end

print(count)
