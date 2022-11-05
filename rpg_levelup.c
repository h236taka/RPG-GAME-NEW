#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

void player_skill_check(Player ******st, P_skill ******player_skill){
  if ( (*****st) -> lv == 2 ){
    (*****player_skill) -> recover1 = 1;                        //skillget!
    printf("%sはケディアを習得した!\n", (*****st) -> name);
  }
  else if ( (*****st) -> lv == 3 ){
    (*****player_skill) -> cure_poison = 1;                     //skillget!
    printf("%sはCURE-POISONを習得した!\n", (*****st) -> name);
  }
}


void status_lvup(Player *****st, P_skill *****player_skill){
  int hp, mp, status_count;
  char point[COMMAND];

  status_count = 0; //statusUPがなされたかcheck
  hp = (rand() % ( 5 - 3 + 1) ) + 3; //Lvup時のHP増加率 3~5
  mp = (rand() % ( 5 - 3 + 1) ) + 3; //Lvup時のMP増加率 3~5
  (****st) -> maxhp += hp;
  (****st) -> maxmp += mp;

  player_skill_check(&st, &player_skill);

  printf("%sの上昇させたい能力を選んで下さい!\n", (****st) -> name);
  printf("1.力:%d\n", (****st) -> atk);
  printf("2.魔:%d\n", (****st) -> magic);
  printf("3.体:%d\n", (****st) -> str);
  printf("4.速:%d\n", (****st) -> agi);
  printf("5.運:%d\n", (****st) -> luk);
  do {
    printf("1~5の内数字を1つ入力してください!\n");
    scanf("%s", point);
    if ( strcmp(point, "1") == 0 ){
      (****st) -> atk++;
      printf("力:%d -> 力:%d\n", (****st) -> atk - 1, (****st) -> atk);
      status_count++;
    }
    else if ( strcmp(point, "2") == 0 ){
      (****st) -> magic++;
      printf("魔:%d -> 魔:%d\n", (****st) -> magic - 1, (****st) -> magic);
      (****st) -> maxmp += 3;
      status_count++;
    }
    else if ( strcmp(point, "3") == 0 ){
      (****st) -> str++;
      printf("体:%d -> 体:%d\n", (****st) -> str - 1, (****st) -> str);
      (****st) -> maxhp += 5;
      status_count++;
    }
    else if ( strcmp(point, "4") == 0 ){
      (****st) -> agi++;
      printf("速:%d -> 速:%d\n", (****st) -> agi - 1, (****st) -> agi);
      status_count++;
    }
    else if ( strcmp(point, "5") == 0 ){
      (****st) -> luk++;
      printf("運:%d -> 運:%d\n", (****st) -> luk - 1, (****st) -> luk);
      status_count++;
    }
    else{
      printf("再度入力してください!\n");
      printf("\n");
    }
  }while ( status_count == 0 );

  printf("\n");
  printf("%sの能力\n", (****st) -> name);
  printf("LV:%d\n", (****st) -> lv);
  printf("HP:%d/%d MP:%d/%d\n", (****st) -> hp, (****st) -> maxhp, (****st) -> mp, (****st) -> maxmp);
  printf("1.力:%d\n", (****st) -> atk);
  printf("2.魔:%d\n", (****st) -> magic);
  printf("3.体:%d\n", (****st) -> str);
  printf("4.速:%d\n", (****st) -> agi);
  printf("5.運:%d\n", (****st) -> luk);
  printf("\n");
}

void special_status_lvup(Player *****st){
  int per;

  printf("%sにさらなる力がみなぎる!!\n", (****st) -> name);
  sleep(1);

  per = (rand() % ( 5 - 1 + 1 ) + 1);
  if ( per == 1 ){
    (****st) -> atk++;
    printf("力が1ポイント上昇した!\n");
    printf("\n");
  }
  else if ( per == 2 ){
    (****st) -> magic++;
    (****st) -> maxmp += 3;
    printf("魔が1ポイント上昇した!\n");
    printf("\n");
  }
  else if ( per == 3 ){
    (****st) -> str++;
    (****st) -> maxhp += 5;
    printf("体が1ポイント上昇した!\n");
    printf("\n");
  }
  else if ( per == 4 ){
    (****st) -> agi++;
    printf("速が1ポイント上昇した!\n");
    printf("\n");
  }
  else if ( per == 5 ){
    (****st) -> luk++;
    printf("運が1ポイント上昇した!\n");
    printf("\n");
  }

  sleep(1);

}

void level_up(Player ****st, P_skill ****player_skill){
  int exp_function;  //LVup必要経験値 LVUPごとに1.4倍
  int i, finish_count, level_up_point, per;

  level_up_point = 1;
  do{
    exp_function = 10;
    finish_count = 0;
    for ( i = 1; i <= (***st) -> lv; i++ ){
      if ( (***st) -> lv == 1 ){
        exp_function = 10;
        break;
      }
      else{
        exp_function *= 1.4;
      }
    }

    printf("exp_function:%d\n", exp_function);

    if ( level_up_point != 1 ){
      (***st) -> lv++;
      printf("%sはLVUP!!\n", (***st) -> name);
      printf("%s LV:%d -> LV:%d\n", (***st) -> name, (***st) -> lv - 1, (***st) -> lv);

      status_lvup(&st, &player_skill);

      level_up_point--;

      if ( level_up_point == 1 ){
        break;
      }
    }

    if ( (***st) -> exp >= exp_function && level_up_point == 1 ){
      (***st) -> lv++;
      printf("%sはLVUP!!\n", (***st) -> name);
      printf("%s LV:%d -> LV:%d\n", (***st) -> name, (***st) -> lv - 1, (***st) -> lv);

      status_lvup(&st, &player_skill);

      per = (rand() % ( 10 - 1 + 1 ) + 1); //10%
      if ( per == 5 ){
        //更にステータスアップ
        special_status_lvup(&st);
      }

      //同時に複数レベル上昇時の判断(15レベル同時上昇まで)
      for ( i = 2; i <= 15; i++ ){
        if ( (***st) -> exp >= exp_function * i ){
          level_up_point = i;
        }
      }

      (***st) -> exp = 0;
    }
    else{
      finish_count++;
    }
    //次のレベルまでの必要経験値
    (***st) -> nextexp = exp_function - (***st) -> exp;

  }while( finish_count == 0 );

}
