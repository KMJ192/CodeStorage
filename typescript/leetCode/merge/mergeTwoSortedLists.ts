class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
      this.val = (val===undefined ? 0 : val)
      this.next = (next===undefined ? null : next)
  }
}

function mergeTwoLists(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  if(!l1 && !l2) return null;
  if(!l1) return l2;
  if(!l2) return l1;
  
  let q1: number[] = [];
  let q2: number[] = [];
  
  let next1: ListNode | null = l1;
  let next2: ListNode | null = l2;
  while (next1) {
      q1.push(next1.val);
      next1 = next1.next;
  }
  while (next2) {
      q2.push(next2.val);
      next2 = next2.next;
  }
  
  const q = [...q1, ...q2].sort((a: number, b: number): number => a - b);
  let node: ListNode = new ListNode(q[0]);
  let retHead = node;
  for(let i = 1; i < q.length; i++){
      node.next = new ListNode(q[i]);
      node = node.next;
  }
  
  return retHead;
};

export function mergeList(){
  
}