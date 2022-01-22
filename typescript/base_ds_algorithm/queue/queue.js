"use strict";
exports.__esModule = true;
var Node = /** @class */ (function () {
    function Node(value) {
        this.value = value;
        this.link = null;
    }
    return Node;
}());
var Queue = /** @class */ (function () {
    function Queue() {
        this.front = null;
        this.rear = null;
        this.size = 0;
    }
    Queue.prototype.top = function () {
        return this.front ? this.front.value : null;
    };
    Queue.prototype.length = function () {
        return this.size;
    };
    Queue.prototype.push = function (val) {
        var newNode = new Node(val);
        if (this.front === null) {
            this.front = newNode;
            this.rear = newNode;
            this.size += 1;
            return;
        }
        this.rear.link = newNode;
        this.rear = newNode;
        this.size += 1;
    };
    Queue.prototype.pop = function () {
        if (!this.front)
            return;
        var curNode = this.front.link;
        this.front.link = null;
        this.front = curNode;
        if (this.front === null) {
            this.rear = null;
        }
        this.size -= 1;
    };
    Queue.prototype.isEmpty = function () {
        return this.front === null;
    };
    return Queue;
}());
function queueTest() {
    var q = new Queue();
    q.push(1);
    console.log(q);
    q.push(2);
    console.log(q);
    q.push(3);
    // console.log(q);
    // q.pop();
    // console.log(q);
    // q.pop();
    // console.log(q);
}
exports["default"] = queueTest;
