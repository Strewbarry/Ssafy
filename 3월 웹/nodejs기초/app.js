

const calc =  {
  
  plus:(a,b)=>a+b,
  mius:(a,b)=>a-b,
  multi:(a,b)=>a*b,
  divd:(a,b)=>a/b
}
const a=2;
const b=4;

console.log(`주어진 수 : ${a} , ${b}`);
console.log(`덧셈 결과 : ${calc.plus(a,b)}`);
console.log(`뺄셈 결과 : ${calc.mius(a,b)}`);
console.log(`곱셈 결과 : ${calc.multi(a,b)}`);
console.log(`나눗셈 결과 : ${calc.divd(a,b)}`);
