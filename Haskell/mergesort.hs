import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment

--mergesort haskell implementation
lim :: Int
lim = 10^6

subDivide :: [Int] -> ([Int],[Int])
subDivide (x:y:rest) = let (left,right) = subDivide rest in (x:left, y:right)
subDivide [x] = ([x],[])
subDivide []  = ([],[])

merge :: [Int] -> [Int] -> [Int]
merge [] right = right
merge left []  = left
merge left@(l:ls) right@(r:rs)
    | l <= r    = l : merge ls right
    | otherwise = r : merge left rs

mergeSort :: [Int] -> [Int]
mergeSort []     = []
mergeSort [arr]  = [arr]
mergeSort array  = let (left,right) = subDivide array
                in merge (mergeSort left) (mergeSort right)

f :: [String] -> [Int]
f = map read

main = do
    [n] <- getArgs
    let list = []
    handle <- openFile n ReadMode
    contents <- hGetContents handle
    let singlewords = words contents
        list = f singlewords    

    let sorted = mergeSort list


    printf "Unsorted List:"
    print list
    printf "Sorted List:"
    start <- getCPUTime
    print sorted
    end <- getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)

    printf "Computation time: %0.9f sec\n" (diff :: Double)
    printf "Individual time: %0.9f sec\n" (diff / fromIntegral lim :: Double)