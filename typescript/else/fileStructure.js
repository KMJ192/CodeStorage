function printFileStructure(curNode, depth, output) {
    for (var _i = 0, _a = Object.entries(curNode); _i < _a.length; _i++) {
        var _b = _a[_i], key = _b[0], val = _b[1];
        output.push('   '.repeat(depth) + "--" + key);
        if (typeof curNode[key] === 'object') {
            printFileStructure(curNode[key], depth + 1, output);
        }
    }
}
function buildDictionary(path, currIdx, tree) {
    if (currIdx === path.length - 1) {
        tree[path[currIdx]] = true;
        return;
    }
    if (tree[path[currIdx]])
        tree[path[currIdx]] = {};
    buildDictionary(path, currIdx + 1, tree[path[currIdx]]);
}
function buildFileStructure(arrString) {
    if (!arrString.length)
        return;
    var tree = {};
    for (var _i = 0, arrString_1 = arrString; _i < arrString_1.length; _i++) {
        var path = arrString_1[_i];
        var filePath = path.split('/');
        buildDictionary(filePath, 0, tree);
    }
    var output = [];
    printFileStructure(tree, 0, output);
}
var input = ["app/index.html", "app/menu/viewController.js", "app/css/view.css", "app/menu/view.js", "app/menu/side.js"];
buildFileStructure(input);
