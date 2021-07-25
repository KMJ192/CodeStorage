"use strict";
exports.__esModule = true;
exports.josephus = void 0;
var Node = /** @class */ (function () {
    function Node(value) {
        this.val = value;
        this.prev = null;
        this.next = null;
    }
    return Node;
}());
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }
    DoublyLinkedList.prototype.push_back = function (val) {
        var newTail = new Node(val);
        if (this.tail) {
            this.tail.next = newTail;
            newTail.prev = this.tail;
        }
        else {
            this.head = newTail;
        }
        this.tail = newTail;
        this.length++;
    };
    DoublyLinkedList.prototype.len = function () {
        return this.length;
    };
    return DoublyLinkedList;
}());
function solution(n, k) {
    var dll = new DoublyLinkedList();
    for (var i = 0; i < n; i++) {
        dll.push_back(i);
    }
    //dll.head = dll.tail;
}
function josephus() {
    var n = 7;
    var k = 3;
    solution(n, k);
}
exports.josephus = josephus;
