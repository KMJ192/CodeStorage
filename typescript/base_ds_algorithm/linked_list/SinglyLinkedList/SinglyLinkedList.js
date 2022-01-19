"use strict";
exports.__esModule = true;
var Node = /** @class */ (function () {
    function Node(value) {
        this.value = value;
        this.next = null;
    }
    return Node;
}());
var SinglyLinkedList = /** @class */ (function () {
    function SinglyLinkedList() {
        this.tail = null;
        this.size = 0;
    }
    SinglyLinkedList.prototype.top = function () {
        return this.tail ? this.tail.value : null;
    };
    SinglyLinkedList.prototype.length = function () {
        return this.size;
    };
    SinglyLinkedList.prototype.push = function (val) {
        var newNode = new Node(val);
        if (this.tail) {
            var curNode = this.tail;
            this.tail = newNode;
            this.tail.next = curNode;
            this.size += 1;
            return;
        }
        this.tail = newNode;
        this.size += 1;
    };
    SinglyLinkedList.prototype.pop = function () {
        if (!this.tail)
            return;
        var curNode = this.tail.next;
        this.tail = null;
        this.tail = curNode;
        this.size -= 1;
    };
    return SinglyLinkedList;
}());
function singlyLinkedList() {
    var ssl = new SinglyLinkedList();
    ssl.push(1);
    ssl.push(2);
    console.log(ssl);
    ssl.pop();
    ssl.pop();
    console.log(ssl);
}
exports["default"] = singlyLinkedList;
