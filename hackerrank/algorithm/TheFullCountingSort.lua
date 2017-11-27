local n = io.read('*n', "*l")

local t = {}
for i = 1, n do
  local line = io.read('*l')
  for num, s in line:gmatch('(%S+) (%S+)') do
    local str = s
    if i <= n / 2 then
      s = '-'
    end
    table.insert(t, {no=tonumber(num), str=s})
  end
end 

local nums = {}
local strs = {}
for i = 0, 99 do
  nums[i] = 0
  strs[i] = {}
end

for i = 1, #t do
  local no = t[i].no
  nums[no] = nums[no] + 1
  strs[no][#strs[no]+1] = t[i].str
end

for i = 0, 99 do
  local j = 1
  while nums[i] > 0 do
    io.write(strs[i][j], " ")
    j = j + 1
    nums[i] = nums[i] - 1
  end
end

