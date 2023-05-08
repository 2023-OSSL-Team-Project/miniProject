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
	int pw; // 비밀번호(4자리 숫자)
}Recruit;

int createRecruit(Recruit *s); // 모집글 작성
void readRecruit(Recruit s); // 모집글  조회
int updateRecruit(Recruit *s); // 모집글 전체 수정
int deleteRecruit(Recruit *s); // 모집글 삭제

int saveRecruit(Recruit *s, int count); // 파일 저장
int loadRecruit(Recruit *s); // 파일 읽어오기
