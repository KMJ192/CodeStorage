"use strict";
exports.__esModule = true;
exports.run = void 0;
var DoublyLinkedListNode = /** @class */ (function () {
    function DoublyLinkedListNode(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
    return DoublyLinkedListNode;
}());
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
            this.head.next = this.head.prev;
            this.head.prev = newHead;
        }
        this.length++;
        return newHead;
    };
    DoublyLinkedList.prototype.push_back = function (value) {
        var newTail = new DoublyLinkedListNode(value);
        if (this.tail === null) {
            this.head = newTail;
        }
        else {
            this.tail.prev = this.tail.next;
            this.tail.next = newTail;
        }
        this.length++;
        return newTail;
    };
    DoublyLinkedList.prototype.pop_front = function () {
        if (this.length > 0)
            this.length--;
        if (this.head === null) {
            console.log(this);
        }
        else {
            if (this.head.next === null) {
                this.tail = null;
            }
            else {
            }
        }
    };
    DoublyLinkedList.prototype.pop_back = function () {
        if (this.length > 0)
            this.length--;
    };
    DoublyLinkedList.prototype.remove = function () {
        if (this.length > 0)
            this.length--;
    };
    return DoublyLinkedList;
}());
var LRUCache = /** @class */ (function () {
    function LRUCache(capacity) {
    }
    LRUCache.prototype.get = function (key) {
        return 1;
    };
    LRUCache.prototype.put = function (key, value) {
    };
    return LRUCache;
}());
function run() {
    // let test = new DoublyLinkedListNode<number>(1);
    // let test2 = new DoublyLinkedListNode<number>(2);
    // let test3 = new DoublyLinkedListNode<number>(3);
    // test.next = test2;
    // test.prev = test3;
    // console.log(test);
    var test = new DoublyLinkedList();
    test.push_front(1);
    test.push_front(2);
    test.pop_front();
    //test.push_back(2);
    //console.log(test);
}
exports.run = run;
