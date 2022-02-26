const test = {
  tmp: {
    test2: () => {
      console.log(this);
    },
  },
};

test.tmp.test2();
const t = test.tmp.test2;
t();
