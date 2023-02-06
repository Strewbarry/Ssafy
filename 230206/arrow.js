
//함수 표현식 
const a = function(){
  console.log("aa");
}

// 화살표 함수
// 함수의 이름 없이 작성한다 (무명 메소드)
// 위의 함수와 같은 역할을 하지만 1줄로 표현이 가능하다
const b = () => {console.log("bb")};
const c = () => console.log("bb");



// 아래의 두 코드는 같은 역할을 하지만 
//{} 를 생략한다면 return을 생략하기 때문에 코드가 짧아져 가독성이 올라간다
const sum = (a,b) => { return a+b};
sum (3,4);

const sum2 = (a,b) => a+b;
sum2(3,4);
// 같은 원리로 곱셈도 가능
const multi = (a) => a*a;



//백틱  ` `
// 문자열과 자바스크립트의 혼합 ok
const myName = "이성연";
const intruduce = "제 이름은 " + myName + "입니다";
const intruduce2 = `제 이름은 ${myName} 입니다`;

// 백틱은 enter를 허용한다
const hello2 = `
안녕하세요
저는
치킨입니다
`;        //'\n안녕하세요\n저는\n치킨입니다\n'  << 출력결과 


// 태그도 넣을 수 있다
const aa =`
<div class="a">
안녕하세요
</div>
`
// 화살표 함수까지 연결하여 부분부분 개발할 수 있는 도구가 된다
const bb = (hello) => `
<div class="a">
${hello}
</div>
`


