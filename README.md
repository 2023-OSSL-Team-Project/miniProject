# 🧊 miniProject

<div align="center"> 

//<img src="" height="" width="">
 
  ## *iTaxi*  
</div>
  
## 📟 주제
 - iTaxi - 한동이들의 교통 어플리케이션

<br/>

## 📟 iTaxi에 대한 소개
  - 한동대학교 구성원을 위한 택시, 카풀 공유경제 플랫폼입니다.
  - 

<br/>
  
##  📟 iTaxi가 가지고 있는 대략적인 기능 설명
  - 
  - 

<br/>

## 📟 CUBE KIOSK CRUD
> 코드 및 기능
```c
typedef struct {
    int contents; // 1: 음료 2: 디저트
    char name[100];
    int price;
    int sugar;
    }Product;
    // 구조체 
    
int createProduct(Product *p); // 제품을 추가하는 함수 => 메뉴 선택
void readProduct(Product *p); // 하나의 제품 출력 함수 => 구매 목록 보기
int updateProduct(Product *p); // 제품을 수정하는 함수 => 구매 목록 수정 
int deleteProduct(Product *p); // 제품을 삭제하는 함수 => 구매 취소 [환불]

void saveProduct(Product *p, int count); //데이터를 파일에 저장 하는 함수
int loadProduct(Product *p);// 저장된 데이터를 불러오는 함수

int selectMenu(); // 데이터를 다룰 때, 원하는 메뉴를 선택하는 함수
int selectDataNo(Product *p, int count); // 제품 번호를 불러오는 
int listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
//검색기능 이름/가격/배송방법

void searchProductName(Product *p, int count); // 메뉴이름 검색
void searchProductPrice(Product *p, int count); // 메뉴가격 검색 
void searchProductSugar(Product *p, int count); // 메뉴 설탕 추가 여부로 검색

void todayMenu(Product *p); // 랜덤으로 오늘의 추천 메뉴 알려주는 기능

```

<br/>

## 📟 개발환경 및 언어
  - git 
  - vs code

<br/>

## 📟 팀소개 및 팀원이 맡은 역할
### 팀원
 #### 김영빈 [hanyoq15 GITHUB LINK](https://github.com/hanyoq15)
  - Repo Owner
  - 
  
<br/>

#### 김채린 [Y-eseong GITHUB LINK](https://github.com/seizethedaylyn)
 - 
 - 

//<p align="center"><img src="" height="" width=""></p>
