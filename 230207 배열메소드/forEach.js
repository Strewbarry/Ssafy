// // 배열 메소드 array.함수(콜백함수)
// // addEventListener('click',function() {})

// // Array.forEach

// const arr = [1,2,3,4];
// arr.forEach((value) => {
//   console.log(value);
// })

// const test = (value) => {console.log(value)};
// arr.forEach(test);



// // 홀수만 카운트 하기
// const aryy = [4,3,5,1,6,5,];
// let cnt=0;
// aryy.forEach(li => {
//   if(li%2 ==1) cnt++;
// })
// console.log(cnt);


// // 음수 양수 구분하기
// const arr4 = [-5,3,4,2,-7,-2,7];
// const pplus=[];
// const mmius=[];
// arr4.forEach(li => {
//   if(li<0)
//     mmius.push(li);  //mmius 배열 끝자리에 li 요소를 추가
//   else
//     pplus.push(li);
// })
// console.log(pplus);
// console.log(mmius);



//forEach 는 값을 리턴하지 않는다.
const array = [1,2,3,4,5];
//some >> 하나의 조건만 만족해도 true 반환
const result1 = array.some(element => element<0);   //false
const result2 = array.some(element => element>4);   //true


//every >> 모든 조건을 만족해야 true 반환
const everes1 = array.every(element => element>0);  //true
const everes2 = array.every(element => element>3);  //false

