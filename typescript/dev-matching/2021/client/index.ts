import React from "./react";
import App from "@src/App";
import debounceFrame from "./debounceFrame/debounceFrame";
import "./style.css";

const { render, useState } = React();

const root = document.getElementById("App");

function Count() {
  const [count, setCount] = useState<number>(1);
  const [cat, setCat] = useState<string>("야옹");

  window.increament = () => multiCnt(count + 1);
  window.decreament = () => {
    if (count > 0) multiCnt(count - 1);
  };
  const multiCnt = (cnt: number) => {
    setCount(cnt);
    setCat("야옹".repeat(cnt));
  };

  return `
    <div>
      <button onclick="increament()">증가</button>      
      <button onclick="decreament()">감소</button>
      <strong>count: ${count}</strong>
    </div>
  `;
}
render(Count, root);

//cd typescript/dev-matching/2021
