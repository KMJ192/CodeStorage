class Node {
  end = '';
  next = {};
  constructor() {
    this.end = '';
    this.next = {};
  }
}

class Trie {
  root;
  constructor() {
    this.root = new Node();
  }
  insert(word) {
    let currNode = this.root;
    console.log(currNode);
    for(let i = 0; i < word.length; i++) {
      let currChar = word[i];
      if(!currNode[currChar]) {
        currNode[currChar] = new Node();
      }
      console.log(currNode[currChar]);
      currNode = currNode[currChar];
    }
    
    currNode.end = word;
  }

  search(word) {
    let currNode = this.root;
    let outputString = [];

    for(let i = 0; i < word.length; i++){
      if(currNode[word[i]]){
        currNode = currNode[word[i]];
      }
    }

    outputString = this.recursion(currNode, outputString);

    if(this.root === currNode && word !== '') {
      return [];
    }

    return outputString;
  }

  recursion(currNode, outputString) {
    if(currNode.end !== '') {
      outputString.push(currNode.end);
    }

    let nowNode = Object.keys(currNode);
    if(nowNode.length > 2){
      for(let i = 0; i < nowNode.length; i++){
        if(nowNode[i] !== 'end' && nowNode[i] !== 'next') {
          this.recursion(currNode[nowNode[i]], outputString);
        }
      }
    }
    return outputString;
  }
}


function run() {
  let tr = new Trie();
  tr.insert("메뉴1");
  tr.insert("메뉴2");
  tr.insert("메뉴3");
  tr.insert("메뉴12");
  tr.insert("메뉴1234");
  tr.insert('test123');
  tr.insert('123sadd');
  let tmp = tr.search('메');

  console.log(tmp);
}
run();