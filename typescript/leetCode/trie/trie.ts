class TrieNode {
  public isWord: boolean;
  public word: string;
  public next: {
    [key: string]: TrieNode;
  };
  constructor() {
    this.isWord = false;
    this.next = {};
    this.word = "";
  }
}

class TrieDataStructure {
  private root: TrieNode;
  constructor() {
    this.root = new TrieNode();
  }

  public insert(word: string) {
    let curNode: TrieNode = this.root;
    for (let i: number = 0; i < word.length; i++) {
      const c: string = word[i];
      !curNode.next[c] && (curNode.next[c] = new TrieNode());
      curNode = curNode.next[c];
    }
    curNode.word = word;
    curNode.isWord = true;
  }
  public search(word: string): boolean {
    let curNode: TrieNode = this.root;
    for (let i: number = 0; i < word.length; i++) {
      curNode = curNode.next[word.charAt(i)];
      if (!curNode) return false;
    }
    return curNode.isWord;
  }

  public startsWith(prefix: string): boolean {
    let curNode = this.root;
    for (let i: number = 0; i < prefix.length; i++) {
      curNode = curNode.next[prefix.charAt(i)];
      if (!curNode) return false;
    }
    return true;
  }
}

export const buildTrie = () => {
  let trie = new TrieDataStructure();
  trie.insert("abcd");
  console.log(trie.search("b"));
};
