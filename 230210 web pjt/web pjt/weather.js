


async function setRenderBackground() {
  //body 의 background에 주소를 넣어도 ok
  
  // 일부러 axios 요청으로 이미지를 받아오기
  const result = await axios.get("https://picsum.photos/1280/720",{
    responseType : "blob"
  });
  console.log(result);

  //나중에 다운로드 할때 많이 사용하는 방식 
  // URL.createObjectURL >> 임시 url만든다 (페이지 안에서만 유효);
  const imageURL = URL.createObjectURL(result.data);
  document.querySelector('body').style.backgroundImage = `url(${imageURL})`;
}
// 화살표 함수로 변형하려면 
// const setRenderBackground = async () => {}   이렇게!

// 시간갱신
function setTime() {
  const timer = document.querySelector('.timer');

  setInterval(()=>{
    //date 함수
    const date = new Date();
    timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;
  },1000)
}

function getMemo() {
  //localStorage 로 부터 가져와서 memo에 넣어주는 작업
  const memo = document.querySelector(".memo");
  memo.textContent = localStorage.getItem('todo');
}

function setMemo() {
  const memoInput = document.querySelector(".memo-input");
  memoInput.addEventListener('keyup',function(e){
    // e.code 입력시 >> 작성한 키보드 조회;
    console.log(e.code);
    console.log(e.target);
    console.log(e.target.value);

    //e.code가 enter 인 경우에 메모 내용이 바뀌어지도록 
    // ! null undefined false "" >> 부정의 의미
    // if(e.target.value) >> 위 부정의 의미가 아닌경우 통합
    // if(!e.target.value) >> 부정의 의미인 경우
    if(e.code === 'Enter' && e.target.value){
      //메모를 저장 
      // const memo = document.querySelector(".memo");
      // memo.textContent = e.target.value;

      //메모가 날아가지 않도록저장해야함
      // 백엔드 >> db에 저장해서 가져오는 작업
      // 브라우저에도 간단한 저장개념이 있다. localstorage
      // localStorage 사용법
      // localStorage.setItem('키', '넣을값')
      localStorage.setItem('todo',e.target.value);
      // localStorage.getItem('키') >> 값을 가져온다

      // getMemo로 분리
      getMemo();
      e.target.value="";
    }
  })
}

function deleteMemo() {
  // 이벤트 위임
  // document.querySelector('body')

  // 똑같은 함수를 수백만개에 addEventListener 가정 >> 속도저하
  document.addEventListener('click',function(e){
    console.log(e.target);
    // e.target.ClassList 가 hello 인경우에 ~ 이벤트 실행 

    // localstorage 를 지워야하고
    if(e.target.classList.contains('memo')){
      localStorage.removeItem('todo');

      e.target.textContent = "";
    }
    // HTML 파트도 지워야 한다
  })

}


async function allRender() {
  // 얘를 주석처리하면 아래의 함수가 처음작동하기 전인 5초간 배경이 비게된다
  setRenderBackground();
  
  setTime();
  setMemo();
  getMemo();
  deleteMemo();

  // 얘도 비동기함수
  // 설정 시간마다 해당 콜백함수 반복
  setInterval(() => {
    setRenderBackground();
  }, 5000) // 5000ms 설정
}

allRender();