getDigit :: Int -> Int -> Int -> Int
getDigit x n base = div (mod x base) n


maxLen :: [Int] -> Int
maxLen xs = length (show (maximum xs))

while :: Int -> Int -> [Int] -> [Int]
while n base xs
  | (div (maximum xs) n) > 0  = while (n*10) (base*10) (radix n base xs)
  | (div (maximum xs) n) <= 0 = xs

radix :: Int -> Int -> [Int] -> [Int]
radix n base xs = let b = [[],[],[],[],[],[],[],[],[],[]] in
                  concat (toBucket n base b xs)

toBucket :: Int -> Int -> [[Int]] -> [Int] -> [[Int]]
toBucket n base b [] = b
toBucket n base b (x:xs) = let (ys,zs) = splitAt (getDigit x n base) b in
                            toBucket n base (ys ++ [(inBucket (b !! (getDigit x n base)) x)] ++ (tail zs)) xs

inBucket :: [Int] -> Int -> [Int]
inBucket b x = b ++ [x]
