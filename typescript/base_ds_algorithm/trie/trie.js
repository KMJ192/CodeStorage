"use strict";
exports.__esModule = true;
exports.TSRun = void 0;
var Node = /** @class */ (function () {
    function Node() {
        this.isWord = '';
        this.next = {};
    }
    return Node;
}());
var Trie = /** @class */ (function () {
    function Trie() {
        this.root = new Node();
        this.end = '';
    }
    Trie.prototype.insert = function (word) {
        var current = this.root;
        for (var i = 0; i < word.length; i++) {
            if (!current.next[word[i]])
                current.next = new Node();
            current = current.next;
        }
    };
    Trie.prototype.display = function () {
        this.recursion(this.root);
    };
    Trie.prototype.recursion = function (currNode) {
        console.log(Object.keys(currNode));
    };
    return Trie;
}());
function TSRun() {
    var tr = new Trie();
    tr.insert("test1");
    tr.insert("sest2");
    console.log(tr);
    tr.display();
}
exports.TSRun = TSRun;
