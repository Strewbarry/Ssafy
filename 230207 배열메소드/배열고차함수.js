// // const bucketLists = [
// //   { id: 3, text: "여행가기", done: false },
// //   { id: 2, text: "치킨 먹기", done: true },
// //   { id: 1, text: "코딩 하기", done: false },
// // ];
// // const getValues = (indecator) =>
// //   bucketLists.map((bucketlist) => bucketlist[indecator]);
// // console.log(getValues("id"));
// // console.log(getValues("text"));
// // console.log(getValues("done"));

// let bucketLists = [
//   { id: 3, text: "여행가기", done: false },
//   { id: 2, text: "치킨 먹기", done: true },
//   { id: 1, text: "코딩 하기", done: false },
// ];
// // 버킷리스트에서 id로 골라서 해당 개체 지우기
// const removeList = (id) => bucketLists.filter((el) => el.id !== id);
// removeList(2);
// // id=2 인 항목이 지워진 배열이 출력된다
// console.log(removeList(2));
// // filter를 사용하였으므로 원본 배열은 유지된다
// console.log(bucketLists);

const bucketLists = [
  { id: 3, text: "여행가기", done: false },
  { id: 2, text: "치킨 먹기", done: true },
  { id: 1, text: "코딩 하기", done: false },
];

const toggle = (id) => {
  //원본 손상 방지를 위한 클론배열 생성
  const newBucketLists = structuredClone(bucketLists);
  //입력 받은 id와 같은 값의 id를 가지는 객체 하나만 뽑아서 새로운 배열로 생성
  const ret = newBucketLists.filter((el) => el.id === id);
  // 새로운 배열은 한개의 값만을 가지기 때문에
  // 0번 index에 내가 걸러놓은 데이터가 있다.
  // 따라서 ret[0]을 통해 index에 접근하고 .done을 이용해 boolean에 접근한다
  if (ret[0].done) {
    ret[0].done = false;
  } else {
    ret[0].done = true;
  }
  return newBucketLists;
};

console.log(toggle(1));

