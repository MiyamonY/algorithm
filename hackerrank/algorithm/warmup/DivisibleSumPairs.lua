local n, k = io.read('*n', '*n')

local t = {}
for i = 1, n do
   table.insert(t, io.read('*n'))
end

function pairs(i, num, sum)
   if num == 2 then
      return sum % k == 0 and 1 or 0
   elseif i > #t then
      return 0
   else
      return pairs(i+1, num + 1, t[i] + sum) + pairs(i+1, num, sum)
   end
end

print(pairs(1, 0, 0))
