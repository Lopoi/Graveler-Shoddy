local start = os.clock()
local rounds = 231
local rolls = 0

-- Get maxRolls from command-line argument or default to 100
local maxRolls = tonumber(arg[1]) or 100
print('Running for ' .. maxRolls .. ' rolls')

local ones = 0
local maxOnes = 0
local items = { 1, 2, 3, 4 }

while ones < 177 and rolls < maxRolls do
    ones = 0
    for i = 1, rounds do
        local roll = items[math.random(1, 4)]
        if roll == 1 then
            ones = ones + 1
            if i > maxOnes and ones + (rounds - i) < maxOnes then
                break
            end
        end
    end
    rolls = rolls + 1
    if ones > maxOnes then
        print(ones)
        maxOnes = ones
    end
end

local end_time = os.clock()
print('Time: ' .. (end_time - start) .. 's')
print('Max: ' .. maxOnes)
