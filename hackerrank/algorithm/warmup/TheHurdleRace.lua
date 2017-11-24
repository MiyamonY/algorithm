local n, k = io.read('*n', '*n')

local count = 0
for i = 1, n do
   local height = io.read('*n')
   if k < height then
      count = count + height - k
      k = height
   end
end

print(count)
