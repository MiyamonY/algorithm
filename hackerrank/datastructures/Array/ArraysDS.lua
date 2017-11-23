local n = io.read('*n')

local t = {}
for i = 1, n do
   local val = io.read('*n')
   table.insert(t, val)
end

for i = #t, 1, -1 do
   io.write(t[i] .. ' ')
end
io.write('\n')
