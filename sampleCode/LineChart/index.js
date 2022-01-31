const XAXIS_PADDING = 50;
const YAXIS_PADDIGN = 50;
const TOP_PADDING = 20;
const RIGHT_PADDING = 60;
const DURATION = 1000 * 30;
const X_MAX_VALUE = 100;
const Y_MAX_VALUE = 100;
const X_TICK_COUNT = 100;
const Y_TICK_COUNT = 10;
const X_TICK_SIZE = 10;
const Y_TICK_SIZE = 10;

class LineChart {
  constructor(id) {
    this.canvas = document.getElementById(id);
    this.ctx = this.canvas.getContext("2d");

    this.ctx.font = "normal bold 12px serif";
    this.canvas.style.width = "100%";

    // this.canvasWidth = this.canvas.clientWidth;
    // this.canvasHeight = this.canvas.clientHeight;
    this.canvasWidth = 1900;
    this.canvasHeight = 700;

    this.chartWidth = this.canvasWidth - YAXIS_PADDIGN;
    this.chartHeight = this.canvasHeight - XAXIS_PADDING - TOP_PADDING;

    this.drawChart();
  }
  setTime = () => {};

  drawChart = () => {
    const { ctx, canvasWidth, canvasHeight, chartWidth, chartHeight } = this;

    ctx.save();
    ctx.beginPath();

    // draw YAXIS
    ctx.textAlign = "right";
    ctx.moveTo(YAXIS_PADDIGN, TOP_PADDING);
    ctx.lineTo(YAXIS_PADDIGN, chartHeight + TOP_PADDING);
    const yInterval = Y_MAX_VALUE / Y_TICK_COUNT;
    let maxWidth = 0;
    for (let i = 0; i <= Y_TICK_COUNT; i++) {
      const value = Math.floor(i * yInterval);
      const yPoint =
        TOP_PADDING + chartHeight - (value / Y_MAX_VALUE) * chartHeight;
      ctx.moveTo(YAXIS_PADDIGN, yPoint);
      ctx.lineTo(YAXIS_PADDIGN - Y_TICK_SIZE, yPoint);
      ctx.fillText(value, YAXIS_PADDIGN / 2, yPoint + 4);
      maxWidth = Math.max(ctx.measureText(value));
    }

    // draw XAXIS
    ctx.moveTo(YAXIS_PADDIGN, chartHeight + TOP_PADDING);
    ctx.lineTo(canvasWidth - RIGHT_PADDING, chartHeight + TOP_PADDING);
    const xInterval = X_MAX_VALUE / X_TICK_COUNT;
    for (let i = 1; i <= X_TICK_COUNT; i++) {
      const value = Math.floor(i * xInterval);
      const xPoint =
        YAXIS_PADDIGN + (value / X_MAX_VALUE) * chartWidth - RIGHT_PADDING;
      const tickPos = xPoint - ctx.measureText(value).width / 2;
      ctx.moveTo(tickPos, chartHeight + TOP_PADDING);
      ctx.lineTo(tickPos, chartHeight + TOP_PADDING + X_TICK_SIZE);
      ctx.fillText(
        value,
        xPoint,
        chartHeight + TOP_PADDING + YAXIS_PADDIGN / 2
      );
    }

    ctx.stroke();
    ctx.restore();
  };

  updateData = () => {};
}

document.addEventListener("DOMContentLoaded", () => {
  new LineChart("line-chart");
});
