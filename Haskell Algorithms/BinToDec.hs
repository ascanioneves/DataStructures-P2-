findLen :: [Int] -> Int
findLen [] = 0
findLen (a : as) = 1 + findLen as 

pot :: Int -> Int -> Int
pot _ 0 = 1
pot 0 _ = 0
pot x y = x * pot x (y - 1)

binToDecimal :: [Int] -> Int
binToDecimal [] = 0
binToDecimal (a:as) = a * pot 2 (findLen as) + binToDecimal as