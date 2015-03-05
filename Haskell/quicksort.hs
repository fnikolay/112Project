import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment


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

    putStrLn "Starting..."
    start <- getCPUTime
    let sorted = quicksort list
    end <- getCPUTime
    printf "Unsorted List:"
    print list
    printf "Sorted List:"
    print sorted
    let diff = (fromIntegral (end - start)) / (10^12)
    printf "Computation time: %0.9f sec\n" (diff :: Double)
    putStrLn "Done."
    hClose handle
