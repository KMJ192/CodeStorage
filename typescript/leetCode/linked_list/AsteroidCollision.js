"use strict";
exports.__esModule = true;
exports.AsteroidCollision = void 0;
var DoublyLinkedListNode = /** @class */ (function () {
    function DoublyLinkedListNode(value) {
        this.prev = null;
        this.value = value;
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
    DoublyLinkedList.prototype.len = function () {
        return this.length;
    };
    DoublyLinkedList.prototype.get = function (i) {
        if (i > this.length)
            return undefined;
        var curData = this.head;
        for (var n = 0; n < i; n++) {
            if (curData)
                curData = curData === null || curData === void 0 ? void 0 : curData.next;
        }
        return curData === null || curData === void 0 ? void 0 : curData.value;
    };
    DoublyLinkedList.prototype.getNode = function (i) {
        if (i > this.length)
            return null;
        var curData = this.head;
        for (var n = 0; n < i; n++) {
            if (curData)
                curData = curData === null || curData === void 0 ? void 0 : curData.next;
        }
        return curData;
    };
    DoublyLinkedList.prototype.display = function () {
        if (this.length === 0)
            return;
        var curNode = this.head;
        while (curNode === null || curNode === void 0 ? void 0 : curNode.next) {
            console.log(curNode.value);
            curNode = curNode.next;
        }
        console.log(curNode === null || curNode === void 0 ? void 0 : curNode.value);
    };
    //             1      2      3     4      5
    //this.head => node => node   =>   node => node => this.tail
    //                          \    ⁄
    //                           node
    DoublyLinkedList.prototype.remove = function (i) {
        if (this.length === 0)
            return null;
        var index = 0;
        var thisList = this;
        while (index < i) {
            if (i === index) {
                thisList;
            }
            index++;
        }
        return this;
    };
    return DoublyLinkedList;
}());
// function asteroidCollision(asteroids: number[]): number[] {
//   //base case
//   if(asteroids.length === 0) return [];
//   if(asteroids.length === 1) return asteroids;
//   if(asteroids.length === 2){
//     if(asteroids[0] + asteroids[1] === 0) return [];
//     if(asteroids[0] > 0 && asteroids[1] > 0) return asteroids;
//     if(asteroids[0] < 0 && asteroids[1] < 0) return asteroids;
//     if(asteroids[0] < asteroids[1]) return [asteroids[0]];
//     if(asteroids[0] > asteroids[1]) return [asteroids[1]];
//   }
//   let answer: number[] = [];
//   let dll = new DoublyLinkedList<number>();
//   for(let i = 0; i < asteroids.length; i++){
//     dll.push_back(asteroids[i]);
//   }
//   //이전 원소가 양수이고 현재 원소가 음수이면 만남
//   // let pointer = 0;
//   // let prev: number = 0;
//   // while(pointer < dll.len()){
//   //   if(pointer === 0){
//   //     const val = dll.get(0);
//   //     if(val) prev = val;
//   //     else return [];
//   //   }else{
//   //     //이전값과 현재값 비교한다.
//   //     const now = dll.get(pointer);
//   //     if(now && prev > 0 && now < 0){
//   //       //충돌 조건
//   //       pointer = 0;
//   //     }
//   //   }
//   //   pointer++;
//   // }
//   return answer;
// }
var Stack = /** @class */ (function () {
    function Stack() {
        this.value = [];
        this.length = 0;
    }
    Stack.prototype.push = function (val) {
        this.value.push(val);
        this.length++;
    };
    Stack.prototype.pop = function () {
        this.value.pop();
        this.length--;
    };
    Stack.prototype.len = function () {
        return this.length;
    };
    Stack.prototype.top = function () {
        return this.value[this.value.length - 1];
    };
    Stack.prototype.get = function () {
        return this.value;
    };
    return Stack;
}());
//stack
function asteroidCollision(asteroids) {
    //base case
    if (asteroids.length === 0)
        return [];
    if (asteroids.length === 1)
        return asteroids;
    if (asteroids.length === 2) {
        if (asteroids[0] + asteroids[1] === 0)
            return [];
        if (asteroids[0] > 0 && asteroids[1] > 0)
            return asteroids;
        if (asteroids[0] < 0 && asteroids[1] < 0)
            return asteroids;
        if (asteroids[0] < asteroids[1])
            return [asteroids[0]];
        if (asteroids[0] > asteroids[1])
            return [asteroids[1]];
    }
    //이전 원소가 양수이고 현재 원소가 음수이면 만남
    var s = new Stack();
    for (var i = 0; i < asteroids.length; i++) {
        var curr = asteroids[i];
        if (curr > 0)
            s.push(curr);
        else {
            console.log(s.get());
            while (s.len() && s.top() > 0 && s.top() < Math.abs(curr)) {
                s.pop();
            }
            if (s.len() && s.top() === Math.abs(curr))
                s.pop();
            else if (!s.len() || s.top() < 0)
                s.push(curr);
        }
    }
    return s.get();
}
function AsteroidCollision() {
    //let result = asteroidCollision([-2,-1,1,2]);
    var result = asteroidCollision([10, 2, -11]);
    console.log(result);
}
exports.AsteroidCollision = AsteroidCollision;
//stack
