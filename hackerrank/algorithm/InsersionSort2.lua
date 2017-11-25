local n = io.read('*n')

function print_table(t)
   for i = 1, #t do
      if i ~= 1 then
         io.write(' ')
      end
      io.write(t[i])
   end
   io.write('\n')
end

local values = {}
for i = 1, n do
   table.insert(values, io.read('*n'))
end

for i = 2, n do
   for j = i, 2, -1 do
      if values[j - 1] > values[j] then
         values[j - 1], values[j] = values[j], values[j - 1]
      end
   end
   print_table(values)
end
