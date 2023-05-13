#include <stdio.h>

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
