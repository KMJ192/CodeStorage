class Node {
  isWord: string;
  next: any;
  constructor() {
    this.isWord = '';
    this.next = {};
  }
}

class Trie{
  private root: Node;
  private end: string;
  constructor() {
      this.root = new Node();
      this.end = '';
  }

  public insert(word: string) {
    let current = this.root;
    for(let i = 0; i < word.length; i++) {
      if(!current.next[word[i]]) current.next = new Node();
      current = current.next;
    }
  }

  public display() {
    this.recursion(this.root);
  }

  private recursion(currNode: Node) {
    console.log(Object.keys(currNode));
  }
}


export function TSRun() {
  let tr = new Trie();
  tr.insert("test1");
  tr.insert("sest2");
  console.log(tr);
  tr.display();
}