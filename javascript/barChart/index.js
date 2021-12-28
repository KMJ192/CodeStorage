const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

var width = canvas.clientWidth;
var height = canvas.clientHeight;

var position = {
  min_x: width * 0.1,
  max_x: width * 0.9,
  max_y: height * 0.9,
  min_y: height * 0.1,
};

const list = [90, 50, 60];

var wid = 50;
ctx.save();
//시작, 시작, 넓이, 높이

// 시작점 x는 position에서 옆으로 띄울 최소값
// 시작점 y는 최대높이값에서 비율을 곱해서 나온 값
// 사각형의 넓이는 wid 값으로 고정
// 사각형의 높이는 최대 높이에서 비율을 곱해나온 값을 빼 준 값
// list.forEach((value, idx) => {
//   const devide = idx / list.length;
//   ctx.strokeRect(
//     position.min_x + position.max_x * devide,
//     position.max_y * (1 - value / 100),
//     wid,
//     position.max_y - position.max_y * (1 - value / 100)
//   );
// });

const virtualVal = [
  {
    data: 1,
    complete: false,
  },
  {
    data: 1,
    complete: false,
  },
  {
    data: 1,
    complete: false,
  },
];
let comFlag = virtualVal.length;
const interval = setInterval(() => {
  ctx.clearRect(0, 0, width, height);
  virtualVal.forEach((value, idx) => {
    const { data, complete } = value;
    if (list[idx] > data) {
      const devide = idx / list.length;
      const tmp = data + 1;
      virtualVal[idx] = {
        ...virtualVal[idx],
        data: tmp,
      };
      ctx.strokeRect(
        position.min_x + position.max_x * devide,
        position.max_y * (1 - tmp / 100),
        wid,
        position.max_y - position.max_y * (1 - tmp / 100)
      );
    } else {
      const devide = idx / list.length;
      ctx.strokeRect(
        position.min_x + position.max_x * devide,
        position.max_y * (1 - data / 100),
        wid,
        position.max_y - position.max_y * (1 - data / 100)
      );
    }
    if (virtualVal[idx].data > list[idx] && !complete) {
      comFlag--;
      virtualVal[idx] = {
        ...virtualVal[idx],
        complete: true,
      };
    }
    if (comFlag === 0) {
      clearInterval(interval);
    }
  });
}, 10);
