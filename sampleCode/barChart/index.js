const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

var width = canvas.clientWidth;
var height = canvas.clientHeight;

function makeText() {
  list.forEach((data, idx) => {
    const devide = idx / list.length;
    const len = wid / 2 - ctx.measureText(String(data) + "").width / 2;
    ctx.strokeText(
      data,
      position.min_x + position.max_x * devide + len,
      position.max_y + position.min_y / 2
    );
  });
}

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
    if (virtualVal[idx].data >= list[idx] && !complete) {
      comFlag--;
      virtualVal[idx] = {
        ...virtualVal[idx],
        complete: true,
      };
    }
    if (comFlag === 0) {
      clearInterval(interval);
      makeText();
    }
  });
}, 10);

function isInsideRect(x1, y1) {
  let result = false;
  let index = -1;
  let val = "";
  for (let i = 0; i < list.length; i++) {
    const data = list[i];
    const devide = i / list.length;
    const start_x = position.min_x + position.max_x * devide;
    const end_x = start_x + wid;
    const start_y = position.max_y * (1 - data / 100);
    const end_y = position.max_y;

    if (x1 >= start_x && x1 <= end_x && y1 >= start_y && y1 <= end_y) {
      result = true;
      index = i;
      val = data;
      break;
    }
  }
  return {
    result,
    index,
    val,
  };
}

function hoverDrawing(hoverIdx) {
  ctx.clearRect(0, 0, width, height);
  list.forEach((data, idx) => {
    ctx.save();
    if (idx === hoverIdx) {
      ctx.strokeStyle = "blue";
    }
    const devide = idx / list.length;
    ctx.strokeRect(
      position.min_x + position.max_x * devide,
      position.max_y * (1 - data / 100),
      wid,
      position.max_y - position.max_y * (1 - data / 100)
    );
    ctx.restore();
  });
  makeText();
}

function toolTipMaker(text, pos_x, pos_y, onOff) {
  console.log(pos_x, pos_y);
  var hover = document.getElementById("tooltip");
  if (!onOff) {
    hover.style.display = "none";
    hover.innerHTML = "";
  } else {
    hover.style.display = "block";
    hover.style.left = pos_x + pos_x * 0.02;
    hover.style.top = pos_y + pos_y * 0.02;
    hover.innerHTML = text;
  }
}

let drawed = false;
canvas.addEventListener("mousemove", function (event) {
  const x1 = event.clientX - canvas.offsetLeft;
  const y1 = event.clientY - canvas.offsetTop;
  const inn = isInsideRect(x1, y1);
  if (inn.result === true) {
    drawed = true;
    hoverDrawing(inn.index);
    toolTipMaker(inn.val, event.clientX, event.clientY, true);
    return;
  }
  if (drawed === true) {
    hoverDrawing(-1);
    toolTipMaker(0, 0, 0, false);
  }
});
