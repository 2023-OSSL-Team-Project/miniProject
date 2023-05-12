int addRecruit(Recruit *s){
  printf("\n출발지 입력 ");
  scanf(" %[^\n]s", s->depart);
  printf("도착지 입력 ");
  scanf(" %[^\n]s", s->arrive );
  printf("출발날짜 (예, 0326) ");
  scanf("%hd", &s->date);
  printf("출발시간 (예, 1940) ");
  scanf("%hd", &s->time);
  printf("모집인원 (2~4) ");
  scanf("%hd", &s->num);
  while(s->num < 2 || s->num > 4){
    printf("모집 인원은 2명에서 4명까지 가능합니다.\n");
    printf("모집인원 (2~4) ");
    scanf("%hd", &s->num);
  }
  printf("모집종류 (택시 : T, 카풀 : C) ");
  scanf(" %c", &s->type);
  s->now_num = 1;
  printf("=> 추가됨!\n");
  return 1;
}

void readRecruit(Recruit s){
  printf("%s -> %s %04hd %04hd %hd/%hd %c\n", s.depart,s.arrive,s.date,s.time,s.now_num,s.num,s.type);
}

int updateRecruit(Recruit *s){
  printf("\n출발지 입력 ");
  scanf(" %[^\n]s", s->depart);
  printf("도착지 입력 ");
  scanf(" %[^\n]s", s->arrive );
  printf("출발날짜 (예, 0326) ");
  scanf("%hd", &s->date);
  printf("출발시간 (예, 1940) ");
  scanf("%hd", &s->time);
  printf("모집인원 (2~4) ");
  scanf("%hd", &s->num);
  while(s->num < 2 || s->num > 4){
    printf("모집 인원은 2명에서 4명까지 가능합니다.\n");
    printf("모집인원 (2~4) ");
    scanf(" %hd", &s->num);
  }
  printf("모집종류 (택시 : T, 카풀 : C) ");
  scanf(" %c", &s->type);
  printf("=> 수정됨!\n");
  return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** iTaxi ***\n");
    printf("1. 조회 ");
    printf("2. 모집 ");
    printf("3. 모집정보수정 ");
    printf("4. 모집삭제 ");
    printf("5. 모집참여 ");
    printf("6. 모집참여취소 ");
    printf("0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
}

void listRecruit(Recruit *s[], int count){
  printf("\nNo 출발지 -> 도착지 출발날짜 출발시간 모집현황 모집종류\n");
  printf("======================================================\n");
  for(int i=0; i<count; i++){
    if(s[i] == NULL) continue;
    printf("%d  ",i+1);
    readRecruit(*s[i]);
  }
}

int selectDataNo(Recruit *s[], int count){
  int no;
  listRecruit(s,count);
  printf("\n번호는 (취소 :0)? ");
  scanf("%d",&no);
  return no;
}

int joinRecruit(Recruit *s){
  int joinok;
  if(s->now_num == s->num){
    printf("이미 마감된 모집입니다.\n");
    return 0;
  }
  printf("해당 모집에 참여하시겠습니까?(참여 :1) ");
  scanf("%d",&joinok);
  if(joinok == 1){
    s->now_num++;
    return 1;
  }
  return 0;
}

int exitjoinRecruit(Recruit *s){
  int exitjoinok;
  if(s->now_num == 1){
    printf("해당 모집에 참여하지 않으셨습니다.\n");
    return 0;
  }
  printf("해당 모집에서 나가시시겠습니까?(참여 :1) ");
  scanf("%d",&exitjoinok);
  if(exitjoinok == 1){
    s->now_num--;
    return 1;
  }
  return 0;
}
