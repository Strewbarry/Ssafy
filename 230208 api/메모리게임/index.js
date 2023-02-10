
const cardArray = [
  {
    name:"cat",
    img: "./public/cat.png",
    Id : "",
    done : false,
  },
  {
    name:"cat",
    img: "./public/cat.png",
    Id : "",
    done : false,
  },
  {
    name:"dog",
    img: "./public/dog.png",
    Id : "",
    done : false,
  },
  {
    name:"dog",
    img: "./public/dog.png",
    Id : "",
    done : false,
  },
  {
    name:"elephant",
    img: "./public/elephant.png",
    Id : "",
    done : false,
  },
  {
    name:"elephant",
    img: "./public/elephant.png",
    Id : "",
    done : false,
  },
  {
    name:"hedgehog",
    img: "./public/hedgehog.png",
    Id : "",
    done : false,
  },
  {
    name:"hedgehog",
    img: "./public/hedgehog.png",
    Id : "",
    done : false,
  },
  {
    name:"pig",
    img: "./public/pig.png",
    Id : "",
    done : false,
  },
  {
    name:"pig",
    img: "./public/pig.png",
    Id : "",
    done : false,
  },
  {
    name:"squirrel",
    img: "./public/squirrel.png",
    Id : "",
    done : false,
  },
  {
    name:"squirrel",
    img: "./public/squirrel.png",
    Id : "",
    done : false,
  },
]

let clickFirst = -1;
let clickSecond = -1;
let clickCount = 0;

const getdom = [];
const gameDOM = [];

//row, col 객체 가져다가 배열의 인덱스로 설정
const getGamedom = () => {
  const rows = document.querySelectorAll(".row");
  rows.forEach((row,idx)=>{
    gameDOM[idx] = row.querySelectorAll(".column");
  })
}
// 클릭할때마다 첫번재 인지 두번째 인지 확인하기 위한 함수
// 각 클릭에 맞는 변수의 값을 받은 변수로 변환 한다 
const setclickHistory = (location) => {
  if(clickFirst === -1){
    clickFirst = location;
  } else {
    clickSecond = location;
  }
}

const backFlip = () => {
  const parsedIDFirst = cardArray[clickFirst].id.split("-");
  const parsedIDSecond = cardArray[clickSecond].id.split("-");
  setTimeout(() => {
    gameDOM[parsedIDFirst[0]][parsedIDFirst[1]].querySelector("img").src =
    "./public/Question-Mark.png";
    gameDOM[parsedIDSecond[0]][parsedIDSecond[1]].querySelector("img").src =
    "./public/Question-Mark.png";
  },300)
}

const isCorrect = () => {
  if(cardArray[clickFirst].name === cardArray[clickSecond].name){
    cardArray[clickFirst].done = true;
    cardArray[clickSecond].done = true;
  } else {
    backFlip();
  }
}

const flip = (location) =>{
  if(!cardArray[location].done){
    setclickHistory(location);

    const parsedID = cardArray[location].id.split("-");
    gameDOM[parsedID[0]][parsedID[1]].querySelector("img").src =
      cardArray[location].img;

    clickCount++;
    if(clickCount===2){
     clickCount=0;
     isCorrect();
    }
      
  

    if(clickFirst!==-1 && clickSecond!==-1){
      clickFirst=-1;
      clickSecond=-1;
    }
  }
};

const setIDtoCardArray = () => {
  cardArray[0].id = "0-0";
  cardArray[1].id = "0-1";
  cardArray[2].id = "0-2";
  cardArray[3].id = "0-3";

  cardArray[4].id = "1-0";
  cardArray[5].id = "1-1";
  cardArray[6].id = "1-2";
  cardArray[7].id = "1-3";

  cardArray[8].id = "2-0";
  cardArray[9].id = "2-1";
  cardArray[10].id = "2-2";
  cardArray[11].id = "2-3";
}

const creatBoard = () => {
  for(let i=0;i < gameDOM.length; i++){
    for(let j = 0; j<gameDOM[i].length; j++){
      const card = document.createElement("img");
      card.setAttribute("src", "./public/Question-Mark.png");
      card.classList.add("eachImage");
      gameDOM[i][j].appendChild(card);
    }
  }
}

///////////////
getGamedom();
cardArray.sort(() => 0.5-Math.random());

setIDtoCardArray();
console.log(cardArray);
creatBoard();