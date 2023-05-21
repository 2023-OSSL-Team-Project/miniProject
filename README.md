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
  - 작성한 글 전체 / 부분 선택하여 수정
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
#include "CRUD.h"

int createRecruit(Recruit *s, int i){

  printf("\n출발지 입력: ");
	scanf("%s", (s+i)->depart);
  
	printf("도착지 입력: ");
	scanf("%s", (s+i)->arrive );
  
	printf("출발날짜 (예, 0522): ");
  scanf("%hd", &(s+i)->date);
  
	printf("출발시간 (예, 1940): ");
  scanf("%hd", &(s+i)->time);
  
	while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &(s+i)->num);
        if((s+i)->num < 2 || (s+i)->num > 4) printf("모집 인원은 2~4명이어야 합니다\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C): ");
  scanf(" %c", &(s+i)->type);
  
  (s+i)->now_num = 1;

  printf("메모(없으면 엔터): ");
  getchar(); // 입력버퍼 지움
  fgets((s+i)-> memo, sizeof((s+i) -> memo), stdin);
  (s+i) -> memo[strlen((s+i) -> memo) -1 ] = '\0';

  while(1){
    printf("비밀번호 (4자리 숫자): ");
    scanf("%hd", &(s+i)->pw);
    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
    if((s+i)->pw < 1000 || (s+i)->pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
    else if(!((s+i)->pw)) printf("숫자로 입력해주세요.");
    else break;
  }

  return 1;
}

void readRecruit(Recruit s){
  printf("출발지: %s\n", s.depart);
  printf("도착지: %s\n", s.arrive);
  printf("날짜: %04hd\n", s.date);
  printf("시간: %04hd\n", s.time);
  printf("모집 현황(현재 인원 / 목표 인원): %hd / %hd\n", s.now_num, s.num);
  printf("모집 종류(T: 택시, C: 카풀): %c\n", s.type);
  printf("메모 : %s\n", s.memo);
}

int updateRecruit(Recruit *s, int i){
  printf("\n출발지 입력: ");
  scanf("%s", (s+i)->depart);

  printf("도착지 입력: ");
  scanf("%s", (s+i)->arrive );

  printf("출발날짜 (예, 0522): ");
  scanf("%04hd", &(s+i)->date);

  printf("출발시간 (예, 1940): ");
  scanf("%04hd", &(s+i)->time);
  
  while(1){
        printf("모집 인원 (2~4): ");
        scanf("%hd", &(s+i)->num);
        if((s+i)->num < 2 || (s+i)->num > 4) printf("모집 인원은 2~4명이어야 합니다.\n");
        else break;
  }

  printf("모집종류 (택시 : T, 카풀 : C): ");
  scanf(" %c", &(s+i)->type);
  getchar();

  (s+i)->now_num = 1;

  printf("메모(없으면 엔터 입력): ");
  getchar(); // 입력버퍼 지움
  fgets((s+i)-> memo, sizeof((s+i) -> memo), stdin);
  (s+i) -> memo[strlen((s+i) -> memo) -1 ] = '\0';

  while(1){
        printf("비밀번호 (4자리 숫자): ");
        scanf("%hd", &(s+i)->pw);
        while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
        if((s+i)->pw < 1000 || (s+i)->pw > 9999) printf("비밀번호는 4자리 숫자로 입력해주세요.\n");
        else if(!((s+i)->pw)) printf("숫자로 입력해주세요.");
        else break;
  }

  return 1;
}

int deleteRecruit(Recruit *s, int i){
  short int password;

  while(1){
    printf("비밀번호 (4자리 숫자): ");
    scanf("%hd", &password );
    while (getchar() != '\n'); // 버퍼 비움: 엔터값이 남아있으면 무한 루프 
    if((s+i)->pw != password) printf("비밀번호가 다릅니다.\n");
    else break;
  }

  (s+i)->date = -1;
  return 1;
}

void saveData(Recruit *sp, int index){
    FILE *fp;
    fp = fopen("itaxi.txt", "wt");

    for(int i = 0; i < index; i++){
        if(sp[i].date== -1) continue;
        fprintf(fp,"\t%s %s %hd %hd %hd %c %hd %s\n", sp[i].depart, sp[i].arrive, sp[i].date, sp[i].time, sp[i].num, sp[i].type, sp[i].now_num, sp[i].memo);
    }

    fclose(fp);
    printf("저장됨! \n");
}

int loadData(Recruit *sp){
    int i = 0;

    FILE *fp;
    fp = fopen("itaxi.txt", "rt");

    if(fp == NULL){
        printf("=> 파일 없음!\n");
    }
    else{
        for(; i < 20; i++){
            fscanf(fp, "%s", (sp[i].depart));
            fgetc(fp);
            if(feof(fp)) break;
            fscanf(fp, "%s", (sp[i].arrive));
            fgetc(fp);
            fscanf(fp,"%hd", &(sp[i].date));
            fgetc(fp);
            fscanf(fp, "%hd", &(sp[i].time));
            fgetc(fp);
            fscanf(fp, "%hd", &(sp[i].num));
            fgetc(fp);
            fscanf(fp, "%c", &(sp[i].type));
            fgetc(fp);
            fscanf(fp, "%hd", &(sp[i].now_num));
            fgetc(fp);
            fgets((sp+i) -> memo, sizeof((sp+i) -> memo), fp);
            (sp + i) -> memo[strlen((sp + i) -> memo) - 1] = '\0';
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }

    return i;
}

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
  - README 파일 작성
  - 참여자 모드 코드 구현

#### 김채린 [seizethedaylyn GITHUB LINK](https://github.com/seizethedaylyn)
 - Wiki 페이지 작성
 - 작성자  코드 구현

<!--
<p align="center"><img src="" height="" width=""></p>
-->
