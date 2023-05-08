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
  - 택시, 카풀 동승자 모집글 작성
  - 모집글 전체 조회  
  - 모집글 전체 수정  
  - 모집글 부분 수정  
  - 모집글 삭제 (삭제시 비밀번호 입력)  
  - 모집글 출발 날짜 및 시간, 출발지 -> 도착지로 검색

<br/>

## 🚖 iTaxi CRUD
> 코드 및 기능  
  
<manager.h>
```c
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
int deleteRecruit(Recruit *s); // 모집 삭제 함수

```
<product.h>
```c
#include <stdio.h>
#include "product.h"

int selectMenu(); // 메뉴 선택

int selectDataNo(Recruit *s[], int count); // 데이터 번호 선택
void listRecruit(Recruit *s[], int count); // 모집 리스트 출력

int joinRecruit(Recruit *s); // 모집 참여
int exitjoinRecruit(Recruit *s); // 모집 참여 취소 
int searchPlace(Recruit *s, int count); // 출발지 -> 도착지 검색
int searchDay(Recruit *s, int count); // 날짜 검색

int editTime(Recruit *s, int count); //출발 시간, 날짜 수정
int editPlace(Recruit *s, int count); // 출발, 도착 지점 수정

```

<br/>

## 🚖 개발환경 및 언어
  - git 
  - vs code

<br/>

## 🚖 팀소개 및 팀원이 맡은 역할
### 팀원
 #### 김영빈 [hanyoq15 GITHUB LINK](https://github.com/hanyoq15)
  - 
  - 
  
<br/>

#### 김채린 [seizethedaylyn GITHUB LINK](https://github.com/seizethedaylyn)
 - 
 - 

<!--
<p align="center"><img src="" height="" width=""></p>
-->
