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
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    DoublyLinkedList.prototype.push_front = function (value) {
        var newHead = new Node(value);
        if (this.head === null) {
            this.tail = newHead;
        }
        else {
            this.head.prev = newHead;
            newHead.next = this.head;
        }
        this.head = newHead;
        this.size++;
    };
    DoublyLinkedList.prototype.push_back = function (value) {
        var newTail = new Node(value);
        if (this.tail === null) {
            this.head = newTail;
        }
        else {
            this.tail.next = newTail;
            newTail.prev = this.tail;
        }
        this.tail = newTail;
        this.size++;
    };
    DoublyLinkedList.prototype.pop_front = function () {
        if (this.head === null)
            return;
        if (this.head.next === null) {
            this.tail = null;
        }
        else {
            this.head.next.prev = null;
            this.head = this.head.next;
        }
        this.size -= 1;
    };
    DoublyLinkedList.prototype.pop_back = function () {
        if (this.tail === null)
            return;
        if (this.tail.prev === null) {
            this.head = null;
        }
        else {
            this.tail.prev.next = null;
            this.tail = this.tail.prev;
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
        this.iterator(this.head, "asc");
    };
    DoublyLinkedList.prototype.display_descending = function () {
        this.iterator(this.tail, "desc");
    };
    return DoublyLinkedList;
}());
function doublyLinkedListRun() {
    var dll = new DoublyLinkedList();
    dll.push_front(1);
    dll.push_front(2);
    dll.push_back(3);
    dll.display_ascending();
    // dll.display_descending();
    dll.pop_back();
    dll.pop_front();
    dll.display_ascending();
}
exports["default"] = doublyLinkedListRun;
