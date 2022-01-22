"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
exports.__esModule = true;
var Heap = /** @class */ (function () {
    function Heap() {
        this.heap = {};
        this.size = 1;
    }
    return Heap;
}());
var MaxHeap = /** @class */ (function (_super) {
    __extends(MaxHeap, _super);
    function MaxHeap() {
        return _super.call(this) || this;
    }
    MaxHeap.prototype.push = function (value) {
        this.heap[this.size] = value;
        var idx = this.size;
        while (this.heap[idx] > this.heap[Math.floor(idx / 2)]) {
            var pIdx = Math.floor(idx / 2);
            var currSpace = this.heap[idx];
            this.heap[idx] = this.heap[pIdx];
            this.heap[pIdx] = currSpace;
            idx = Math.floor(idx / 2);
        }
        this.size += 1;
    };
    MaxHeap.prototype.pop = function () {
        if (this.size === 1)
            return;
        this.size -= 1;
        this.heap[1] = this.heap[this.size];
        delete this.heap[this.size];
        var idx = 1;
        while (this.heap[idx * 2] > this.heap[idx] ||
            this.heap[idx * 2 + 1] > this.heap[idx]) {
            var currSpace = this.heap[idx];
            var left = idx * 2;
            var right = idx * 2 + 1;
            if (this.heap[left] < this.heap[right]) {
                this.heap[idx] = this.heap[right];
                this.heap[right] = currSpace;
                idx = right;
            }
            else {
                this.heap[idx] = this.heap[left];
                this.heap[left] = currSpace;
                idx = left;
            }
        }
    };
    MaxHeap.prototype.top = function () {
        return this.heap[1];
    };
    MaxHeap.prototype.length = function () {
        return this.size - 1;
    };
    return MaxHeap;
}(Heap));
var MinHeap = /** @class */ (function (_super) {
    __extends(MinHeap, _super);
    function MinHeap() {
        return _super.call(this) || this;
    }
    MinHeap.prototype.push = function (value) {
        this.heap[this.size] = value;
        var idx = this.size;
        while (this.heap[idx] < this.heap[Math.floor(idx / 2)]) {
            var pIdx = Math.floor(idx / 2);
            var currSpace = this.heap[idx];
            this.heap[idx] = this.heap[pIdx];
            this.heap[pIdx] = currSpace;
            idx = Math.floor(idx / 2);
        }
        this.size += 1;
    };
    MinHeap.prototype.pop = function () {
        if (this.size === 1)
            return;
        this.size -= 1;
        this.heap[1] = this.heap[this.size];
        delete this.heap[this.size];
        var idx = 1;
        while (this.heap[idx * 2] < this.heap[idx] ||
            this.heap[idx * 2 + 1] < this.heap[idx]) {
            var currSpace = this.heap[idx];
            var left = idx * 2;
            var right = idx * 2 + 1;
            if (this.heap[left] > this.heap[right]) {
                this.heap[idx] = this.heap[right];
                this.heap[right] = currSpace;
                idx = right;
            }
            else {
                this.heap[idx] = this.heap[left];
                this.heap[left] = currSpace;
                idx = left;
            }
        }
    };
    MinHeap.prototype.top = function () {
        return this.heap[1];
    };
    MinHeap.prototype.length = function () {
        return this.size - 1;
    };
    return MinHeap;
}(Heap));
function priorityQueueRun() {
    var minHeap = new MinHeap();
    minHeap.push("test2");
    minHeap.push("test3");
    minHeap.push("test7");
    minHeap.push("test3");
    minHeap.push("test4");
    console.log(minHeap.top());
    minHeap.pop();
    console.log(minHeap.top());
    minHeap.pop();
    console.log(minHeap.top());
    minHeap.pop();
    console.log(minHeap.top());
    minHeap.pop();
    console.log(minHeap.top());
    minHeap.pop();
    console.log();
    var maxHeap = new MaxHeap();
    maxHeap.push("test2");
    maxHeap.push("test3");
    maxHeap.push("test7");
    maxHeap.push("test3");
    maxHeap.push("test4");
    console.log(maxHeap.top());
    maxHeap.pop();
    console.log(maxHeap.top());
    maxHeap.pop();
    console.log(maxHeap.top());
    maxHeap.pop();
    console.log(maxHeap.top());
    maxHeap.pop();
    console.log(maxHeap.top());
}
exports["default"] = priorityQueueRun;
