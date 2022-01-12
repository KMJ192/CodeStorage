"use strict";
exports.__esModule = true;
var Node = /** @class */ (function () {
    function Node(value) {
        this.value = value;
        this.link = null;
    }
    return Node;
}());
var Stack = /** @class */ (function () {
    function Stack() {
        this.tail = null;
        this.size = 0;
    }
    Stack.prototype.top = function () {
        return this.tail ? this.tail.value : null;
    };
    Stack.prototype.length = function () {
        return this.size;
    };
    Stack.prototype.push = function (val) {
        var newNode = new Node(val);
        if (this.tail) {
            var curNode = this.tail;
            this.tail = newNode;
            this.tail.link = curNode;
            return;
        }
        this.tail = newNode;
        this.size += 1;
    };
    Stack.prototype.pop = function () {
        if (!this.tail)
            return;
        var curNode = this.tail.link;
        this.tail = null;
        this.tail = curNode;
        this.size -= 1;
    };
    return Stack;
}());
function stackRun() {
    var s = new Stack();
    s.push(1);
    console.log(s.top());
    s.push(2);
    console.log(s.top());
    s.pop();
    console.log(s.top());
    s.pop();
    console.log(s.top());
    var t = new Stack();
    t.push("test1");
    console.log(t.top());
    t.push("test2");
    console.log(t.top());
    t.pop();
    console.log(t.top());
    t.pop();
    console.log(t.top());
}
exports["default"] = stackRun;
