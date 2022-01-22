"use strict";
exports.__esModule = true;
var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
    return ListNode;
}());
var List = /** @class */ (function () {
    function List() {
        this.front = null;
        this.rear = null;
    }
    List.prototype.push = function (value) {
        var newNode = new ListNode(value);
        if (this.front === null) {
            this.front = newNode;
            this.rear = newNode;
            return;
        }
        this.rear.next = newNode;
        this.rear = newNode;
    };
    return List;
}());
var Solution = /** @class */ (function () {
    function Solution(l1, l2) {
        this.l1 = l1;
        this.l2 = l2;
        this.curNode = null;
    }
    Solution.prototype.recursive = function (l1, l2, q, mod) {
        if (!l1 && !l2) {
            if (mod)
                q.push(mod);
            return;
        }
        var l1Val = 0, l2Val = 0;
        if (l1)
            l1Val = l1.val;
        if (l2)
            l2Val = l2.val;
        var value = l1Val + l2Val + mod;
        mod = 0;
        if (value >= 10) {
            mod = Number(String(value).substring(0, 1));
            value = Number(String(value).substring(1));
        }
        q.push(value);
        if (l1 && l2) {
            this.recursive(l1.next, l2.next, q, mod);
            return;
        }
        if (!l1 && l2) {
            this.recursive(null, l2.next, q, mod);
            return;
        }
        if (l1 && !l2) {
            this.recursive(l1.next, null, q, mod);
            return;
        }
    };
    Solution.prototype.run = function () {
        var q = new List();
        this.recursive(this.l1, this.l2, q, 0);
        return q.front;
    };
    return Solution;
}());
function addTwoNumbers(l1, l2) {
    return new Solution(l1, l2).run();
}
function run() {
    var l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    var l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    console.log(addTwoNumbers(l1, l2));
}
exports["default"] = run;
