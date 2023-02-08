const names = ["jony","sylvie","nana"];

// slice (index1, index2)
// 원본배열을 건드리지 않는다
// index1 부터 index2 앞까지 자른다
// newNames = ["sylvie"]
const newNames = names.slice(1,2);
console.log(names);
console.log(newNames);


// splice(index1, number)
// 원본 배열을 손상시킨다
// index1 부터 number 갯수만큼 가져온다
// newwNames = ["sylvie"]
const newwNames = names.splice(1,1);
console.log(names);
console.log(newwNames);


// 배열에서 특정값 지울 때 사용하는 코드 
var index = array.indexOf(item);
if (index !== -1) {
  array.splice(index, 1);
}
