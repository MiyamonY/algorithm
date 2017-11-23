local n = io.read('*n')

for i = 1, n do
   local val = io.read('*n')
   if val < 38 then
      print(val)
   else
      local grade = math.floor((val + 5) / 5) * 5
      if grade - val < 3 then
         print(grade)
      else
         print(val)
      end
   end
end
