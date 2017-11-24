local n = io.read('*n')
local p = io.read('*n')

if n % 2 == 1 then
   n = n - 1
end

if p % 2 == 1 then
   p = p - 1
end

print(math.min(math.abs(p - n) // 2, (p - 0) // 2))
