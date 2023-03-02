
// const array = [3,5,4,2];
// //3 보다 큰애들만 새로운 배열에 넣어라
// const filtered = array.filter(data => data>3);

const bucketlist = [
  {
    id : 1,
    text : "여행가기",
    done : false,
  },
  {
    id : 2,
    text : "치킨먹기",
    done : true,
  },
  {
    id : 3,
    text : "코딩하기",
    done : true,
  },
  {
    id : 4,
    text : "요리하기",
    done : false,
  },
];
// done 이 true 인 값만 새로운 배열에 담기
const done = bucketlist.filter(data => data.done===true);



