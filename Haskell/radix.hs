import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment
import Control.DeepSeq
import Data.Sequence
import Data.Foldable


lim :: Int
lim = 10^6

getDigit :: Int -> Int -> Int -> Int
getDigit x n base = div (mod x base) n


maxLen :: [Int] -> Int
maxLen xs = Prelude.length (show (Prelude.maximum xs))

radixS :: Int -> Int -> [Int] -> [Int]
radixS n base xs
  | (div (Prelude.maximum xs) n) > 0  = radixS (n*10) (base*10) (mergeB n base xs)
  | (div (Prelude.maximum xs) n) <= 0 = xs

mergeB :: Int -> Int -> [Int] -> [Int]
mergeB n base xs = toList (Data.Foldable.foldl1 (><) (getBucket n base (fromList [empty | i <- [1..10]]) xs))

getBucket :: Int -> Int -> Seq (Seq Int) -> [Int] -> Seq (Seq Int)
getBucket n base b [] = b
getBucket n base b (x:xs) = let i = (getDigit x n base) in
                               getBucket n base (update i (insertB (index b i) x) b) xs



insertB :: Seq Int -> Int -> Seq Int
insertB b x = b |> x

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
