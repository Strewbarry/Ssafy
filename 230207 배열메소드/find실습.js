const chicken = [
  { name : "머리" , quantity:1},
  { name : "날개" , quantity:2},
  { name : "닭다리" , quantity:2},
  { name : "닭가슴살" , quantity:1},
  { name : "닭발" , quantity:2},
];

const index = chicken.find(element => element.name==="닭다리");
const number = chicken.findIndex(element => element.name==="닭다리");

console.log(index);
console.log(number);


