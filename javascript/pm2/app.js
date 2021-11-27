const express = require("express");
const app = express();
const port = 3000;
let isDisableKeepAlive = false;
app.use((req, res, next) => {
  if (isDisableKeepAlive) {
    res.set("Connection", "close");
  }
  next();
});
app.get("/", (req, res) => {
  res.send("pm2 test");
});
app.listen(port, () => {
  process.send("ready");
  console.log("ready");
});
process.on("SIGINT", () => {
  isDisableKeepAlive = true;
  app.close(() => {
    console.log("server closed");
    process.exit(0);
  });
});
