local s = io.read()

local erase = true
while erase do
  erase = false
  local index = -1
  for i = 1, s:len() - 1 do
    if s:sub(i, i) == s:sub(i + 1, i + 1) then
      index = i
      erase = true
      break
    end
  end
  if erase then
    s = s:sub(0, index-1) .. s:sub(index+2)
  end
end 

if s == "" then
  print('Empty String')
else
  print(s)
end