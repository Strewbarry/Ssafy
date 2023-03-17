const express = require("express");
const app = express();
const cors = require("cors");
const morgan = require("morgan");
const axios = require("axios");
const PORT = 8081;
const fs = require("fs");

const dotenv = require("dotenv");

dotenv.config();

app.use(express.json());
app.use(morgan("dev"));
app.use(cors());

// dotenv에 작성한 내용 가져오는법
app.get("/", (req, res) => {
  console.log(process.env.CLIENT_ID);
  console.log(process.env.CLIENT_SECRET);
  return res.json({ test: "HELLO" });
});

// 파일을 읽어서 리턴
app.get("/api/data", (req, res) => {
  try{
    fs.readFile('./uploads/chart.json','utf8',(error,data) => {
      if(error) {
        console.log(error);
      }
      return res.json(JSON.parse(data));
    })
  }catch(error){
    console.log(error);
    return res.json(error);
  }

});

// 요청을 보내고 값을 파일로 저장하는 역할
app.post("/api/data", async (req, res) => {
  const url = "https://openapi.naver.com/v1/datalab/search";
  const headers = {
    "X-Naver-Client-Id": process.env.CLIENT_ID,
    "X-Naver-Client-Secret": process.env.CLIENT_SECRET,
    "Content-Type": "application/json",
  };
  const request_body = {
    startDate: req.body.startDate,
    endDate: req.body.endDate,
    timeUnit: req.body.timeUnit,
    keywordGroups: req.body.keywordGroups,
    // [
    //   {
    //     groupName: "치킨",
    //     keywords: [
    //       "치킨",
    //       "BBQ", "BHC"
    //     ]
    //   },
    //   {
    //     groupName: "삼겹살",
    //     keywords: [
    //       "삼겹살",
    //       "고기"
    //     ]
    //   }
    // ]
  };
  try {
    const result = await axios.post(url, request_body, {
      headers: headers,
    });
    console.log(result);
    fs.writeFile("./uploads/chart.json",JSON.stringify(result.data.results), function(err){
      console.log(err);
    })
    return res.json(result.data.results);
  } catch (error) {
    console.log(error);
    return res.json(error);
  }
});

// 파일 삭제
app.delete("/api/data", (req, res) => {});

app.listen(PORT, () => console.log(`${PORT} 서버 기동중`));
