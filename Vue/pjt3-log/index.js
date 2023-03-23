// 로그의 레벨
// error, warn ,info, http, verbose, debug, silly
// error, warn ,info, debug 를 자주 쓴다.

// error -> 에러 기록
// warn -> 에러는 아니지만 유의할 내용
// info -> 내용
// debug -> 상세한 데이터들 

// 이렇게 레벨별로 나누어 보여주는 것이 winston 


const express = require('express');
const morgan = require('morgan');
const logger = require('./utils/log');
const app = express();
const PORT = 8080;

app.use(morgan('dev'));

app.get("/api/logs", (req,res) => {
  logger.error("error 메세지");
  logger.warn("warn 메세지");
  logger.info("info 메세지");
  logger.debug("debug 메세지");
  return res.json({
    test : "OK"
  })
})

app.listen(PORT, () => console.log(`${PORT} 서버 가동중`))