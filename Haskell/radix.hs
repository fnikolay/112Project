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

getDigit :: Int -> Int -> Int -> Int
getDigit x n base = div (mod x base) n


maxLen :: [Int] -> Int
maxLen xs = length (show (maximum xs))

radixS :: Int -> Int -> [Int] -> [Int]
radixS n base xs
  | (div (maximum xs) n) > 0  = radixS (n*10) (base*10) (mergeB n base xs)
  | (div (maximum xs) n) <= 0 = xs

mergeB :: Int -> Int -> [Int] -> [Int]
mergeB n base xs = let b = [[],[],[],[],[],[],[],[],[],[]] in
                  concat (getBucket n base b xs)

getBucket :: Int -> Int -> [[Int]] -> [Int] -> [[Int]]
getBucket n base b [] = b
getBucket n base b (x:xs) = let (ys,zs) = splitAt (getDigit x n base) b in
                            getBucket n base (ys ++ [(insertB (b !! (getDigit x n base)) x)] ++ (tail zs)) xs

insertB :: [Int] -> Int -> [Int]
insertB b x = b ++ [x]

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
    let sorted = radixS 1 10 list
    end <- sorted `deepseq` getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)
    printf "Computation time: %0.9f sec\n" (diff :: Double)
    putStrLn "Done."
    hClose handle
