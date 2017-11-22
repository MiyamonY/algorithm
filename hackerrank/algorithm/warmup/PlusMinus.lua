local n = io.read('*n')

local num_pos = 0
local num_neg = 0
local num_zero = 0
local num = 0
for i = 1, n do
  local val = io.read('*n')
  if val > 0 then
    num_pos = 1 + num_pos
  elseif val < 0 then
    num_neg = 1 + num_neg
  else
    num_zero = num_zero + 1
  end
  num = num + 1
end

print(string.format("%.6f", num_pos/num))
print(string.format("%.6f", num_neg/num))
print(string.format("%.6f", num_zero/num))
