import Text.Printf
import Control.Monad
import Control.Exception
import Control.Parallel.Strategies
import System.IO
import System.CPUTime
import System.Environment



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
    start <- getCPUTime
    let sorted = heapsort list
    print(heapsort (list))
    end <- getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)


    printf "Unsorted List:"
    print list
    printf "Sorted List:"
    print sorted
    printf "Computation time: %0.9f sec\n" (diff :: Double)
    printf "Individual time: %0.9f sec\n" (diff / fromIntegral lim :: Double)



