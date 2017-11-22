local n = io.read('*n')

local candles = {}
for i = 1, n do
  table.insert(candles, io.read('*n'))
end

table.sort(candles)

local max = candles[#candles]
local count = 0

for i = #candles, 1, -1 do
  if max == candles[i] then
    count = 1 + count
  else
    break
  end
end

print(count)