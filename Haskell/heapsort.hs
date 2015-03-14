import System.CPUTime
import System.Environment
import System.IO
import Text.Printf
import Control.DeepSeq

lim :: Int
lim = 10^6

--heap data structure
data Heap h = Empty | T Int h (Heap h) (Heap h) 
 
rank Empty = 0 
rank (T r _ _ _) = r 
 
heapify x a b = 
    if rank a > rank b then 
        T (rank b + 1) x a b 
    else 
        T (rank a + 1) x b a 
 
merge h Empty = h 
merge Empty h = h

merge h1@(T _ x a1 b1) h2@(T _ y a2 b2) = 
    if x >= y then heapify x a1 (merge b1 h2) else heapify y a2 (merge h1 b2) 
 
toList xs Empty = xs 
toList xs (T _ x a b) = toList (x:xs) (merge a b)
 
heapsort xs = toList [] (foldl (\h x -> merge (heapify x Empty Empty) h) Empty xs)


f :: [String] -> [Int]
f = map read

main = do
    [n] <- getArgs
    let list = []
    handle <- openFile n ReadMode
    contents <- hGetContents handle
    let singlewords = words contents
        list = f singlewords    

    let sorted = heapsort list


    printf "Unsorted List:"
    print list
    printf "Sorted List:"
    start <- getCPUTime
    print sorted
    end <- getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)


    printf "Computation time: %0.9f sec\n" (diff :: Double)
    printf "Individual time: %0.9f sec\n" (diff / fromIntegral lim :: Double)
        list = f singlewords

    start <- getCPUTime
    let sorted = heapsort list
    end <- sorted `deepseq` getCPUTime
    let diff = (end - start) `div` (10^9)
    printf "%d\n" (diff :: Integer)
    hClose handle
