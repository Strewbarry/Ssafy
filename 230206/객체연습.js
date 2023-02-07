class Person {
  constructor(name,hp){
    this.name = name;
    this.hp = hp;
  }
  hello() {
    console.log("hello");
  }
}

class avengers extends Person {
  constructor(power,skill){
    super(Person)
    this.power = power;
    this.skill = skill;
  }
  information(){
    console.log(this.name);
    console.log(this.hp);
    console.log(this.power);
    console.log(this.skill);
  }
  fly(){
    console.log("비행중");    
  }
}

const ironman = new Person(ironman,100);




