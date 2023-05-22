# 📋 miniProject

<div align="center"> 

<img src="https://user-images.githubusercontent.com/130302221/236679887-e07f2804-ddea-450a-aee1-2f6a0b3f2dbb.png" height="500" width="500">
 
  ## *iTaxi*  
</div>
  
## 🚖 주제
 - iTaxi - 한동이들의 교통 어플리케이션

<br/>

## 🚖 iTaxi에 대한 소개
  - 한동대학교 구성원을 위한 택시, 카풀 공유경제 플랫폼입니다.

<br/>
  
##  🚖 iTaxi가 가지고 있는 대략적인 기능 설명
### 1.  작성자 모드  
  - 택시, 카풀 동승자 모집글 작성
  - 작성한 글 수정
  - 모집 취소 (글 삭제시 작성할 때 적은 비밀번호 입력해야 삭제됨)
### 2.  참여자 모드
  - 모집 글 전체 조회
  - 지점 검색
  - 날짜 검색
  - 동승 참여 / 취소

<br/>

## 🚖 iTaxi CRUD
> 코드 및 기능  
  
<CRUD.h>
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int createRecruit(Recruit *s, int index); // 모집글 작성
void readRecruit(Recruit s); // 모집글  조회
int updateRecruit(Recruit *s, int index); // 모집글 전체 수정
int deleteRecruit(Recruit *s, int index); // 모집글 삭제

void saveData(Recruit *s, int index); // 파일 저장
int loadData(Recruit *s); // 파일 읽어오기

```

<extra.h>
```c
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
void updateMemo(Recruit *sp, int index); // 메모 내용 
```

<br/>

## 🚖 개발환경 및 언어
### 개발환경
  - git 
  - vs code
### 사용 언어
  - c언어

<br/>

## 🚖 팀소개 및 팀원이 맡은 역할
### 팀원
 #### 김영빈 [hanyoq15 GITHUB LINK](https://github.com/hanyoq15)
  - 전체적인 코드 틀 작성
  - 지점, 날짜 검색 함수
  - 메뉴 선택 함수(main, 1, 2)
  - 데이터 번호 선택, 모집 리스트 출력 함수
  - 모집 참여 취소 함수
  - 코드 수정
  - README 파일 작성

#### 김채린 [seizethedaylyn GITHUB LINK](https://github.com/seizethedaylyn)
  - 전체적인 디자인 제공
  - create, read, update 함수
  - 메모 추가 함수
  - delete 함수
  - 파일 저장, 불러오는 함수
  - 코드 수정
  - wiki페이지 작성
