CC= ghc -O2

alli : radixsort quicksort mergesort heapsort

radixsort: radixsort.hs
	$(CC) -o radixsort radixsort.hs

quicksort : quicksort.hs
	$(CC) -o quicksort quicksort.hs

mergesort : mergesort.hs
	$(CC) -o mergesort mergesort.hs

heapsort : heapsort.hs
	$(CC) -o heapsort heapsort.hs

clean :
	rm -rf *.o *.hi

spotless : clean
	rm radixsort
	rm quicksort
	rm mergesort
	rm heapsort
