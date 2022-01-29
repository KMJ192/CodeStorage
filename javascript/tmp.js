const tmp = "1020000";

const pointer = {
  first: tmp.length - 3,
  second: tmp.length,
};

const test = [];
while (pointer.first > 0) {
  test.push(tmp.substring(pointer.first, pointer.second));
  pointer.second = pointer.first;
  pointer.first = pointer.first - 3;
}
test.push(tmp.substring(pointer.first, pointer.second));
console.log(test.reverse().join(","));
