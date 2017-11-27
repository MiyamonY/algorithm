local nums = {}
for i = 0, 99 do
  nums[i] = 0
end

local n = io.read('*n')

local t = {}
for i = 1, n do
  local val = io.read('*n')
  nums[val] = nums[val] + 1
end 

for i = 0, 99 do
  if i ~= 0 then
    io.write(' ')
  end
  io.write(nums[i])
end