//sort each side and then merge together
function mergeSort(array, side, leng) {
  //if the length is greater than 2
  if (leng >= 2){
    var mid = Math.floor(leng / 2);
    var left = side.slice(0, mid);
    var right = side.slice(mid);
    //perform merge sort on the first half of the numbers
    mergeSort(left, array.slice(0, mid), mid);
    //perform merge on the second half of the numbers
    mergeSort(right, array.slice(mid), leng - mid);
    //merge the two lists in the correct order
    merge(array,left, right);
    return array;
  }else{
    return;
  }
};

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

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split(/\s+/);
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}
var start = new Date().getTime() ;
<<<<<<< HEAD
mergeSort(array); // mergesort

//console.log(array);
for (var i = 0; i < array.length; ++i) {
  console.log(array[i]);
}
var end = new Date().getTime();
console.log(((end-start)));
=======
mergeSort(array, array.slice(), array.length - 1); // mergesort
var end = new Date().getTime();
console.log(end - start);
//console.log(array);
>>>>>>> FETCH_HEAD
