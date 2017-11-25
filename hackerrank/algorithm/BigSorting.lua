local n = io.read('*n', '*l')

local values = {}
for i = 1, n do
   local value = io.read('*l')
   table.insert(values, value)
end

table.sort(values, function(a, b)
              if a:len() == b:len() then
                 return a < b
              elseif a:len() < b:len() then
                 return true
              else
                 return false
              end
end)

for i = 1, n do
   print(values[i])
end
