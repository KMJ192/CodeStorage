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
        this.front = null;
        this.rear = null;
        this.size = 0;
    }
    SinglyLinkedList.prototype.top = function () {
        return this.front ? this.front.value : null;
    };
    SinglyLinkedList.prototype.bottom = function () {
        return this.rear ? this.rear.value : null;
    };
    SinglyLinkedList.prototype.length = function () {
        return this.size;
    };
    SinglyLinkedList.prototype.push = function (val) {
        var newNode = new Node(val);
        if (this.front === null) {
            this.front = newNode;
            this.rear = newNode;
            this.size += 1;
            return;
        }
        this.rear.next = newNode;
        this.rear = newNode;
        this.size += 1;
    };
    SinglyLinkedList.prototype.pop = function () {
        if (!this.front)
            return;
        var curNode = this.front.next;
        this.front.next = null;
        this.front = curNode;
        if (this.front === null) {
            this.rear = null;
        }
        this.size -= 1;
    };
    SinglyLinkedList.prototype.iterator = function (node) {
        if (node) {
            console.log(node.value);
            if (node.next)
                this.iterator(node.next);
        }
    };
    SinglyLinkedList.prototype.display = function () {
        this.iterator(this.front);
    };
    return SinglyLinkedList;
}());
function singlyLinkedList() {
    var ssl = new SinglyLinkedList();
    ssl.push(1);
    ssl.display();
    ssl.push(2);
    ssl.push(3);
    ssl.display();
    ssl.pop();
    ssl.display();
}
exports["default"] = singlyLinkedList;
