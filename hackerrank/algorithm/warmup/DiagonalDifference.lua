local n = io.read('*n')

local values = {}
for i = 1, n do
  values[i] = {}
  for j = 1, n do
    table.insert(values[i], io.read('*n'))
  end
end

local rdigonal = 0
for i = 1, n do
  rdigonal = rdigonal + values[i][i]
end

local ldigonal = 0
for i = 1, n do
  ldigonal = ldigonal + values[i][n + 1- i]
end

print(math.abs(rdigonal - ldigonal))