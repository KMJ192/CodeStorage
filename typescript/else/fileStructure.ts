function printFileStructure(curNode: any, depth: number, output: string[]) {
  for(let [key, val] of Object.entries(curNode)) {
    output.push(`${'   '.repeat(depth)}--${key}`);
    if(typeof curNode[key] === 'object') {
      printFileStructure(curNode[key], depth + 1, output);
    }
  }
}

function buildDictionary(path: string[], currIdx: number, tree: any) {
  if(currIdx === path.length - 1) {
    tree[path[currIdx]] = true;
    return;
  }
  if(tree[path[currIdx]]) tree[path[currIdx]] = {};
  buildDictionary(path, currIdx+1, tree[path[currIdx]]);
}

function buildFileStructure(arrString: string[]) {
  if(!arrString.length) return;

  const tree: any = {};
  for(const path of arrString) {
    const filePath = path.split('/');
    buildDictionary(filePath, 0, tree);
  }
  let output: string[] = [];
  printFileStructure(tree, 0, output);
}



const input: string[] = ["app/index.html", "app/menu/viewController.js", "app/css/view.css", "app/menu/view.js", "app/menu/side.js"];
buildFileStructure(input);