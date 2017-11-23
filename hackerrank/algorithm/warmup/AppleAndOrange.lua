local s, t = io.read('*n', '*n')
local a, b = io.read('*n', '*n')
local m, n = io.read('*n', '*n')

local apples = 0
for i = 1, m do
   local d = io.read('*n')
   if s <= a + d and a + d <= t then
      apples = apples + 1
   end
end

local oranges = 0
for i = 1, n do
   local d = io.read('*n')
   if s <= b + d and b + d <= t then
      oranges = oranges + 1
   end
end

print(apples)
print(oranges)
