function exchange(array, i, j) {
    var temp = array[i];
    array[i] = array[j];
    array[j] = temp;
};

function maxHeapify(array, root) {
    var left = (root === 0) ? 1 : 2 * root,
        right = left + 1,
        largest = (left < array.heapSize && array[left] > array[root])
            ? left : root;

    if (right < array.heapSize && array[right] > array[largest])
        largest = right;

    if (largest !== root) {
        exchange(array, root, largest);
        maxHeapify(array, largest);
    }
};

function buildMaxHeap(array) {
    array.heapSize = array.length;
    for (var i = Math.round(array.length / 2); i >= 0; i--) {
        maxHeapify(array, i);
        //update(array);
    }
};

function heapSort(array) {
    buildMaxHeap(array);
    var start = new Date().getTime() ;
    //console.log(start);
    for (var i = array.length - 1; i >= 1; i--) {
        exchange(array, 0, i);
        array.heapSize--;
        maxHeapify(array, 0);
        //update(array);
    }
    //var end = new Date().getTime();
    //console.log(end);
    //console.log(end-start);

};

if (process.argv.length != 3) {
  process.exit(0);
}
var fs = require('fs'); // Read values from file
var array = fs.readFileSync(process.argv[2]).toString().split("\n");
for (var i = 0; i < array.length; ++i) {
  array[i] = parseInt(array[i]);
}
var start = new Date().getTime();
heapSort(array, 0, array.length - 1);
var end = new Date().getTime();
console.log(end - start);

