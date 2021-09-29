"use strict";
exports.__esModule = true;
exports.buildTrie = void 0;
var TrieNode = /** @class */ (function () {
    function TrieNode() {
        this.isWord = false;
        this.next = {};
    }
    return TrieNode;
}());
var TrieDataStructure = /** @class */ (function () {
    function TrieDataStructure() {
        this.root = new TrieNode();
    }
    TrieDataStructure.prototype.insert = function (word) {
        var curNode = this.root;
        for (var i = 0; i < word.length; i++) {
            var c = word[i];
            !curNode.next[c] && (curNode.next[c] = new TrieNode());
            curNode = curNode.next[c];
        }
        curNode.isWord = true;
    };
    TrieDataStructure.prototype.search = function (word) {
        var curNode = this.root;
        for (var i = 0; i < word.length; i++) {
            var c = word.charAt(i);
            curNode = curNode.next[word.charAt(i)];
            if (!curNode)
                return false;
        }
        return curNode.isWord;
    };
    TrieDataStructure.prototype.startsWith = function (prefix) {
        var curNode = this.root;
        for (var i = 0; i < prefix.length; i++) {
            curNode = curNode.next[prefix.charAt(i)];
            if (!curNode)
                return false;
        }
        return true;
    };
    return TrieDataStructure;
}());
var buildTrie = function () {
    var trie = new TrieDataStructure();
    trie.insert("abcd");
    console.log(trie.search("b"));
};
exports.buildTrie = buildTrie;
