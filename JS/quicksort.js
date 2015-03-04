/******************************************
CMPS 112 Javascript Quicksort Implementation
Ryan Fulscher rfulsche@ucsc.edu
Requires Node.js
******************************************/

var swap = function(array, i, j) {
  var temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

var partition = function(array, low, high) {
  var pivI, pivVal, tempI;
  pivI = Math.floor((high + low)/2); // Median of Three pivot
  pivVal = array[pivI];
  swap(array, pivI, high);
  tempI = low;
  for (var i = low; i < high; ++i) {
    if (array[i] < pivVal) {
      swap(array, i, tempI);
      ++tempI;
    }
  }
  swap(array, tempI, high);
  return tempI;
}

var sort = function(array, low, high) {
  if (low < high) {
    var pivI = partition(array, low, high);
    sort(array, low, pivI - 1);
    sort(array, pivI + 1, high);
  }
}

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split("\n");
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}
sort(array, 0, array.length - 1); // Quicksort
for (var i = 0; i < array.length; ++i) {
  console.log(array[i]);
}
