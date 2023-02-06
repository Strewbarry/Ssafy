// class StudentInfo {
//   constructor(name, age) {
//     this.name = name;
//     this.age = age;
//     this.address = "";
//   }
//   sayMyName() {
//     console.log(`my name is ${this.name}`);
//   }
//   setAddress(address) {
//     this.address = address;
//   }
//   getAddress() {
//     return this.address;
//   }
//   useMethod() {
//     this.sayMyName();
//   }
// }

// const student1 = new StudentInfo("jony", 30);
// const student2 = new StudentInfo("David", 40);

// const studentInfo = {
//   name : "",
//   age: -1,
//   address : "",
//   sayMyName:() => console.log(`my name is ${this.name}`),
//   setAddress: (address) => (this.address = address),
//   getAddress: () => this.address,
//   useMethod: () => sayMyName(),  
// };

// student1.sayMyName();
// student1.setAddress("경기 군포시 산본동");
// console.log(student1.getAddress());
// student1.useMethod();


const student1 = {
  name: "",
  age: -1,      // 이것이 number 다
  address: "",  // 이것은 string 이다 
  constructor: function (name, age) {   
    this.name = name;                 
    this.age = age;
  },
  sayMyName: function () {                    // 화살표 함수는 안에 this로 접근할 수 없다.
    console.log(`my name is ${this.name}`);   // 그럴 때를 대비해 function 을 써보자
  },
  setAddress: (address) => (this.address = address),
  getAddress: () => this.address,
  useMethod: function () {
    this.sayMyName();
  },
};

student1.constructor("jony", 30);
student2.constructor("david", 50);
student1.sayMyName();
student1.setAddress("경기 군포시 산본동");
console.log(student1.getAddress());
student1.useMethod();