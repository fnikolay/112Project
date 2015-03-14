function heapify(array, root) {
    var left = (root === 0) ? 1 : 2 * root;
    var right = left + 1;
    var largest = (left < array.heapSize && array[left] > array[root]) ? left : root;
    var temp;


    if (right < array.heapSize && array[right] > array[largest])
        largest = right;

    if (largest !== root) {
        temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        heapify(array, largest);
    }
};

function buildHeap(array) {
    array.heapSize = array.length;
    for (var i = Math.round(array.length / 2); i >= 0; i--) {
        heapify(array, i);
    }
};

function heapSort(array) {
    buildHeap(array);
    var start = new Date().getTime();
    var temp;
    for (var i = array.length - 1; i >= 1; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        array.heapSize--;
        heapify(array, 0);
    }

    //for(j=0; j<array.length; j++){
        //console.log(array[j]);
    //}
};

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split("\n");
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}
var start = new Date().getTime() ;
heapSort(array, 0, array.length - 1); // heapsort
for (var i = 0; i < array.length; ++i) {
  console.log(array[i]);
}
var end = new Date().getTime();
console.log((end-start));