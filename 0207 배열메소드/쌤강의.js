const students = [
  {
    name : "김도훈",
    age : 26,
    address : "경남 창원시"
  },
  {
    name : "김기홍",
    age : 27,
    address : "광주광역시"
  },
  {
    name : "김택우",
    age : 30,
    address : "인천광역시"
  },
];

//각 객체 출력하며 전체탐색
students.forEach((student)=>{
  console.log(student);
});
// 각 객체의 이름을 출력하며 전체탐색
students.forEach((student)=>{
  console.log(student.name);
});

// 30살 이상의 정보 전체가 저장
const over30names = students.filter(student => student.age>=30);

// 전체 학생 목록중에 30살 이하 탐색해서 새로운 배열만들기
const under30 = students.filter(student => student.age<30);
// 그 새로운 배열중에 이름을 뽑아 새로운 배열로 만들기
const under30names = under30.map(student => student.name);


