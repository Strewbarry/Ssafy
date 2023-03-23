// winston -> node의 대표적인 로그 라이브러리 
// winston-daily-rotate-file -> 로그 관리 라이브러리 
const winston = require('winston');
const { format } = winston;
// winston.format.combine;
const {combine} = format;

// winston-daily-rotate-file은 별도의 호출 없이 사용하므로 실행선언만 진행해주면된다.
require('winston-daily-rotate-file');


const transport = new winston.transports.DailyRotateFile({
  level : 'info',
  // 저장할 파일 이름 정보
  filename: "./log.js/%DATE%.log",
  // 날짜 형식
  datePattern:"YYYY-MM-DD-HH",
  zippedArchive: true,
  // 파일의 최대 크기
  maxSize : "20m",
  // 보관할 최대 로그 수 (1d 는 하루단위로 저장한다는 의미) 
  maxFiles : "1d"
})

const logger = winston.createLogger({
  transports:[transport]
})

module.exports = logger;