import express from "express";

import { TodoList } from "./src/components.js";
import { render } from "./src/render.js";

const app = express();

app.get("/", (req, res) => {
  res.send(render(TodoList()));
});

app.listen(3000, () => {
  console.log("listen to http://localhost:3000");
});
