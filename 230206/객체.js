

// const studentInfo = {        //  얘는 그냥 Object(객체)
//   name : "이자룡",
//   age : 31,
//   address : "경기도 군포시",
//   family:["나", "와이프","고양이"],
//   skill:{
//     client:["vue.js","vanilla","react"],
//     server:["django","php","node.js"],
//     db:["sqlite","mongo","mysql","postgresql"],
//   },
//   sayHi : () => console.log("hi!!!!!!!!!!"),
//   // 함수를 sayHi의 value로 넣었다
//   // 객체에 들어있는 함수를 method라고 부른다
// };

StudentInfo = {         // 이것이 타입
  name : String,              // 협업시 틀을 맞추기위해 사용한다
  age : Number,               // JS는 프로토타입 이라고 부른다(c는 구조체)
  address : String,
  family: Array,
  skill: Object,
  sayHi : Function,
};


const araaayy = new Array(); // []
const student1 = new StudentInfo("jony",30);  // {}    StudentInfo 타입의 새로운 객체
                              //jony / 30 은 생성자



studentInfo.sayHi();
