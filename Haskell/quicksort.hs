import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment
import Control.DeepSeq

lim :: Int
lim = 10^6

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = (quicksort low) ++ [x] ++ (quicksort high)
    where
        low = filter (< x) xs
        high = filter (>= x) xs

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
    let sorted = quicksort list
    end <- sorted `deepseq` getCPUTime
    let diff = (end - start) `div` (10^9)
    printf "%d\n" (diff :: Integer)
    hClose handle