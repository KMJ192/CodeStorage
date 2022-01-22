"use strict";
exports.__esModule = true;
var Node = /** @class */ (function () {
    function Node(value) {
        this.prev = null;
        this.value = value;
        this.next = null;
    }
    return Node;
}());
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.front = null;
        this.rear = null;
        this.size = 0;
    }
    DoublyLinkedList.prototype.push_front = function (value) {
        var newNode = new Node(value);
        if (this.front === null) {
            this.rear = newNode;
        }
        else {
            this.front.prev = newNode;
            newNode.next = this.front;
        }
        this.front = newNode;
        this.size++;
    };
    DoublyLinkedList.prototype.push_back = function (value) {
        var newNode = new Node(value);
        if (this.rear === null) {
            this.front = newNode;
        }
        else {
            this.rear.next = newNode;
            newNode.prev = this.rear;
        }
        this.rear = newNode;
        this.size++;
    };
    DoublyLinkedList.prototype.pop_front = function () {
        if (this.front === null)
            return;
        if (this.front.next === null) {
            this.front = null;
            this.rear = null;
        }
        else {
            this.front.next.prev = null;
            this.front = this.front.next;
        }
        this.size -= 1;
    };
    DoublyLinkedList.prototype.pop_back = function () {
        if (this.rear === null)
            return;
        if (this.rear.prev === null) {
            this.front = null;
            this.rear = null;
        }
        else {
            this.rear.prev.next = null;
            this.rear = this.rear.prev;
        }
        this.size -= 1;
    };
    DoublyLinkedList.prototype.length = function () {
        return this.size;
    };
    DoublyLinkedList.prototype.iterator = function (node, type) {
        console.log(node.value);
        if (type === "asc" && node.next) {
            this.iterator(node.next, type);
        }
        if (type === "desc" && node.prev) {
            this.iterator(node.prev, type);
        }
    };
    DoublyLinkedList.prototype.display_ascending = function () {
        this.iterator(this.front, "asc");
    };
    DoublyLinkedList.prototype.display_descending = function () {
        this.iterator(this.rear, "desc");
    };
    return DoublyLinkedList;
}());
function doublyLinkedListRun() {
    var dll = new DoublyLinkedList();
    dll.push_front(1);
    dll.push_front(2);
    dll.push_back(3);
    dll.pop_front();
    dll.pop_front();
    dll.pop_front();
    console.log(dll);
}
exports["default"] = doublyLinkedListRun;
