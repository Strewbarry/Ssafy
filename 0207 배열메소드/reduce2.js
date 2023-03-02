const studentInfo =[
  {
    name : "jony",
    age: 30,
  },
  {
    name : "yeon",
    age: 30,
  },
  {
    name : "nana",
    age: 1,
  },
];

// const newStudentInfo = studentInfo.map((stdent) => student.name);
// console.log(newStudentInfo);

const newwStudentInfo = studentInfo.reduce((acc, cur) => {
  acc.push(cur.name);
  return acc;
  //acc 의 초기값은 빈배열
}, []);

const over30Info = studentInfo.reduce((acc, cur) => {
  // 현재 index의 age가 30이상이면
  if(cur.age>=30)
    //acc에 이름 넣기 
    acc.push(cur.name);
    return acc;
}, []);

