local m, n = io.read('*n', '*n')

local t1 = {}
for i = 1, m do
   local val = io.read('*n')
   table.insert(t1, val)
end

local t2 = {}
for i = 1, n do
   local val = io.read('*n')
   table.insert(t2, val)
end

local factors = {}
for i = 1, 100 do
   local factor = true
   for j = 1, #t1 do
      if i % t1[j] ~= 0 then
         factor  =false
      end
   end
   if factor then
      table.insert(factors, i)
   end
end

local count = 0
for i = 1, #factors do
   local factor = true
   for j = 1, #t2 do
      if t2[j] % factors[i] ~= 0 then
         factor = false
      end
   end
   if factor then
      count = 1 + count
   end
end

print(count)
