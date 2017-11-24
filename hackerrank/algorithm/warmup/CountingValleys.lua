local n = io.read('*n', '*l')

local hikes = io.read('*l')

local level = 0
local valleys = 0
for i = 1, #hikes do
   local hike = hikes:sub(i,i)
   local below = false
   if level < 0 then
      below = true
   end
   if hike == 'D' then
      level = level - 1
   elseif hike == 'U' then
      level = level + 1
   end
   if below and level == 0 then
      valleys = valleys + 1
   end
end

print(valleys)
