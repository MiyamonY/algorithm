local n = io.read('*n', '*l')

local t = {}
for i = 1, n do
   local val = io.read('*n')
   table.insert(t, val)
end

table.sort(t)

local min = 10e7
for i = 1, #t do
   if i+1 <= #t then
      min = math.min(min, t[i+1] - t[i])
   end
end

for i = 1, #t do
   if i + 1 <= #t then
      if min == t[i+1] - t[i] then
         io.write(string.format("%d %d ", t[i], t[i+1]))
      end
   end
end
