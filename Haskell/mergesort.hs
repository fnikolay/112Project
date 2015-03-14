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

subDivide :: [Int] -> ([Int],[Int])
subDivide (a:b:rest) = (a:left, b:right) where
                       (left,right) = subDivide rest 
subDivide [a] = ([a],[])
subDivide []  = ([],[])

merge :: [Int] -> [Int] -> [Int]
merge left []  = left
merge [] right = right
merge left@(l:ls) right@(r:rs)
    | l <= r    = l : merge ls right
    | otherwise = r : merge left rs

mergeSort :: [Int] -> [Int]
mergeSort []     = []
mergeSort [arr]  = [arr]
mergeSort array  = merge (mergeSort left) (mergeSort right) where
                   (left,right) = subDivide array

f :: [String] -> [Int]
f = map read

main = do
    [n] <- getArgs
    let list = []
    handle <- openFile n ReadMode
    contents <- hGetContents handle
    let singlewords = words contents
<<<<<<< HEAD
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
=======
        list = f singlewords

    start <- getCPUTime
    let sorted = mergeSort list
    end <- sorted `deepseq` getCPUTime
    let diff = (end - start) `div` (10^9)
    printf "%d\n" (diff :: Integer)
    hClose handle
>>>>>>> FETCH_HEAD
