function minHeap() {
    this.priorityQueue = [];
   }
    
   minHeap.prototype.state = function () {
    return this.priorityQueue;
   };
    
   minHeap.prototype.size = function () {
    return this.priorityQueue.length;
   };
    
   minHeap.prototype.peak = function () {
    return !this.priorityQueue[0]
      ? console.log("no element")
      : this.priorityQueue[0];
   };
    
   minHeap.prototype.heapifyDown = function (index) {
    while (this.priorityQueue[2 * index + 1]) {
      let left = 2 * index + 1;
      let right = 2 * index + 2;
    
      let smallerChild = left;
      if (
        this.priorityQueue[right] &&
        this.priorityQueue[right] < this.priorityQueue[left]
      ) {
        smallerChild = right;
      }
    
      if (this.priorityQueue[index] < this.priorityQueue[smallerChild]) {
        break;
      } else {
        [this.priorityQueue[index], this.priorityQueue[smallerChild]] = [
          this.priorityQueue[smallerChild],
          this.priorityQueue[index],
        ];
      }
      index = smallerChild;
    }
   };
    
   minHeap.prototype.heapifyUp = function (index) {
    let parent = Math.floor((index - 2) / 2);
    while (index > 0 && this.priorityQueue[parent] > this.priorityQueue[index]) {
      [this.priorityQueue[parent], this.priorityQueue[index]] = [
        this.priorityQueue[index],
        this.priorityQueue[parent],
      ];
      index = parent;
      parent = Math.floor((index - 1) / 2);
    }
   };
    
   minHeap.prototype.insert = function (val) {
    this.priorityQueue.push(val);
    this.heapifyUp(this.priorityQueue.length - 1);
   };
    
   minHeap.prototype.removeMin = function () {
    const min = this.priorityQueue[0];
    const len = this.priorityQueue.length;
    [this.priorityQueue[0], this.priorityQueue[len - 1]] = [
      this.priorityQueue[len - 1],
      this.priorityQueue[0],
    ];
    this.priorityQueue.pop();
    //O(logn)
    this.heapifyDown(0);
    return min;
   };
    
   let newMinHeap = new minHeap();