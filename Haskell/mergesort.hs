--mergesort haskell implementation
subDivide :: [Int] -> ([Int],[Int])
subDivide (x:y:rest) = let (left,right) = subDivide rest in (x:left, y:right)
subDivide [x] = ([x],[])
subDivide [] = ([],[])

merge :: [Int] -> [Int] -> [Int]
merge [] right = right
merge left [] = left
merge left@(l:ls) right@(r:rs)
                          | l <= r    = l : merge ls right
                          | otherwise = r : merge left rs

mergeSort :: [Int] -> [Int]
mergeSort []  = []
mergeSort [arr] = [arr]
mergeSort array  = let (left,right) = subDivide array
                in merge (mergeSort left) (mergeSort right)