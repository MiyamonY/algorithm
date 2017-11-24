local n, k = io.read('*n', '*n')

local costs = {}
local total = 0
for i = 1 , n do
   local cost = io.read('*n')
   table.insert(costs, cost)
   total = total + cost
end

local charged = io.read('*n')
local diff = charged - (total - costs[k + 1]) // 2
print(diff ~= 0 and diff or 'Bon Appetit')
