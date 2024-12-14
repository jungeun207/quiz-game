#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//문제 데이터 저장할 구조체 정의
typedef struct {
    char *Question; //문제
    char *Case[3]; //보기 (3개)
    int Answer; //정답
    int Already; //이미 출제된 문제 재출제 방지 (1이면 출제된 문제)
} Question;

//문제 데이터 배열
Question Question_data[] = {
    {"다음 중 나라와 수도가 올바르게 짝지어진 것은?\n", "독일-베를린", "호주-시드니", "태국-치앙마이", 1, 0},
    {"'중도에서 성의 없이 그만두는 모양'을 이르는 말로 올바른 순우리말은?\n", "빈둥빈둥", "빈둥반둥", "반둥건둥", 3, 0},
    {"'ㅇㅇ도 약에 쓰려면 없다'에서 ㅇㅇ은?\n", "소똥", "토끼똥", "개똥", 3, 0},
    {"다음 중 가장 가벼운 기체는?\n", "산소", "수소", "질소", 2, 0},
    {"가장 많은 영화를 제작한 국가는?\n", "미국", "영국", "독일", 1, 0},
    {"10원짜리 동전 앞 면에 새겨진 탑의 이름은?\n", "다보탑", "석가탑", "무영탑", 1, 0},
    {"고려 시대에 만들어진 인쇄물로, 세계에서 가장 오래된 금속활자본인 '이것'의 이름은?\n", "팔만대장경", "무구정광대다라니경", "직지심체요절", 3, 0},
    {"태양계에서 가장 큰 행성은?\n", "금성", "목성", "토성", 2, 0},
    {"벌에게 쏘였을 때 가장 아픈 부위는?\n", "콧구멍", "발바닥", "윗입술", 1, 0},
    {"소설 <어린 왕자> 속 어린 왕자가 살고 있던 소행성의 이름은?\n", "B-203", "B-120", "B-612", 3, 0}
};

int main() {
    int Select; //문제 선택
    int Select_num; //랜덤으로 선택된 문제 번호
    int i; //보기 출력
    int ch; //사용자 입력

    srand(time(0)); //랜덤 시드 설정

    //총 10문제 풀 때까지 반복
    for (Select=0; Select<10; Select++) {
        //중복 문제 출제 방지
        do {
            Select_num=rand()%(sizeof(Question_data)/sizeof(Question_data[0])); //문제 배열에서 랜덤으로 하나 선택
        } while (Question_data[Select_num].Already==1); //출제된 문제는 다시 선택되지 않도록 함
        
        Question_data[Select_num].Already=1; //문제 출제 완료 표시

        system("cls"); //화면 지우기

        //게임 제목 출력
        printf("┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┓\n");
        printf("┃   Q U I Z G A M E   ┃\n");
        printf("┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┛\n");

        printf("\n%s\n", Question_data[Select_num].Question); //문제 출력
        for (i=0; i<3; i++) { //보기 3개 출력
            printf("%d) %s\n", i+1, Question_data[Select_num].Case[i]);
        }
        printf("\n정답을 숫자로 작성해 주세요: ");

        ch=getchar(); //사용자 입력 받기
        ch=ch-'0'; //입력받은 문자를 정수로 변환 

        //정답 확인
        if (ch==Question_data[Select_num].Answer) {
            printf("정답입니다!\n");
        } else {
            printf("오답입니다. 정답은 %d번입니다.\n", Question_data[Select_num].Answer);
        }

        Sleep(1500); //1.5초 대기 후 다음 문제로 넘어감
        getchar(); //엔터키를 입력받아 다음 문제로 넘어감
    }

    system("cls"); //마지막 화면 지우기
    printf("모든 문제를 해결했습니다. 게임을 종료합니다. ^ㅁ^\n");
    getchar(); //종료 전 한 번 더 엔터키를 입력받아 게임 종료

    return 0;
}