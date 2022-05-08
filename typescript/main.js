"use strict";
exports.__esModule = true;
// import async from "./syntax/async";
// import mixinTest from "./base_syntax/mixin/mixin";
var hangulExtract_1 = require("./hangulExtract/hangulExtract");
// import { buildTrie } from "./base_ds_algorithm/trie/trie";
function main() {
    (0, hangulExtract_1.hangulExtract)();
    // buildTrie();
}
main();
