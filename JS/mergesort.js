//Mergesort Implementation

function merge(array, left, right) {
  var i = 0;

  while (left.length != 0 && right.length != 0){
    if (right[0] < left[0]) {
      array[i++] = right.shift();
    } 
    else {
      array[i++] = left.shift();
    }
  }
  while (left.length != 0){
    array[i++] = left.shift();
  }
  while (right.length != 0){
    array[i++] = right.shift();
  }
};

//sort each side and then merge together
function mergeSort(array, side, leng) {
  if (leng == 1){
    return;
  }
  var mid = Math.floor(leng / 2);
  var left = side.slice(0, mid);
  var right = side.slice(mid);
  //perform merge sort on the first half of the numbers
  mergeSort(left, array.slice(0, mid), mid);
  //perform merge on the second half of the numbers
  mergeSort(right, array.slice(mid), leng - mid);
  //merge the two lists in the correct order
  merge(array,left, right);
  return array
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
mergeSort(array, array.slice(), array.length); // mergesort
var end = new Date().getTime();
console.log("Time: "((end-start)/1000));