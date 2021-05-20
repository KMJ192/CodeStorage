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
    //list의 front에 data 삽입
    DoublyLinkedList.prototype.push_front = function (value) {
        var newHead = new DoublyLinkedListNode(value);
        if (this.head === null) {
            //tail이 새로운 노드를 가리킨다.
            this.tail = newHead;
        }
        else {
            //첫번째 노드의 prev와 newHead.next연결
            this.head.prev = newHead;
            newHead.next = this.head;
        }
        this.head = newHead;
        this.length++;
        return newHead;
    };
    //list의 back에 data 삽입
    DoublyLinkedList.prototype.push_back = function (value) {
        var newTail = new DoublyLinkedListNode(value);
        if (this.tail === null) {
            //head에 새로운 노드를 가리킨다
            this.head = newTail;
        }
        else {
            //마지막 노드의 next와 newtail.prev를 연결
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
            this.head = this.head.next.prev;
            this.head.next = null;
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
            this.tail.next = null;
            this.tail = this.tail.prev.next;
        }
        console.log(this);
        if (this.length > 0)
            this.length--;
        return this.tail;
    };
    DoublyLinkedList.prototype.remove = function () {
        if (this.length > 0)
            this.length--;
    };
    return DoublyLinkedList;
}());
function runDoublyLinkedList() {
    var dll = new DoublyLinkedList();
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    console.log(dll);
    dll.pop_back();
    // dll.pop_back();
    // dll.pop_back();
    //console.log(dll);
}
exports["default"] = runDoublyLinkedList;
