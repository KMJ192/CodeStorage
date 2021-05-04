"use strict";
exports.__esModule = true;
exports.buildTrie = void 0;
var Trie = /** @class */ (function () {
    function Trie() {
        this.root = {};
        this.end = "*";
    }
    Trie.prototype.insert = function (word) {
        var currentNode = this.root;
        for (var i = 0; i < word.length; i++) {
            !currentNode[word[i]] && (currentNode[word[i]] = {});
            currentNode = currentNode[word[i]];
        }
        currentNode[this.end] = true;
    };
    Trie.prototype.search = function (word) {
        var currentNode = this.root;
        for (var i = 0; i < word.length; i++) {
            if (!currentNode[word[i]])
                return false;
            currentNode = currentNode[word[i]];
            if (i === word.length - 1) {
                if (currentNode[this.end])
                    return true;
            }
        }
        return false;
    };
    Trie.prototype.startsWith = function (prefix) {
        var currentNode = this.root;
        for (var i = 0; i < prefix.length; i++) {
            if (!currentNode[prefix[i]])
                return false;
            currentNode = currentNode[prefix[i]];
        }
        return Object.keys(currentNode).length !== 0;
    };
    Trie.prototype.show = function () {
        return this.root;
    };
    return Trie;
}());
var buildTrie = function (words) {
    var dictionary = new Trie();
    for (var i = 0; i < words.length; i++) {
        dictionary.insert(words[i]);
    }
    dictionary.startsWith("appd");
    //console.log(dictionary.search("apple"));
};
exports.buildTrie = buildTrie;
