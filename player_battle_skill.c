#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include "rpg.h"

//敵と味方のスキルに関する機能

int player_ability(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, int use_skill_count, int skill_target, int skill_user){
  int recover_point, base, beforehp;

  if ( use_skill_count == 1 ){

    //skill使用者
    if ( skill_user == 1 ){
      printf("%s>>ケディア\n", (***st) -> name);
      sleep(1);

      if ( (***st) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (***st) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (***st) -> magic * 3 + (***st) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (***st) -> hp;

          (***st) -> hp += recover_point;
          if ( (***st) -> hp >= (***st) -> maxhp ){
            (***st) -> hp = (***st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st) -> name, beforehp, (***st) -> maxhp, (***st) -> hp, (***st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (***st2) -> hp;

          (***st2) -> hp += recover_point;
          if ( (***st2) -> hp >= (***st2) -> maxhp ){
            (***st2) -> hp = (***st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st2) -> name, beforehp, (***st2) -> maxhp, (***st2) -> hp, (***st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (***st3) -> hp;

          (***st3) -> hp += recover_point;
          if ( (***st3) -> hp >= (***st3) -> maxhp ){
            (***st3) -> hp = (***st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st3) -> name, beforehp, (***st3) -> maxhp, (***st3) -> hp, (***st3) -> maxhp);
          printf("\n");
        }

      }
    }
    else if ( skill_user == 2 ){
      printf("%s>>ケディア\n", (***st2) -> name);
      sleep(1);

      if ( (***st2) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (***st2) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (***st2) -> magic * 3 + (***st2) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (***st) -> hp;

          (***st) -> hp += recover_point;
          if ( (***st) -> hp >= (***st) -> maxhp ){
            (***st) -> hp = (***st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st) -> name, beforehp, (***st) -> maxhp, (***st) -> hp, (***st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (***st2) -> hp;

          (***st2) -> hp += recover_point;
          if ( (***st2) -> hp >= (***st2) -> maxhp ){
            (***st2) -> hp = (***st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st2) -> name, beforehp, (***st2) -> maxhp, (***st2) -> hp, (***st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (***st3) -> hp;

          (***st3) -> hp += recover_point;
          if ( (***st3) -> hp >= (***st3) -> maxhp ){
            (***st3) -> hp = (***st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st3) -> name, beforehp, (***st3) -> maxhp, (***st3) -> hp, (***st3) -> maxhp);
          printf("\n");
        }

      }
    }
    else if ( skill_user == 3 ){
      printf("%s>>ケディア\n", (***st3) -> name);
      sleep(1);

      if ( (***st3) -> mp < 3 ){
        printf("MP不足!\n");
      }
      else{
        (***st3) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (***st3) -> magic * 3 + (***st3) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == 1 ){
          beforehp = (***st) -> hp;

          (***st) -> hp += recover_point;
          if ( (***st) -> hp >= (***st) -> maxhp ){
            (***st) -> hp = (***st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st) -> name, beforehp, (***st) -> maxhp, (***st) -> hp, (***st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 2 ){
          beforehp = (***st2) -> hp;

          (***st2) -> hp += recover_point;
          if ( (***st2) -> hp >= (***st2) -> maxhp ){
            (***st2) -> hp = (***st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st2) -> name, beforehp, (***st2) -> maxhp, (***st2) -> hp, (***st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == 3 ){
          beforehp = (***st3) -> hp;

          (***st3) -> hp += recover_point;
          if ( (***st3) -> hp >= (***st3) -> maxhp ){
            (***st3) -> hp = (***st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (***st3) -> name, beforehp, (***st3) -> maxhp, (***st3) -> hp, (***st3) -> maxhp);
          printf("\n");
        }

      }
    }

  }
  else if ( use_skill_count == 2 ){  //キュアポ
    //skill使用者
    if ( skill_user == 1 ){
      printf("%s>>キュアポ\n", (***st) -> name);
      sleep(1);

      if ( (***st) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (***st) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (***st) -> badstatus == POISON ){
            (***st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (***st2) -> badstatus == POISON ){
            (***st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (***st3) -> badstatus == POISON ){
            (***st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == 2 ){
      printf("%s>>キュアポ\n", (***st2) -> name);
      sleep(1);

      if ( (***st2) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (***st2) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (***st) -> badstatus == POISON ){
            (***st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (***st2) -> badstatus == POISON ){
            (***st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (***st3) -> badstatus == POISON ){
            (***st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == 3 ){
      printf("%s>>キュアポ\n", (***st3) -> name);
      sleep(1);

      if ( (***st3) -> mp < 4 ){
        printf("MP不足!\n");
      }
      else{
        (***st3) -> mp -= 4;

        if ( skill_target == 1 ){
          if ( (***st) -> badstatus == POISON ){
            (***st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 2 ){
          if ( (***st2) -> badstatus == POISON ){
            (***st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st2) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }
        else if ( skill_target == 3 ){
          if ( (***st3) -> badstatus == POISON ){
            (***st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (***st3) -> name);
            printf("\n");
          }
          else{
            printf("無効果\n");
            printf("\n");
          }
        }

      }
    }
  }

}

int skill_target_select(Player ****st, Player ****st2, Player ****st3, int use_skill_count){
  int skill_target;
  int command;

  if ( use_skill_count == 1 ){
    do{
      printf("使用する対象を選択してください(使用しない場合はcを入力)\n");
      if ( (***st) -> badstatus == DEAD ){
        //nothing
      }
      else{
        printf("1:%s ", (***st) -> name);
      }

      if ( (***st2) -> badstatus == DEAD ){
        //nothing
      }
      else{
        printf("2:%s ", (***st2) -> name);
      }

      if ( (***st3) -> badstatus == DEAD ){
        //nothing
      }
      else{
        printf("3:%s ", (***st3) -> name);
      }
      printf("\n");

      command =  _getch();
      if ( command == '1' ){
        if ( (***st) -> badstatus == DEAD ){
          command = 'e';  //error
        }
        else{
          skill_target = 1;
        }
      }
      else if ( command == '2' ){
        if ( (***st2) -> badstatus == DEAD ){
          command = 'e';
        }
        else{
          skill_target = 2;
        }
      }
      else if ( command == '3' ){
        if ( (***st3) -> badstatus == DEAD ){
          command = 'e';
        }
        else{
          skill_target = 3;
        }
      }
      else if ( command == 'c' ){
        skill_target = 0;
      }
    }while ( command != '1' && command != '2' && command != '3' && command != 'c' );

  }

  return skill_target;
}

int battle_player_skill_list(P_skill ****player_skill){
  int skill_count;

  skill_count = 0;
  printf("<<<<<<SKILL>>>>>>\n");
  if ( (***player_skill) -> recover1 == SETTING ){
    printf("1:ケディア 消費MP:3 (味方1人のHP小回復)\n");
    skill_count++;
  }
  if ( (***player_skill) -> cure_poison == SETTING ){
    printf("2:キュアポ 消費MP:4 (味方1人のPOISON状態を回復)\n");
    skill_count++;
  }
  if ( (***player_skill) -> recover2 == SETTING ){
    printf("3:回復:LV2 (HP中回復)\n");
    skill_count++;
  }
  if ( (***player_skill) -> recover3 == SETTING ){
    printf("4:回復:LV3 (HP大回復)\n");
    skill_count++;
  }
  if ( skill_count == 0 ){
    printf("使用可能なSKILLはありません!\n");
  }

  return skill_count;
}
