"use strict";
exports.__esModule = true;
var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
    return ListNode;
}());
function build() {
    var obj = new Map();
    function recursion(node) {
        var value = obj.get(node.val);
        if (value !== undefined)
            obj.set(node.val, value + 1);
        else
            obj.set(node.val, 1);
        if (node.next === null)
            return;
        recursion(node.next);
    }
    return {
        obj: obj,
        recursion: recursion
    };
}
function mergeTwoLists(list1, list2) {
    if (list1 === null && list2 === null)
        return null;
    var answer = new ListNode();
    var tmp = new ListNode();
    tmp = answer;
    var _a = build(), obj = _a.obj, recursion = _a.recursion;
    if (list1)
        recursion(list1);
    if (list2)
        recursion(list2);
    Object.keys(obj).forEach(function (data) {
        var key = Number(data);
        var cnt = obj.get(key);
        if (cnt) {
            for (var i = 0; i < cnt; i++) {
                tmp.next = new ListNode(key);
                tmp = tmp.next;
            }
        }
    });
    if (answer.next)
        answer = answer.next;
    console.log(answer);
    display(answer);
    return answer;
}
function display(node) {
    if (node.next === null)
        return;
    display(node.next);
}
function mergeTwoSortedList() {
    var list1 = new ListNode(-9, new ListNode(3));
    var list2 = new ListNode(5, new ListNode(7));
    mergeTwoLists(list1, list2);
}
exports["default"] = mergeTwoSortedList;
