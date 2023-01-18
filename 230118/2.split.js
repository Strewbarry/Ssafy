const a = "치킨|삼겹살|마라탕";
const array = a.split("|");
console.log(array);
// | 를 기준으로 a를 나누어서 배열로 저장한다.

for (let y = 0; y < array.length; y++) {
  console.log(array[y]);
}