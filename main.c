#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extra.h"

int main(void){
  Recruit *sp[20];
  int count = 0, menu; //count : 데이터 개수
  int index = 0; // 데이터 번호


  while (1){
    menu = selectMenu();
    if (menu == 0){
      int exitok;
      printf("\n=> 종료하시겠습니까? (종료 : 0) ");
      scanf("%d",&exitok);
      if(exitok == 0) break;
    }

    if (menu == 1){
      if (count > 0)
        listRecruit(sp[0], index);
    }

    else if (menu == 2){
      sp[index]=(Recruit*)malloc(sizeof(Recruit));
      count += createRecruit(sp[index++]);
    }

    else if (menu == 3){
      int no = selectDataNo(sp[0], index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      updateRecruit(sp[no-1]);
    }

    else if (menu == 4){
      int no = selectDataNo(sp[0], index);
      int deleteok;

      if(no == 0){
        printf("취소됨!");
        continue;
      }
      
      printf("정말로 삭제하시겠습니까?(삭제 :1) ");
      scanf("%d",&deleteok);

      if(deleteok == 1){
                count -= deleteRecruit(sp[0], no-1);
                printf("\n");
                printf("=> 삭제됨!\n");
      }
    }

    else if (menu == 5){
      int no = selectDataNo(sp[0], index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      if(joinRecruit(sp[no-1]) == 1)
        printf("=> 모집에 참여되었습니다.\n");
    }

    else if (menu == 6){
      int no = selectDataNo(sp[0], index);
      if(no == 0){
        printf("취소됨!");
        continue;
      }
      if(exitjoinRecruit(sp[no-1]) == 1)
        printf("=> 모집에서 나갔습니다.\n");
    }
    
     else if (menu == 7){
      searchPlace(sp[0], count);
    }
    
    else if (menu == 8){
      searchDay(sp[0], count);
    }
    
    else return 0;
  }
  printf("종료됨!\n");
  return 0;
}
