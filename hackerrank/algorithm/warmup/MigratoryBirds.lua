local n = io.read('*n')

local flocks = {}
for i = 1, n do
   local flock = io.read('*n')
   if flocks[flock] then
      flocks[flock] = flocks[flock] + 1
   else
      flocks[flock] = 1
   end
end

local max_flock = 0
local max_num = 0
for i = 1, 5 do
   if flocks[i] then
      if max_num < flocks[i] then
         max_num = flocks[i]
         max_flock = i
      end
   end
end
print(max_flock)
