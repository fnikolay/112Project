function radix(A,len){
  ListRef buckets[10];
  for(long i = 0; i < 10; i++){
    buckets[i] = newList();
  }

  long max = 0;
  long n = 1;
  long base = 10;
  long digit;

  for (long i = 1; i < len; i++) {
      if (A[i] > max)
        max = A[i];
  }

  while((max / n) > 0){
    for(long i = 0; i < len; i++){
      //printf("%ld ", A[i]);
      digit = A[i] % base;
      digit = digit/n;
      insertAfterLast(buckets[digit], A[i]);
    }

    long index = 0;
    for(long i = 0; i < 10; i++){
      if(!isEmpty(buckets[i])){
        while(!isEmpty(buckets[i])){
          A[index] = getFirst(buckets[i]);
          index++;
          deleteFirst(buckets[i]);
        }
      }
    }

    printf("\n");

    for(long i = 0; i < len; i++){
      printf("%ld ", A[i]);
    }
    printf("\n");
    base *= 10;
    n *= 10;
  }
  return 0;
}


if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split(/\s+/);
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}
mergeSort(array); // mergesort
for (var i = 0; i < array.length; ++i) {
  console.log(array[i]);
}
