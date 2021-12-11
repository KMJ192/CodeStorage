import { createDom, createElement, render } from "./src/react";
// const vDom = {
//   tag: "p",
//   props: {},
//   children: [
//     {
//       tag: "h1",
//       props: {},
//       children: ["react"],
//     },
//     {
//       tag: "ul",
//       props: {},
//       children: [
//         {
//           tag: "li",
//           props: {
//             style: "color:red",
//           },
//           children: ["first"],
//         },
//         {
//           tag: "li",
//           props: {
//             style: "color:blud",
//           },
//           children: ["second"],
//         },
//         {
//           tag: "li",
//           props: {
//             style: "color:green",
//           },
//           children: ["third"],
//         },
//       ],
//     },
//   ],
// };

// const vDom = createElement("p", {}, [
//   createElement("h1", {}, ["react"]),
//   createElement("ul", {}, [
//     createElement("li", { style: "color:red" }, ["first"]),
//     createElement("li", { style: "color:red" }, ["second"]),
//     createElement("li", { style: "color:red" }, ["third"]),
//   ]),
// ]);

/* @jsx createElement */
const vDom = (
  <p>
    <h1>React</h1>
    <ul>
      <li style="color: red">first</li>
      <li style="color: blue">second</li>
      <li style="color: green">third</li>
    </ul>
  </p>
);

console.log(vDom);

render(vDom, document.querySelector("#root"));
