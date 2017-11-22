local a = {}
for i = 1, 3 do
  table.insert(a, io.read('*n'))
end

local b = {}
for i = 1, 3 do
  table.insert(b, io.read('*n'))
end

local a_count = 0
local b_count = 0
for i = 1, 3 do
  if a[i] > b[i] then
    a_count = a_count + 1
  elseif a[i] < b[i] then
    b_count = b_count + 1
  end
end

print(a_count .. " " .. b_count)