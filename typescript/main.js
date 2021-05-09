"use strict";
exports.__esModule = true;
//import { buildTrie } from './leetCode/trie/trie';
//import WordSearchII from './leetCode/trie/WordSearchII/WordSearchII';
var ValidParentheses_1 = require("./leetCode/stack/ValidParentheses");
function main() {
    //buildTrie(["apple", "cat", "dog", "boat", "plane", "bottle", "note", "compiler"]);
    //WordSearchII();
    console.log(ValidParentheses_1.isValid("{{)()}}"));
}
main();
