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


local val = values[#values]
local at = 1
for i = #values, 2, -1 do
   if values[i-1] > val then
      values[i] = values[i-1]
      print_table(values)
   else
      at = i
      break
   end
end

values[at] = val

print_table(values)
