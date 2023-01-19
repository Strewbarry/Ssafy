//토글 버튼
const toggleButton = document.querySelector(".toggle-button");
//배경
const bodyBackground = document.querySelector("body");

//header-nav
const headerNav = document.querySelector(".haeder-nav-list-wrapper");
//bookmarkWrapper
const bookmarkWrappers = document.querySelector(".bookmark-wrapper");
// search-input
const searchInput = document.querySelector("#search-input");
// imgicon-wrapper
// 여러개 동시에 바꾸기 위해 qsAll 사용
const imgIconWrappers = document.querySelectorAll(".imgicon-wrapper");
//bookmark-text
const bookmarkTexts = document.querySelectorAll(".bookmark_text");

toggleButton.addEventListener("click", function () {
  // 클릭 하면
  // 다크모드로 전환
  // 일반모드 >> 다크모드로 텍스트 변경imgicon-wrapper-darkmode

  toggleButton.textContent = "다크 모드";
  // classList.contains 를 활용할 예정

  // classList 는 class로 대응되기 때문에 .을 붙이지 않는다
  toggleButton.classList.toggle("toggle-button-darkmode");
  bodyBackground.classList.toggle("body-background-darkmode");
  headerNav.classList.toggle("text-darkmode");
  
  for (let i = 0; i < imgIconWrappers.length; i++) {
    imgIconWrappers[i].classList.toggle("imgicon-wrapper-darkmode");
  }

  for (let i = 0; i < bookmarkTexts.length; i++) {
    bookmarkTexts[i].classList.toggle("text-darkmode")
  }

  if (toggleButton.classList.contains("toggle-button-darkmode")) {
    toggleButton.textContent = "일반 모드";
  }
});

searchInput.addEventListener('keyup',function(e){
  //e.code 어떤키를 입력했는지 알 수 있게 해줌
  //enter 를 입력했을때 그거로 검색을 진행할 예정
  if(e.code === "Enter"){
    // 검색어가 존재할때만 이동
    // 
    if(!e.target.value){
      alert("검색어를 입력하지 않으셨습니다!");
      return;
    }
    //이동하기
    const googleSearch = "https://www.google.com/search?q=";
    // location.href =googleSearch + e.target.value;


    // 새창으로 열기
    // <a href = "" target="_blank">    >> 새창으로 열기
    window.open(googleSearch+e.target.value, "_blank")
  }
})
