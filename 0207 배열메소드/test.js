const abc = {
  name : "치킨",
  type : "후라이드"
}

const { name , type } = abc;
console.log(name);
console.log(type);


// js 도 함수에서 배열을 return 할 수 있다.
const samlefunc = () =>{
  return [1,2];
}
const [one,two] = samlefunc();
console.log(one);   //1
console.log(two);   //2



const square = {
  width : 200,
  height : 200,
};
const colorSqare = {
  // ... 을통해 위에 있는 square 객체를 가져다가 포장을 푼다
  // width 와 height 가 colorsqare의 요소가 된다. 
  ...square,
  color:"red",
};
console.log(colorsqare);

