local v = io.read('*n', '*l')
local n = io.read('*n', '*l')

for i = 1, n do
   local value = io.read('*n')
   if value == v then
      print(i - 1)
   end
end
