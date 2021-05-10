"use strict";
exports.__esModule = true;
//import { buildTrie } from './leetCode/trie/trie';
//import WordSearchII from './leetCode/trie/WordSearchII/WordSearchII';
//import { isValid } from "./leetCode/stack/ValidParentheses";
var TaskScheduler_1 = require("./leetCode/queue/TaskScheduler");
function main() {
    //buildTrie(["apple", "cat", "dog", "boat", "plane", "bottle", "note", "compiler"]);
    //WordSearchII();
    //console.log(isValid("{{)()}}"));
    TaskScheduler_1.leastInterval(['A', 'A', 'A', 'B', 'B', 'B'], 2);
}
main();
