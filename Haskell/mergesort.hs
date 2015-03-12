import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment
import Control.DeepSeq

--mergesort haskell implementation
lim :: Int
lim = 10^6

merge :: [Int] -> [Int] -> [Int]
merge left []  = left
merge [] right = right
merge left@(l:ls) right@(r:rs)
    | l <= r    = l : merge ls right
    | otherwise = r : merge left rs

subDivide :: [Int] -> ([Int],[Int])
subDivide (a:b:rest) = let (left,right) = subDivide rest in (a:left, b:right)
subDivide [a] = ([a],[])
subDivide []  = ([],[])

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

    start <- getCPUTime
    let sorted = mergeSort list
    end <- sorted `deepseq` getCPUTime
    let diff = (end - start) `div` (10^9)
    printf "%d\n" (diff :: Integer)
    hClose handle