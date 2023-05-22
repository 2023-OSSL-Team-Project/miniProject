#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"

int selectMenu_main(); // 메인화면 메뉴 선택
int selectMenu1(); // 조회 메뉴 선택
int selectMenu2(); // 모집 메뉴 선택


int selectDataNo(Recruit *s, int index); // 데이터 번호 선택
void listRecruit(Recruit *s, int index); // 모집 리스트 출력

int joinRecruit(Recruit *s,int index); // 모집 참여
int exitjoinRecruit(Recruit *s, int index); // 모집 참여 취소 
void searchPlace(Recruit *s, int index); // 지점 검색
void searchDay(Recruit *s, int index); // 날짜 검색
void updateMemo(Recruit *sp, int index);

/*
int editTime(Recruit *s, int count); // 시간, 날짜 수정
int editPlace(Recruit *s, int count); // 지점 수정
*/
