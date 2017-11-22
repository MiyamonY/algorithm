local total = 0
local arr = {}
for token in string.gmatch(io.read(), "[^%s]+") do
  arr[#arr+ 1] = token
  total = total + token
end 

table.sort(arr)

local min = arr[1]
local max = arr[#arr]

print(string.format("%d %d", total - max, total - min))