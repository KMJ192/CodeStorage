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
        this.head = null;
        this.size = 0;
    }
    Queue.prototype.top = function () {
        return this.head ? this.head.value : null;
    };
    Queue.prototype.length = function () {
        return this.size;
    };
    Queue.prototype.push = function (val) {
        var newNode = new Node(val);
        if (this.head) {
            var curNode = this.head.link;
            newNode.link = curNode;
            this.head.link = newNode;
            return;
        }
        this.head = newNode;
        this.size += 1;
    };
    Queue.prototype.pop = function () {
        if (!this.head)
            return;
        var curNode = this.head.link;
        this.head.link = null;
        this.head = curNode;
        this.size -= 1;
    };
    return Queue;
}());
function queueTest() {
    var q = new Queue();
    q.push(1);
    console.log(q.top()); // 1
    q.push(2);
    console.log(q.top()); // 1
    q.pop();
    console.log(q.top()); // 2
    q.push(3);
    console.log(q.top()); // 2
    q.pop();
    console.log(q.top()); // 3
    var sq = new Queue();
    sq.push("test");
    console.log(sq.top());
    sq.push("test2");
    console.log(sq.top());
    sq.pop();
    console.log(sq.top());
    sq.pop();
    console.log(sq.top());
}
exports["default"] = queueTest;
