local n = io.read('*n')

local socks = {}
for i = 1, n do
   table.insert(socks, io.read('*n'))
end

local i = 1
local count = 0
while i < #socks do
   for j = i + 1, #socks do
      if socks[i] == socks[j] then
         count = count + 1
         table.remove(socks, j)
         break
      end
   end
   i = i + 1
end

print(count)
