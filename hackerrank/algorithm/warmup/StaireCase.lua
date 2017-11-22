local n = io.read('*n')

for i = 1, n do
  local str = ''
  for j = 1, n do
    if n - i < j then
      str = str .. "#"
    else
      str = str .. " "
    end
  end
  io.write(str .. "\n")
end
