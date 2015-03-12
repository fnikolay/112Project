import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment
import Control.DeepSeq
import Data.Graph.Inductive.Internal.Heap(
  Heap(..),insert,findMin,deleteMin)

lim :: Int
lim = 10^6
 
-- heapsort is added in this module as an example application
 
build :: Ord a => [(a,b)] -> Heap a b
build = foldr insert Empty
 
toList :: Ord a => Heap a b -> [(a,b)]
toList Empty = []
toList h = x:toList r
           where (x,r) = (findMin h,deleteMin h)
 
heapsort :: Ord a => [a] -> [a]
heapsort = (map fst) . toList . build . map (\x->(x,x))

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
    let sorted = heapsort list
    end <- sorted `deepseq` getCPUTime
    let diff = (end - start) `div` (10^9)
    printf "%d\n" (diff :: Integer)
    hClose handle