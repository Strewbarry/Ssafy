#include <iostream>
#include <algorithm> // <-- 정렬 기능이 포함된 라이브러리 (min, max)
using namespace std;

// 정렬
// -> 특정 집합의 요소들을 특정 기준으로 나열하는것

// 정렬 알고리즘
// STL의 정렬 기능을 그냥 가져다가 쓸것이다. 
// --> STL에서 구현된 정렬 알고리즘 = 굉장히 "안정적" 
// --> STL에서 만들어진 정렬의 시간복잡도는 "항상" O(NlogN) 보장
// --> C++ >> Intro Sort
// --> heap 정렬, 삽입 정렬, quick 정렬

struct Student {
    string name; // 이름
    int age; // 나이 
    int grade; // 점수
};

bool cmp(int left, int right) {
    // return left < right;    
    // left < right -> true
    // left > right -> false 
    if (left > right) // 더 큰게 왼쪽에 있다 -> 저희가 원하는 상태! (올바른 상태)
        return true; // OK -pass 
    if (left < right) // 더 작은게 왼쪽에 있다 -> 우리가 원하지 않는 상태 
        return false; // 잘못됐다! -> 바꿔라! 
    // 모든 조건들이 같을때
    return false; 
}

bool ssafycmp(Student left, Student right) {
    // #1 시험 점수 높은 사람 중, 
    if (left.grade > right.grade)
        return true;
    if (left.grade < right.grade)
        return false; 
    // #2 나이가 많은 사람, 
    if (left.age > right.age)
        return true;
    if (left.age < right.age)
        return false; 
    // #3 이름이 사전순으로 빠른 사람
    if (left.name < right.name)
        return true;
    if (left.name > right.name)
        return false;
    // 마지막
    return false; 

}

int main() {
    int arr[] = { 1, 3, 5, 4, 2 }; 
    // 정렬방법
    // sort(RandomAccessIterator first, RandomAccessIterator last)
    // iterator : 포인터
    // 배열 자체 = 포인터 
    // cout << *(arr+4); // arr[0]번이 존재하는 메모리의 
    // 정렬이 되는 구간 : first부터 "last 전"의 주소까지
    // sort(배열의 시작 주소 (정렬을 하려고 하는 시작 위치), 배열의 끝주소)

    // #1 오름차순 정렬
    // sort(first, last, cmp); -> default : sort(first, last, <(less))
    // < 로 비교했을떄 오름차순이 되었다! 
    /*
    sort(arr, arr + 5); 
    for (int i = 0; i < 5; i++) 
        cout << arr[i] << " ";
    */

    // #2 내림차순 정렬
    //sort(arr, arr + 5, cmp);
    //for (int i = 0; i < 5; i++)
    //    cout << arr[i] << " ";

    // #3 사용자 정의 정렬
    // struct 정렬

    Student ssafy[5]; 
    // 시험 점수 높은 사람 중, 나이가 많은 사람, 이름이 사전순으로 빠른 사람
    ssafy[0] = { "송유빈", 3, 100};
    ssafy[1] = { "박준형", 4, 100};
    ssafy[2] = { "김택우", 2, 100}; 
    ssafy[3] = { "김기덕", 4, 100};
    ssafy[4] = { "이득화", 7, 25 };

    sort(ssafy, ssafy + 5, ssafycmp); 

    for (int i = 0; i < 5; i++) 
        cout << ssafy[i].name << " " << ssafy[i].age << " " << ssafy[i].grade<< '\n';
    
}