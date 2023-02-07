// const arr = [1,2,3,4,5,6,7,8,9,10];
// const arr2 = [1,2,3,4,5,6,7,8,9,10];

// const odd = arr.filter(el=>el%2===1);
// const odd10 = odd.map(el => el*10);

// const even = arr2.filter(el=>el%2===0);
// const even10 = even.map(el=> el*10);


const orderlist =[
  {
    menu:"치킨 ",
    price:  17000,
    event: false,
    coutn: 50,
  },
  {
    menu:"돈까스 ",
    price:  8500,
    event: true,
    coutn: 99,
  },
  {
    menu:"마라탕 ",
    price:  8000,
    event: false,
    coutn: 100,
  },
  {
    menu:"쫄면 ",
    price:  6500,
    event: false,
    coutn: 0,
  },
  {
    menu:"짜장면 ",
    price:  5500,
    event: true,
    coutn: 30,
  },
];

const newOrderList = orderList
  .filter((order) => order.count !== 0)
  .map((order) => {
    const newOrder = structuredClone(order);
  //const newOrder = order; 의 경우 js의 배열이 포인터역할을 하여 넣어도 전부 원본을
  //   훼손시키기 때문에 js에서 제공하는 structuredClone 함수를 이용하여 값만 복사해온다
    if (order.event) {
      newOrder.saledPrice = (newOrder.price * 9) / 10;
      return newOrder;
    }
    newOrder.saledPrice = newOrder.price;
    // saledPrice가 같은 객체도 같은 값을 작성해 주어서 class type이 유지되도록 한다
    return newOrder;
  });
console.log(orderList); // 원래 배열은 손상되지 않는다.
console.log(newOrderList); // 새로운 메뉴 리스트
