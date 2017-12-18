local n = io.read('*n', '*l')

local t = {}
for i = 1, n do
   local value = io.read('*n')
   table.insert(t, value)
end

table.sort(t)

print(t[(1 + #t)/2])
