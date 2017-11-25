local n = io.read('*n')

local points = {}
for i = 1, n do
   local point = io.read('*n')
   table.insert(points, point)
end

local min = {point=points[1], count=0}
local max = {point=points[1], count=0}

for i = 2, n do
   if points[i] < min.point then
      min.point = points[i]
      min.count = min.count + 1
   end
   if max.point < points[i]  then
      max.point = points[i]
      max.count = max.count + 1
   end
end

io.write(string.format('%d %d', max.count, min.count))
