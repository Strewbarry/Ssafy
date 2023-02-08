const datas = [1,2,3,4,5];

//acc = accelator = 누산기 (누적합산값)
// acc는 초기값인 1에서 시작하여 cur과 합산한다 
// cur은 datas의 0번 index인 1에서 시작한다.
const accResult = datas.reduce((acc,cur) => {
  console.log(acc,cur);
  return acc + cur;
// 1 은 누산의 초기값 , 생략가능
// 초기값을 생략한다면 index 0번을 초기값으로 잡고 
// cur을 index 1번에서 시작하여 누산을 진행한다 
}, 1);

console.log(accResult);