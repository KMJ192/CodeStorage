class Trie{
    private root : Object;
    private end : string;
    constructor() {
        this.root = {};
        this.end = "*";
    }
    public insert(word : string){
        let currentNode : Object = this.root;
        for(let i = 0; i < word.length; i++) {
            !currentNode[word[i]] && ( currentNode[word[i]] = {} );
            currentNode = currentNode[word[i]];
        }
        currentNode[this.end] = true;
    }
    public search(word : string) : boolean{
        let currentNode : Object = this.root;
        for(let i = 0; i < word.length; i++) {
            if(!currentNode[word[i]]) return false;
            currentNode = currentNode[word[i]];

            if(i === word.length - 1){
                if(currentNode[this.end]) return true;
            }
        }
        return false;
    }
    public startsWith(prefix : string) : boolean{
        let currentNode : Object = this.root;
        for(let i = 0; i < prefix.length; i++) {
            if(!currentNode[prefix[i]]) return false;
            currentNode = currentNode[prefix[i]];
        }
        return Object.keys(currentNode).length !== 0;
    }
    public show(){
        return this.root;
    }
}

export const buildTrie = (words : Array<string>) => {
    const dictionary = new Trie();
    for(let i = 0; i < words.length; i++){
        dictionary.insert(words[i]);
    }
    console.log(dictionary.startsWith("app"));
    console.log(dictionary.search("apple"));
}