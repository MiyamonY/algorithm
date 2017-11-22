local n = io.read('*n')

local values = {}

for i = 1, n do
  table.insert(values, io.read('n'))
end

local sum = 0
for i = 1, #values do
  sum = sum + values[i]
end

print(sum)
