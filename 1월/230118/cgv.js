
const title22 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong");
const per22 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span");
const day22 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > span.txt-info > strong");
// querySelector를 이용하여 데이터를 각각 원하는 변수명으로 저장
console.log(title22);
title22.textContent = "삼겹살과 그대라면";
console.log(per22);
per22.textContent = "11.5%";
console.log(day22);
day22.textContent = "1915.03.01"
// 변수명을 통해 qs를 호출하여 텍스트 내용을 각각 변경


const title3 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > a > strong");
const per3 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > div > strong > span");
const day3 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > span.txt-info > strong");

// let 을 이용하여 제목 바꿔치기 
let temp = title22.textContent;
title22.textContent = title3.textContent;
title3.textContent = temp;

// img src를 가져와서 바꿔치기하기 
const pic1 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img");
const pic3 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img");

let srctm = pic1.src;
pic1.src = pic3.src;
pic3.src = srctm;

