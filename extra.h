#include <stdio.h>

typedef struct{
	char depart[20]; // 출발지
	char arrive[20]; // 도착지
	short int date; // 출발날짜 (예, 0326)
	short int time; // 출발시간 (예, 1940)
	short int num; // 모집인원
	char type; // 모집종류(T/C) (T: 택시, C: 카풀)
	short int now_num; // 현재 모집된 인원
	char memo[100]; // 메모
	short int pw; // 비밀번호(4자리 숫자)
} Recruit;

int selectMenu(); // 메뉴 선택

int selectDataNo(Recruit *s[], int count); // 데이터 번호 선택
void listRecruit(Recruit *s[], int count); // 모집 리스트 출력

int joinRecruit(Recruit *s); // 모집 참여
int exitjoinRecruit(Recruit *s); // 모집 참여 취소 
int searchPlace(Recruit *s, int count); // 지점 검색
int searchDay(Recruit *s, int count); // 날짜 검색

int editTime(Recruit *s, int count); // 시간, 날짜 수정
int editPlace(Recruit *s, int count); // 지점 수정
void updateMemo(Recruit *s, int count); // 추가 메모 작성
