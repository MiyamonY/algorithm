local time = io.read()

vals = {string.match(time, '^(%d+):(%d+):(%d+)(%a+)')}

if tonumber(vals[1]) == 12 then
  if vals[#vals] == 'AM' then
    vals[1] = 0
  end
elseif vals[#vals] == "PM" then
  vals[1] = 12 + tonumber(vals[1])
  vals[1] = vals[1] % 24
end

print(string.format("%02d:%02d:%02d", vals[1], vals[2], vals[3])) 
