local n = io.read('*n')

local values = {}
for i = 1, n do
   table.insert(values, io.read('*n'))
end

local count = 0
for i = 2, n do
   for j = i, 2, -1 do
      if values[j - 1] > values[j] then
         values[j - 1], values[j] = values[j], values[j - 1]
         count = count + 1
      end
   end
end

print(count)
