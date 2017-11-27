local nums = {}
for i = 0, 99 do
  nums[i] = 0
end

local n = io.read('*n')

for i = 1, n do
  local n = io.read('*n')
  nums[n] = nums[n] + 1
end

local vals = {}
for i = 0, 99 do
  while nums[i] > 0 do
    table.insert(vals, i)
    nums[i] = nums[i] - 1
  end
end

for i = 1, #vals do
  if i ~= 1 then
    io.write(' ')
  end
  io.write(vals[i])
end