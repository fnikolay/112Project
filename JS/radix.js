function radix(A){
  var buckets = [[],[],[],[],[],[],[],[],[],[]];
  var max = 0;
  var n = 1;
  var base = 10;
  var digit = 0;

  for (var i = 1; i < A.length; i++) {
      if (A[i] > max){max = A[i];}
  }

  while((max / n) > 0){
    for(var i = 0; i < A.length; i++){
      digit = A[i] % base;
      //console.log(digit);
      digit = Math.floor(digit / n);
      //console.log(digit);
      //console.log(buckets[digit]);
      buckets[digit].push(A[i]);
    }

    var index = 0;
    for(var i = 0; i < 10; i++){
      if(buckets[i].length != 0){
        while(buckets[i].length != 0){
          A[index] = buckets[i].shift();
          index++;
        }
      }
    }
    base *= 10;
    n *= 10;
  }
  return A;
}

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs');
var array = fs.readFileSync(process.argv[2]).toString().split(/\s+/);

for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}

var start = new Date().getTime() ;
radix(array); // mergesort
var end = new Date().getTime();
console.log(((end-start)/1000));
