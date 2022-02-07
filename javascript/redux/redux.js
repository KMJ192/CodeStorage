function test() {}

const test2 = {
  test1: () => {
    console.log("test1");
  },
  test2: () => {
    console.log("test2");
  },
};

// console.log(typeof test);
// console.log(typeof test2);
const tmp = Object.keys(test2).map((value) => test2[value]);
tmp[0]();
tmp[1]();
