"use strict";
exports.__esModule = true;
var DoublyLinkedListNode = /** @class */ (function () {
    function DoublyLinkedListNode(value) {
        this.prev = null;
        this.value = value;
        this.next = null;
    }
    return DoublyLinkedListNode;
}());
//push_front, push_back, 
//pop_front, pop_back, 
//remove, 
//display_front, display_back
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    DoublyLinkedList.prototype.push_front = function (value) {
        var newHead = new DoublyLinkedListNode(value);
        if (this.head === null) {
            this.tail = newHead;
        }
        else {
            this.head.prev = newHead;
            newHead.next = this.head;
        }
        this.head = newHead;
        this.length++;
        return newHead;
    };
    DoublyLinkedList.prototype.push_back = function (value) {
        var newTail = new DoublyLinkedListNode(value);
        if (this.tail === null) {
            this.head = newTail;
        }
        else {
            this.tail.next = newTail;
            newTail.prev = this.tail;
        }
        this.tail = newTail;
        this.length++;
        return newTail;
    };
    DoublyLinkedList.prototype.pop_front = function () {
        if (this.head === null)
            return null;
        if (this.head.next === null) {
            this.tail = null;
        }
        else {
            this.head.next.prev = null;
            this.head = this.head.next;
        }
        if (this.length > 0)
            this.length--;
        return this.head;
    };
    DoublyLinkedList.prototype.pop_back = function () {
        if (this.tail === null)
            return null;
        if (this.tail.prev === null) {
            this.head = null;
        }
        else {
            this.tail.prev.next = null;
            this.tail = this.tail.prev;
        }
        if (this.length > 0)
            this.length--;
        return this.tail;
    };
    DoublyLinkedList.prototype.remove = function (node) {
        if (node.prev === null && node.next === null) {
            this.head = null;
            this.tail = null;
            this.length = 0;
            return node.value;
        }
        if (node.prev === null) {
            this.head = node.next;
            this.head.prev = null;
        }
        else {
            if (node.prev.next === null) {
                node.prev.next = null;
                this.tail = node.prev;
            }
            else {
                node.prev.next.next = node.prev.next;
                node.prev.next.prev = node.prev;
            }
        }
        if (this.length > 0)
            this.length--;
        return node.value;
    };
    return DoublyLinkedList;
}());
function runDoublyLinkedList() {
    var dll = new DoublyLinkedList();
    var testNode = new DoublyLinkedListNode(1);
    dll.push_front(1);
    console.log(dll);
    // dll.push_front(2);
    // dll.push_front(3);
    dll.remove(testNode);
    console.log(dll);
}
exports["default"] = runDoublyLinkedList;
