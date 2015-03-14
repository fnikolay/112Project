//Mergesort Implementation
function merge(array, left, right) {
  var a = 0;
  while (left.length && right.length){
    if (right[0] < left[0]) {
      array[a++] = right.shift();
    } 
    else {
      array[a++] = left.shift();
    }
  }
  while (left.length){
    array[a++] = left.shift();
  }
  while (right.length){
    array[a++] = right.shift();
  }
};

function mSort(array, temp, leng) {
  if (leng == 1){
    return;
  }
  var m = Math.floor(leng / 2),
  left = temp.slice(0, m),
  right = temp.slice(m);
  mSort(left, array.slice(0, m), m);
  mSort(right, array.slice(m), leng - m);
  merge(array,left, right);
  return array
};

function mergeSort(array) {

  var sorted = mSort(array, array.slice(), array.length);

  return sorted;
};

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split(/\s+/);
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}

var start = new Date().getTime() ;
mergeSort(array); // mergesort

//console.log(array);
for (var i = 0; i < array.length; ++i) {
  console.log(array[i]);
}
var end = new Date().getTime();
console.log(((end-start)));