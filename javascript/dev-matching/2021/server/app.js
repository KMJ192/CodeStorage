// import { cors } from "cors";
// import express from "express";
// import { productList } from "./template/data";

const cors = require("cors");
const express = require("express");
const {
  productList,
  productOption1,
  productOption2,
  productOption3,
  productOption4,
  productOption5,
  productOption6,
  productOption7,
  productOption8,
  productOption9,
  productOption10,
  productOption11,
  productOption12,
} = require("./template/data");

const app = express();
const port = 3001;

app.use(cors());
app.use("/images", express.static("images"));

app.get("/", (req, res) =>
  res.send(
    "2021 하반기 프론트엔드 dev-matching 커피캣 스토어 spa문제 풀이 연습용 서버"
  )
);
app.get("/product-list", (req, res) => res.send(productList));

app.listen(port);
