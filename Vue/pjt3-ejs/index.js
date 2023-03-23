const express = require("express");
const morgan = require("morgan");
const axios = require("axios");
const app = express();
const PORT = 8080;

app.use(morgan("dev"));

// 템플릿 엔진으로 ejs 사용
app.set("view engine", "ejs");
// 해당 ejs에서 활용할 경로를 ./views 폴더로 설정
app.set("views", "./views");

app.get("/", (req, res) => {
  // ejs에서 화면을 그리는 방식
  // index.ejs를 그린다.
  res.render("index", { name: "성연" });
});

app.get("/holder", async (req, res) => {
  const result = await axios.get(`https://jsonplaceholder.typicode.com/todos/`);
  
  res.render("holder-list", {data: result.data});
});

// axios로 jsonplaceholder 요청 -> 데이터 그려보기
app.get("/holder/id", async (req, res) => {
  const result = await axios.get(`https://jsonplaceholder.typicode.com/todos/${req.params.id}`);
  // console.log(result);
  res.render("holder", { data: result.data });
});

app.listen(PORT, () => console.log(`${PORT} 서버 구동중`));
