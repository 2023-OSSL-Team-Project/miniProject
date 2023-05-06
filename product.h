#include<stdio.h>
#include<string.h>

typedef struct{
	char depart[20]; // 출발지
	char arrive[20]; // 도착지
	short int date; // 출발날짜 (예, 0326)
	short int time; // 출발시간 (예, 1940)
	short int num; // 모집인원
	char type; // 모집종류(T/C) (T: 택시, C: 카풀)
	short int now_num; // 현재 모집된 인원
	char memo[100]; // 메모
}Recruit;

int addRecruit(Recruit *s); // 모집 추가 함수
void readRecruit(Recruit s); // 모집 조회 함수
int updateRecruit(Recruit *s); // 모집 수정 함수
int deleteRecruit(Recruit *s);
