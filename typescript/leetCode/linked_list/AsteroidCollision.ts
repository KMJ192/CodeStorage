class DoublyLinkedListNode<T>{
  public value : T;
  public prev : DoublyLinkedListNode<T> | null;
  public next : DoublyLinkedListNode<T> | null;
  constructor(value : T) {
      this.prev = null;
      this.value = value;
      this.next = null;
  }
}

class DoublyLinkedList<T>{
  private head : DoublyLinkedListNode<T> | null;
  private tail : DoublyLinkedListNode<T> | null;
  private length : number;
  constructor(){
      this.head = null;
      this.tail = null;
      this.length = 0;
  }

  public push_front(value : T) : DoublyLinkedListNode<T> {
      const newHead = new DoublyLinkedListNode<T>(value);
      if(this.head === null){
          this.tail = newHead;
      }else{
          this.head.prev = newHead;
          newHead.next = this.head;
      }
      this.head = newHead;
      this.length++;
      return newHead;
  }
  
  public push_back(value : T) : DoublyLinkedListNode<T>{
      let newTail = new DoublyLinkedListNode<T>(value);
      if(this.tail === null){
          this.head = newTail;
      }else{
          this.tail.next = newTail;
          newTail.prev = this.tail;
      }

      this.tail = newTail;
      this.length++;
      return newTail;
  }

  public pop_front() : DoublyLinkedListNode<T> | null{
      if(this.head === null) return null;

      if(this.head.next === null){
          this.tail = null;
      }else{
          this.head.next.prev = null;
          this.head = this.head.next
      }
      if(this.length > 0) this.length--;
      return this.head;
  }

  public pop_back(){
      if(this.tail === null) return null;
      
      if(this.tail.prev === null){
          this.head = null;
      }else{
          this.tail.prev.next = null;
          this.tail = this.tail.prev;
      }
      if(this.length > 0) this.length--;
      return this.tail;
  }

  public len(): number{
    return this.length;
  }

  public get(i: number): T | undefined{
    if(i > this.length) return undefined;
    let curData: DoublyLinkedListNode<T> | null = this.head;
    for(let n = 0; n < i; n++){
      if(curData) curData = curData?.next;
    }
    return curData?.value;
  }

  public getNode(i: number): DoublyLinkedListNode<T> | null{
    if(i > this.length) return null;
    let curData: DoublyLinkedListNode<T> | null = this.head;

    for(let n = 0; n < i; n++){
      if(curData) curData = curData?.next;
    }
    
    return curData;
  }

  public display(){
    if(this.length === 0) return;
    let curNode: DoublyLinkedListNode<T> | null = this.head;
    while(curNode?.next){
      console.log(curNode.value);
      curNode = curNode.next;
    }
    console.log(curNode?.value);
  }
  //             1      2      3     4      5
//this.head => node => node   =>   node => node => this.tail
//                          \    ⁄
//                           node
  public remove(i: number): DoublyLinkedList<T> | null | undefined{
    if(this.length === 0) return null;
    let index = 0;
    let thisList = this;

    while(index < i){
      if(i === index){
        thisList
      }

      index++;
    }
    return this;
  }
}

// function asteroidCollision(asteroids: number[]): number[] {
//   //base case
//   if(asteroids.length === 0) return [];
//   if(asteroids.length === 1) return asteroids;
//   if(asteroids.length === 2){
//     if(asteroids[0] + asteroids[1] === 0) return [];
//     if(asteroids[0] > 0 && asteroids[1] > 0) return asteroids;
//     if(asteroids[0] < 0 && asteroids[1] < 0) return asteroids;
//     if(asteroids[0] < asteroids[1]) return [asteroids[0]];
//     if(asteroids[0] > asteroids[1]) return [asteroids[1]];
//   }

//   let answer: number[] = [];
//   let dll = new DoublyLinkedList<number>();

//   for(let i = 0; i < asteroids.length; i++){
//     dll.push_back(asteroids[i]);
//   }

//   //이전 원소가 양수이고 현재 원소가 음수이면 만남
//   // let pointer = 0;
//   // let prev: number = 0;
//   // while(pointer < dll.len()){
//   //   if(pointer === 0){
//   //     const val = dll.get(0);
//   //     if(val) prev = val;
//   //     else return [];
//   //   }else{
//   //     //이전값과 현재값 비교한다.
//   //     const now = dll.get(pointer);
//   //     if(now && prev > 0 && now < 0){
//   //       //충돌 조건

//   //       pointer = 0;
//   //     }
//   //   }
//   //   pointer++;
//   // }

//   return answer;
// }

class Stack<T>{
  private value: T[] = [];
  private length: number = 0;

  public push(val: T){
    this.value.push(val);
    this.length++;
  }

  public pop(){
    this.value.pop();
    this.length--;
  }

  public len(): number{
    return this.length;
  }

  public top(): T{
    return this.value[this.value.length - 1];
  }

  public get(): T[]{
    return this.value;
  }
}

//stack
function asteroidCollision(asteroids: number[]): number[] {
  //base case
  if(asteroids.length === 0) return [];
  if(asteroids.length === 1) return asteroids;
  if(asteroids.length === 2){
    if(asteroids[0] + asteroids[1] === 0) return [];
    if(asteroids[0] > 0 && asteroids[1] > 0) return asteroids;
    if(asteroids[0] < 0 && asteroids[1] < 0) return asteroids;
    if(asteroids[0] < asteroids[1]) return [asteroids[0]];
    if(asteroids[0] > asteroids[1]) return [asteroids[1]];
  }

  //이전 원소가 양수이고 현재 원소가 음수이면 만남
  let s = new Stack<number>();
  for(let i = 0; i <asteroids.length; i++){
    const curr = asteroids[i];
    if(curr > 0) s.push(curr);
    else{
      while(s.len() && s.top() > 0 && s.top() < Math.abs(curr)){
        s.pop();
      }
      if(s.len() && s.top() === Math.abs(curr)) s.pop();
      else if(!s.len() || s.top() < 0) s.push(curr);
    }
  }
  return s.get();
}

export function AsteroidCollision(){
  //let result = asteroidCollision([-2,-1,1,2]);
  let result = asteroidCollision([10,2,-11]);
  console.log(result);
}