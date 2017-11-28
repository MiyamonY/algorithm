local s = io.read()

local count = 1
for _ in s:gmatch("%u") do
  count = count + 1
end

print(count)