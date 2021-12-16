class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function build() {
  const obj = new Map<number, number>();

  function recursion(node: ListNode) {
    const value = obj.get(node.val);
    if (value !== undefined) obj.set(node.val, value + 1);
    else obj.set(node.val, 1);
    if (node.next === null) return;
    recursion(node.next);
  }
  return {
    obj,
    recursion,
  };
}

function mergeTwoLists(
  list1: ListNode | null,
  list2: ListNode | null
): ListNode | null {
  if (list1 === null && list2 === null) return null;
  let answer = new ListNode();
  let tmp = new ListNode();

  tmp = answer;

  const { obj, recursion } = build();
  if (list1) recursion(list1);
  if (list2) recursion(list2);

  Object.keys(obj).forEach((data: Object) => {
    const key = Number(data);
    const cnt = obj.get(key);
    if (cnt) {
      for (let i = 0; i < cnt; i++) {
        tmp.next = new ListNode(key);
        tmp = tmp.next;
      }
    }
  });
  if (answer.next) answer = answer.next;
  console.log(answer);

  display(answer);

  return answer;
}

function display(node: ListNode) {
  if (node.next === null) return;
  display(node.next);
}

function mergeTwoSortedList() {
  const list1 = new ListNode(-9, new ListNode(3));
  const list2 = new ListNode(5, new ListNode(7));
  mergeTwoLists(list1, list2);
}

export default mergeTwoSortedList;
