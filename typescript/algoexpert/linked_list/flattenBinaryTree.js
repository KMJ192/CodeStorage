"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
exports.__esModule = true;
exports.flattenBinaryTree = void 0;
var Node = /** @class */ (function () {
    function Node(value, prev, next) {
        this.value = value;
        this.prev = prev || null;
        this.next = next || null;
    }
    return Node;
}());
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.table = {};
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    DoublyLinkedList.prototype.insert = function (param) {
        var _a;
        var object = param.object, pos = param.pushPosition, value = param.value;
        var _b = this, table = _b.table, head = _b.head, tail = _b.tail;
        var key = String(value);
        var obj = String(object);
        var newNode = new Node(value, null, null);
        var o = table[obj];
        // key | value table에 node할당
        this.table = __assign(__assign({}, table), (_a = {}, _a[key] = newNode, _a));
        // 최초입력, parameter로 position이 "first"가 아니라도, this.length === 0 일때 최초할당
        if (pos === "first" || this.length === 0) {
            if (this.length > 0)
                return;
            this.head = newNode;
            this.tail = newNode;
            this.length++;
            return;
        }
        // 대상 node(o)의 prev에 새로운 노드 할당
        if (pos === "front" && o) {
            if (head === o) {
                // 대상 노드가 head일 경우 head를 새로운 노드로 교체
                this.head = newNode;
            }
            else if (o.prev) {
                // 새로운 노드의 prev와 대상 노드prev의 next가 서로 가리키도록 설정
                newNode.prev = o.prev;
                o.prev.next = newNode;
            }
            // 대상 노드의 prev와 새로운 노드의 next가 서로 가리키도록 설정
            o.prev = newNode;
            newNode.next = o;
        }
        // 대상 node(o)의 next에 새로운 노드 할당
        if (pos === "back" && o) {
            if (tail === o) {
                // 대상 노드가 tail일 경우 tail을 새로운 노드로 교체
                this.tail = newNode;
            }
            else if (o.next) {
                // 새로운 노드의 next와 대상 노드next의 prev가 서로 가리키도록 설정
                newNode.next = o.next;
                o.next.prev = newNode;
            }
            // 대상 노드의 next와 새로운 노드의 prev가 서로 가리키도록 설정
            o.next = newNode;
            newNode.prev = o;
        }
        // DoublyLinkedList 길이를 증가시켜두기
        this.length++;
    };
    DoublyLinkedList.prototype.display = function () {
        this.head && this.curDisplay(this.head);
    };
    DoublyLinkedList.prototype.curDisplay = function (node) {
        console.log(node.value);
        if (node.next)
            this.curDisplay(node.next);
    };
    return DoublyLinkedList;
}());
var TreeNode = /** @class */ (function () {
    function TreeNode(value, l, r) {
        this.value = value;
        this.left = l;
        this.right = r;
    }
    return TreeNode;
}());
// FlattenBinaryTree문제 풀이
function solution(tree) {
    var ll = new DoublyLinkedList();
    var value = tree.value;
    var param = {
        pushPosition: "first",
        value: value
    };
    // DoublyLinkedList에 최초 값 할당
    ll.insert(param);
    recursion(tree, ll);
    // 결과 출력
    ll.display();
}
function recursion(node, ll) {
    if (node.left) {
        var value = node.value, left = node.left;
        var param = {
            object: value,
            pushPosition: "front",
            value: left.value
        };
        ll.insert(param);
        recursion(left, ll);
    }
    if (node.right) {
        var value = node.value, right = node.right;
        var param = {
            object: value,
            pushPosition: "back",
            value: right.value
        };
        ll.insert(param);
        recursion(right, ll);
    }
}
function flattenBinaryTree() {
    var tree = new TreeNode(1, new TreeNode(2, new TreeNode(2, null, null), new TreeNode(2, new TreeNode(2, null, null), new TreeNode(2, null, null))), new TreeNode(2, new TreeNode(2, null, null), null));
    solution(tree);
}
exports.flattenBinaryTree = flattenBinaryTree;
