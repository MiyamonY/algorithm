local s, n, m = io.read('*n', '*n', '*n')

local keyboards = {}
for i = 1, n do
   local keyboard = io.read('*n')
   table.insert(keyboards, keyboard)
end

local mouses = {}
for i = 1, m do
   local mouse = io.read('*n')
   table.insert(mouses, mouse)
end

local cost = -1
for i = 1, n do
   for j = 1, m do
      local total_cost = keyboards[i] + mouses[j]
      if total_cost <= s then
         if cost < total_cost then
            cost = total_cost
         end
      end
   end
end

print(cost)
