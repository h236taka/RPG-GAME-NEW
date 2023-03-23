#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <math.h>
#include <wchar.h>
#include "rpg.h"

static int pEquip_temp;
static int p2Equip_temp;
static int p3Equip_temp;

//マップ上で開くメニュー画面

void menu_hp_graphycal_display(Player *****st, Player *****st2, Player *****st3){
  printf(" ------------");
  printf("           ------------");
  printf("              ------------\n");

  if ( (****st) -> hp == (****st) -> maxhp ){
    printf(" |//////////|");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.9 ){
    printf(" |/////////||");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.8 ){
    printf(" |////////| |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.7 ){
    printf(" |///////|  |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.6 ){
    printf(" |//////|   |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.5 ){
    printf(" |/////|    |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.4 ){
    printf(" |////|     |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.3 ){
    printf(" |///|      |");
  }
  else if ( (****st) -> hp >= (****st) -> maxhp * 0.2 ){
    printf(" |//|       |");
  }
  else if ( (****st) -> hp > 0 ){
    printf(" |/|        |");
  }
  else if ( (****st) -> hp == 0 ){
    printf(" ||         |");
  }

  if ( (****st2) -> hp == (****st2) -> maxhp ){
    printf("           |//////////|");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.9 ){
    printf("           |/////////||");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.8 ){
    printf("           |////////| |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.7 ){
    printf("           |///////|  |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.6 ){
    printf("           |//////|   |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.5 ){
    printf("           |/////|    |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.4 ){
    printf("           |////|     |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.3 ){
    printf("           |///|      |");
  }
  else if ( (****st2) -> hp >= (****st2) -> maxhp * 0.2 ){
    printf("           |//|       |");
  }
  else if ( (****st2) -> hp > 0 ){
    printf("           |/|        |");
  }
  else if ( (****st2) -> hp == 0 ){
    printf("           ||         |");
  }

  if ( (****st3) -> hp == (****st3) -> maxhp ){
    printf("              |//////////|\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.9 ){
    printf("              |/////////||\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.8 ){
    printf("              |////////| |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.7 ){
    printf("              |///////|  |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.6 ){
    printf("              |//////|   |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.5 ){
    printf("              |/////|    |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.4 ){
    printf("              |////|     |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.3 ){
    printf("              |///|      |\n");
  }
  else if ( (****st3) -> hp >= (****st3) -> maxhp * 0.2 ){
    printf("              |//|       |\n");
  }
  else if ( (****st3) -> hp > 0 ){
    printf("              |/|        |\n");
  }
  else if ( (****st3) -> hp == 0 ){
    printf("              ||         |\n");
  }

  printf(" ------------");
  printf("           ------------");
  printf("              ------------\n");

}

void menu_mp_graphycal_display(Player *****st, Player *****st2, Player *****st3){

  printf(" ------------");
  printf("           ------------");
  printf("              ------------\n");

  if ( (****st) -> mp == (****st) -> maxmp ){
    printf(" |//////////|");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.9 ){
    printf(" |/////////||");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.8 ){
    printf(" |////////| |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.7 ){
    printf(" |///////|  |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.6 ){
    printf(" |//////|   |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.5 ){
    printf(" |/////|    |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.4 ){
    printf(" |////|     |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.3 ){
    printf(" |///|      |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.2 ){
    printf(" |//|       |");
  }
  else if ( (****st) -> mp >= (****st) -> maxmp * 0.1 ){
    printf(" |/|        |");
  }
  else{
    //死亡時はHPゲージ表示なし
  }

  if ( (****st2) -> mp == (****st2) -> maxmp ){
    printf("           |//////////|");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.9 ){
    printf("           |/////////||");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.8 ){
    printf("           |////////| |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.7 ){
    printf("           |///////|  |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.6 ){
    printf("           |//////|   |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.5 ){
    printf("           |/////|    |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.4 ){
    printf("           |////|     |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.3 ){
    printf("           |///|      |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.2 ){
    printf("           |//|       |");
  }
  else if ( (****st2) -> mp >= (****st2) -> maxmp * 0.1 ){
    printf("           |/|        |");
  }
  else{
    //死亡時はHPゲージ表示なし
  }

  if ( (****st3) -> mp == (****st3) -> maxmp ){
    printf("              |//////////|\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.9 ){
    printf("              |/////////||\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.8 ){
    printf("              |////////| |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.7 ){
    printf("              |///////|  |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.6 ){
    printf("              |//////|   |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.5 ){
    printf("              |/////|    |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.4 ){
    printf("              |////|     |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.3 ){
    printf("              |///|      |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.2 ){
    printf("              |//|       |\n");
  }
  else if ( (****st3) -> mp >= (****st3) -> maxmp * 0.1 ){
    printf("              |/|        |\n");
  }
  else{
    //死亡時はHPゲージ表示なし
  }

  printf(" ------------");
  printf("           ------------");
  printf("              ------------\n");
}

//Playerの状態を表示
void menu_display_condition(Player *****st, int battle_display_condition_count){

  if ( battle_display_condition_count == 0 ){
    if ( (****st) -> badstatus == GOOD ){
      printf(" STATUS:GOOD");
    }
    else if ( (****st) -> badstatus == DEAD ){
      printf(" STATUS:DEAD");
    }
    else if ( (****st) -> badstatus == POISON ){
      printf(" STATUS:POISON");
    }
    else if ( (****st) -> badstatus == PALYZE ){
      printf(" STATUS:PALYZE");
    }
    else if ( (****st) -> badstatus == CHARM ){
      printf(" STATUS:CHARM");
    }
    else if ( (****st) -> badstatus == CLOSE ){
      printf(" STATUS:CLOSE");
    }
    else if ( (****st) -> badstatus == STONE ){
      printf(" STATUS:STONE");
    }
    else if ( (****st) -> badstatus == PANIC ){
      printf(" STATUS:PANIC");
    }
    else if ( (****st) -> badstatus == SLEEP ){
      printf(" STATUS:SLEEP");
    }
    else if ( (****st) -> badstatus == CURSE ){
      printf(" STATUS:CURSE");
    }
  }
  else if ( battle_display_condition_count == 1 ){
    if ( (****st) -> badstatus == GOOD ){
      printf("           STATUS:GOOD");
    }
    else if ( (****st) -> badstatus == DEAD ){
      printf("           STATUS:DEAD");
    }
    else if ( (****st) -> badstatus == POISON ){
      printf("           STATUS:POISON");
    }
    else if ( (****st) -> badstatus == PALYZE ){
      printf("           STATUS:PALYZE");
    }
    else if ( (****st) -> badstatus == CHARM ){
      printf("           STATUS:CHARM");
    }
    else if ( (****st) -> badstatus == CLOSE ){
      printf("           STATUS:CLOSE");
    }
    else if ( (****st) -> badstatus == STONE ){
      printf("           STATUS:STONE");
    }
    else if ( (****st) -> badstatus == PANIC ){
      printf("           STATUS:PANIC");
    }
    else if ( (****st) -> badstatus == SLEEP ){
      printf("           STATUS:SLEEP");
    }
    else if ( (****st) -> badstatus == CURSE ){
      printf("           STATUS:CURSE");
    }
  }
  else{
    if ( (****st) -> badstatus == GOOD ){
      printf("               STATUS:GOOD");
    }
    else if ( (****st) -> badstatus == DEAD ){
      printf("               STATUS:DEAD");
    }
    else if ( (****st) -> badstatus == POISON ){
      printf("               STATUS:POISON");
    }
    else if ( (****st) -> badstatus == PALYZE ){
      printf("               STATUS:PALYZE");
    }
    else if ( (****st) -> badstatus == CHARM ){
      printf("               STATUS:CHARM");
    }
    else if ( (****st) -> badstatus == CLOSE ){
      printf("               STATUS:CLOSE");
    }
    else if ( (****st) -> badstatus == STONE ){
      printf("               STATUS:STONE");
    }
    else if ( (****st) -> badstatus == PANIC ){
      printf("               STATUS:PANIC");
    }
    else if ( (****st) -> badstatus == SLEEP ){
      printf("               STATUS:SLEEP");
    }
    else if ( (****st) -> badstatus == CURSE ){
      printf("               STATUS:CURSE");
    }
  }
}

void menu_player_effective(Player *******st){

  if ( (******st) -> physical_attack == 200 ){
    printf("物理弱点 ");
  }
  else if ( (******st) -> physical_attack == 50 || (******st) -> physical_attack == 25 ){
    printf("物理耐性 ");
  }
  else if ( (******st) -> physical_attack == -1 ){
    printf("物理無効 ");
  }
  else if ( (******st) -> physical_attack == -2 ){
    printf("物理吸収 ");
  }
  else if ( (******st) -> physical_attack == -3 ){
    printf("物理反射 ");
  }

  if ( (******st) -> gun_attack == 200 ){
    printf("銃撃弱点 ");
  }
  else if ( (******st) -> gun_attack == 50 || (******st) -> gun_attack == 25 ){
    printf("銃撃耐性 ");
  }
  else if ( (******st) -> gun_attack == -1 ){
    printf("銃撃無効 ");
  }
  else if ( (******st) -> gun_attack == -2 ){
    printf("銃撃吸収 ");
  }
  else if ( (******st) -> gun_attack == -3 ){
    printf("銃撃反射 ");
  }

  if ( (******st) -> fire == 200 ){
    printf("火炎弱点 ");
  }
  else if ( (******st) -> fire == 50 || (******st) -> fire == 25 ){
    printf("火炎耐性 ");
  }
  else if ( (******st) -> fire == -1 ){
    printf("火炎無効 ");
  }
  else if ( (******st) -> fire == -2 ){
    printf("火炎吸収 ");
  }
  else if ( (******st) -> fire == -3 ){
    printf("火炎反射 ");
  }

  if ( (******st) -> ice == 200 ){
    printf("氷結弱点 ");
  }
  else if ( (******st) -> ice == 50 || (******st) -> ice == 25 ){
    printf("氷結耐性 ");
  }
  else if ( (******st) -> ice == -1 ){
    printf("氷結無効 ");
  }
  else if ( (******st) -> ice == -2 ){
    printf("氷結吸収 ");
  }
  else if ( (******st) -> ice == -3 ){
    printf("氷結反射 ");
  }

  if ( (******st) -> elec == 200 ){
    printf("電撃弱点 ");
  }
  else if ( (******st) -> elec == 50 || (******st) -> elec == 25 ){
    printf("電撃耐性 ");
  }
  else if ( (******st) -> elec == -1 ){
    printf("電撃無効 ");
  }
  else if ( (******st) -> elec == -2 ){
    printf("電撃吸収 ");
  }
  else if ( (******st) -> elec == -3 ){
    printf("電撃反射 ");
  }

  if ( (******st) -> wave == 200 ){
    printf("衝撃弱点 ");
  }
  else if ( (******st) -> wave == 50 || (******st) -> wave == 25 ){
    printf("衝撃耐性 ");
  }
  else if ( (******st) -> wave == -1 ){
    printf("衝撃無効 ");
  }
  else if ( (******st) -> wave == -2 ){
    printf("衝撃吸収 ");
  }
  else if ( (******st) -> wave == -3 ){
    printf("衝撃反射 ");
  }

  if ( (******st) -> almighty == 50 || (******st) -> almighty == 25 ){
    printf("万能耐性 ");
  }

  if ( (******st) -> death == 200 ){
    printf("呪殺弱点 ");
  }
  else if ( (******st) -> death == 50 || (******st) -> death == 25 ){
    printf("呪殺耐性 ");
  }
  else if ( (******st) -> death == -1 ){
    printf("呪殺無効 ");
  }
  else if ( (******st) -> death == -2 ){
    printf("呪殺吸収 ");
  }
  else if ( (******st) -> death == -3 ){
    printf("呪殺反射 ");
  }

  if ( (******st) -> expel == 200 ){
    printf("破魔弱点 ");
  }
  else if ( (******st) -> expel == 50 || (******st) -> expel == 25 ){
    printf("破魔耐性 ");
  }
  else if ( (******st) -> expel == -1 ){
    printf("破魔無効 ");
  }
  else if ( (******st) -> expel == -2 ){
    printf("破魔吸収 ");
  }
  else if ( (******st) -> expel == -3 ){
    printf("破魔反射 ");
  }

  if ( (******st) -> poison == 200 ){
    printf("毒弱点 ");
  }
  else if ( (******st) -> poison == 50 || (******st) -> poison == 25 ){
    printf("毒耐性 ");
  }
  else if ( (******st) -> poison == -1 ){
    printf("毒無効 ");
  }
  else if ( (******st) -> poison == -2 ){
    printf("毒吸収 ");
  }
  else if ( (******st) -> poison == -3 ){
    printf("毒反射 ");
  }

  if ( (******st) -> palyze == 200 ){
    printf("麻痺弱点 ");
  }
  else if ( (******st) -> palyze == 50 || (******st) -> palyze == 25 ){
    printf("麻痺耐性 ");
  }
  else if ( (******st) -> palyze == -1 ){
    printf("麻痺無効 ");
  }
  else if ( (******st) -> palyze == -2 ){
    printf("麻痺吸収 ");
  }
  else if ( (******st) -> palyze == -3 ){
    printf("麻痺反射 ");
  }

  if ( (******st) -> charm == 200 ){
    printf("魅了弱点 ");
  }
  else if ( (******st) -> charm == 50 || (******st) -> charm == 25 ){
    printf("魅了耐性 ");
  }
  else if ( (******st) -> charm == -1 ){
    printf("魅了無効 ");
  }
  else if ( (******st) -> charm == -2 ){
    printf("魅了吸収 ");
  }
  else if ( (******st) -> charm == -3 ){
    printf("魅了反射 ");
  }

  if ( (******st) -> close == 200 ){
    printf("魔封弱点 ");
  }
  else if ( (******st) -> close == 50 || (******st) -> close == 25 ){
    printf("魔封耐性 ");
  }
  else if ( (******st) -> close == -1 ){
    printf("魔封無効 ");
  }
  else if ( (******st) -> close == -2 ){
    printf("魔封吸収 ");
  }
  else if ( (******st) -> close == -3 ){
    printf("魔封反射 ");
  }

  if ( (******st) -> stone == 200 ){
    printf("石化弱点 ");
  }
  else if ( (******st) -> stone == 50 || (******st) -> stone == 25 ){
    printf("石化耐性 ");
  }
  else if ( (******st) -> stone == -1 ){
    printf("石化無効 ");
  }
  else if ( (******st) -> stone == -2 ){
    printf("石化吸収 ");
  }
  else if ( (******st) -> stone == -3 ){
    printf("石化反射 ");
  }

  if ( (******st) -> panic == 200 ){
    printf("混乱弱点 ");
  }
  else if ( (******st) -> panic == 50 || (******st) -> panic == 25 ){
    printf("混乱耐性 ");
  }
  else if ( (******st) -> panic == -1 ){
    printf("混乱無効 ");
  }
  else if ( (******st) -> panic == -2 ){
    printf("混乱吸収 ");
  }
  else if ( (******st) -> panic == -3 ){
    printf("混乱反射 ");
  }

  if ( (******st) -> sleep == 200 ){
    printf("睡眠弱点 ");
  }
  else if ( (******st) -> sleep == 50 || (******st) -> sleep == 25 ){
    printf("睡眠耐性 ");
  }
  else if ( (******st) -> sleep == -1 ){
    printf("睡眠無効 ");
  }
  else if ( (******st) -> sleep == -2 ){
    printf("睡眠吸収 ");
  }
  else if ( (******st) -> sleep == -3 ){
    printf("睡眠反射 ");
  }

  if ( (******st) -> curse == 200 ){
    printf("呪い弱点 ");
  }
  else if ( (******st) -> curse == 50 || (******st) -> curse == 25 ){
    printf("呪い耐性 ");
  }
  else if ( (******st) -> curse == -1 ){
    printf("呪い無効 ");
  }
  else if ( (******st) -> curse == -2 ){
    printf("呪い吸収 ");
  }
  else if ( (******st) -> curse == -3 ){
    printf("呪い反射 ");
  }

  printf("\n");
}

void menu_player_status(Player ******st){
  int command;

  do{
    printf("<<<STATUS>>>\n");
    printf("%s:LV:%d EXP:%d NEXT EXP:%d\n", (*****st) -> name, (*****st) -> lv, (*****st) -> sumexp, (*****st) -> nextexp);
    printf("HP:%d/%d MP:%d/%d\n", (*****st) -> hp, (*****st) -> maxhp, (*****st) -> mp, (*****st) -> maxmp);
    printf("力:%d\n", (*****st) -> atk);
    printf("魔:%d\n", (*****st) -> magic);
    printf("体:%d\n", (*****st) -> str);
    printf("速:%d\n", (*****st) -> agi);
    printf("運:%d\n", (*****st) -> luk);

    printf("\n");
    menu_player_effective(&st);

    printf("\n");
    printf("戻る場合はcを入力してください。\n");
    command = _getch();
    if ( command == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }
  } while ( command != 'c' );
}

int menu_item_useselect(Player *******st, Player *******st2, Player *******st3, Items *******items){
  int item_target;
  int command;

  do{
    printf("使用する対象を選択してください(使用しない場合はcを入力)\n");
    if ( (******st) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("1:%s ", (******st) -> name);
    }

    if ( (******st2) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("2:%s ", (******st2) -> name);
    }

    if ( (******st3) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("3:%s ", (******st3) -> name);
    }
    printf("\n");

    command =  _getch();
    if ( command == '1' ){
      if ( (******st) -> badstatus == DEAD ){
        command = 'e'; //error
      }
      else{
        item_target = 1;
      }
    }
    else if ( command == '2' ){
      if ( (******st2) -> badstatus == DEAD ){
        command = 'e'; //error
      }
      else{
        item_target = 2;
      }
    }
    else if ( command == '3' ){
      if ( (******st3) -> badstatus == DEAD ){
        command = 'e'; //error
      }
      else{
        item_target = 3;
      }
    }
    else if ( command == 'c' ){
      item_target = 0;
    }

  }while ( command != '1' && command != '2' && command != '3' && command != 'c' );

  return item_target;

}

void menu_use_items_effect(Player *******st, Player *******st2, Player *******st3, int item_number, int item_target){
  int recover_point, beforehp;

  //傷薬
  if ( item_number == MEDICINE ){
    recover_point = 50;

    if ( item_target == PLAYER ){
      beforehp = (******st) -> hp;
      (******st) -> hp += recover_point;
      if ( (******st) -> hp >= (******st) -> maxhp ){
        (******st) -> hp = (******st) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st) -> name, beforehp, (******st) -> maxhp, (******st) -> hp, (******st) -> maxhp);
      printf("\n");
    }
    else if ( item_target == PLAYER2 ){
      beforehp = (******st2) -> hp;
      (******st2) -> hp += recover_point;
      if ( (******st2) -> hp >= (******st2) -> maxhp ){
        (******st2) -> hp = (******st2) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st2) -> name, beforehp, (******st2) -> maxhp, (******st2) -> hp, (******st2) -> maxhp);
      printf("\n");
    }
    else if ( item_target == PLAYER3 ){
      beforehp = (******st3) -> hp;
      (******st3) -> hp += recover_point;
      if ( (******st3) -> hp >= (******st3) -> maxhp ){
        (******st3) -> hp = (******st3) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st3) -> name, beforehp, (******st3) -> maxhp, (******st3) -> hp, (******st3) -> maxhp);
      printf("\n");
    }
  }
  else if ( item_number == LIFESTONE ){

    if ( item_target == PLAYER ){
      recover_point = (******st) -> maxhp * 0.25;
      beforehp = (******st) -> hp;
      (******st) -> hp += recover_point;
      if ( (******st) -> hp >= (******st) -> maxhp ){
        (******st) -> hp = (******st) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st) -> name, beforehp, (******st) -> maxhp, (******st) -> hp, (******st) -> maxhp);
      printf("\n");
    }
    else if ( item_target == PLAYER2 ){
      recover_point = (******st2) -> maxhp * 0.25;
      beforehp = (******st2) -> hp;
      (******st2) -> hp += recover_point;
      if ( (******st2) -> hp >= (******st2) -> maxhp ){
        (******st2) -> hp = (******st2) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st2) -> name, beforehp, (******st2) -> maxhp, (******st2) -> hp, (******st2) -> maxhp);
      printf("\n");
    }
    else if ( item_target == PLAYER3 ){
      recover_point = (******st3) -> maxhp * 0.25;
      beforehp = (******st3) -> hp;
      (******st3) -> hp += recover_point;
      if ( (******st3) -> hp >= (******st3) -> maxhp ){
        (******st3) -> hp = (******st3) -> maxhp;
      }
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st3) -> name, beforehp, (******st3) -> maxhp, (******st3) -> hp, (******st3) -> maxhp);
    }
  }
  else if ( item_number == BEAD ){  //宝玉
    if ( item_target == PLAYER ){
      beforehp = (******st) -> hp;
      recover_point = (******st) -> maxhp;
      (******st) -> hp = recover_point;
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st) -> name, beforehp, (******st) -> maxhp, (******st) -> hp, (******st) -> maxhp);
    }
    else if ( item_target == PLAYER2 ){
      beforehp = (******st2) -> hp;
      recover_point = (******st2) -> maxhp;
      (******st2) -> hp = recover_point;
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st2) -> name, beforehp, (******st2) -> maxhp, (******st2) -> hp, (******st2) -> maxhp);
    }
    else if ( item_target == PLAYER3 ){
      beforehp = (******st3) -> hp;
      recover_point = (******st3) -> maxhp;
      (******st3) -> hp = recover_point;
      printf("%s HP:%d/%d >> HP:%d/%d\n", (******st3) -> name, beforehp, (******st3) -> maxhp, (******st3) -> hp, (******st3) -> maxhp);
    }
  }
  else if ( item_number == ANTIPOISON ){
    if ( item_target == PLAYER ){
      if ( (******st) -> badstatus == POISON ){
        (******st) -> badstatus = GOOD;
        printf("%s(POISON) >> %s(GOOD)\n", (******st) -> name, (******st) -> name);
      }
      else{
        printf("%s:無効果!\n", (******st) -> name);
      }
      printf("\n");
    }
    else if ( item_target == PLAYER2 ){
      if ( (******st2) -> badstatus == POISON ){
        (******st2) -> badstatus = GOOD;
        printf("%s(POISON) >> %s(GOOD)\n", (******st2) -> name, (******st2) -> name);
      }
      else{
        printf("%s:無効果!\n", (******st2) -> name);
      }
      printf("\n");
    }
    else if ( item_target == PLAYER3 ){
      if ( (******st3) -> badstatus == POISON ){
        (******st3) -> badstatus = GOOD;
        printf("%s(POISON) >> %s(GOOD)\n", (******st3) -> name, (******st3) -> name);
      }
      else{
        printf("%s無効果!\n", (******st3) -> name);
      }
      printf("\n");
    }
  }
  else if ( item_number == ANTIPALYZE ){
    if ( item_target == PLAYER ){
      if ( (******st) -> badstatus == PALYZE ){
        (******st) -> badstatus = GOOD;
        printf("%s(PALYZE) >> %s(GOOD)\n", (******st) -> name, (******st) -> name);
      }
      else{
        printf("%s:無効果!\n", (******st) -> name);
      }
      printf("\n");
    }
    else if ( item_target == PLAYER2 ){
      if ( (******st2) -> badstatus == PALYZE ){
        (******st2) -> badstatus = GOOD;
        printf("%s(PALYZE) >> %s(GOOD)\n", (******st2) -> name, (******st2) -> name);
      }
      else{
        printf("%s:無効果!\n", (******st2) -> name);
      }
      printf("\n");
    }
    else if ( item_target == PLAYER3 ){
      if ( (******st3) -> badstatus == PALYZE ){
        (******st3) -> badstatus = GOOD;
        printf("%s(PALYZE) >> %s(GOOD)\n", (******st3) -> name, (******st3) -> name);
      }
      else{
        printf("%s:無効果!\n", (******st3) -> name);
      }
      printf("\n");
    }
  }
}

void menu_item_use(Player ******st, Player ******st2, Player ******st3, Items ******items, int command){
  int item_number, item_target;

  if ( command == '1' ){
    item_number = MEDICINE;
    item_target = menu_item_useselect(&st,&st2,&st3,&items);
    //printf("item_number:%d\n", item_number);
    //printf("item_target:%d\n", item_target);

    if ( item_target == NOTARGET ){
      //nothing
      return;
    }
    else if ( item_target == PLAYER ){
      (*****items) -> medicine--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    else if ( item_target == PLAYER2 ){
      (*****items) -> medicine--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    //item_target = 3
    else if ( item_target == PLAYER3 ){
      (*****items) -> medicine--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
  }
  else if ( command == '2' ){
    item_number = LIFESTONE;
    item_target = menu_item_useselect(&st,&st2,&st3,&items);
    //printf("item_number:%d\n", item_number);
    //printf("item_target:%d\n", item_target);

    if ( item_target == NOTARGET ){
      //nothing
      return;
    }
    else if ( item_target == PLAYER ){
      (*****items) -> lifestone--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    else if ( item_target == PLAYER2 ){
      (*****items) -> lifestone--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    //item_target = 3
    else if ( item_target == PLAYER3 ){
      (*****items) -> lifestone--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
  }
  else if ( command == '3' ){
    item_number = BEAD;
    item_target = menu_item_useselect(&st,&st2,&st3,&items);
    //printf("item_number:%d\n", item_number);
    //printf("item_target:%d\n", item_target);

    if ( item_target == NOTARGET ){
      //nothing
      return;
    }
    else if ( item_target == PLAYER ){
      (*****items) -> bead--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    else if ( item_target == PLAYER2 ){
      (*****items) -> bead--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    //item_target = 3
    else if ( item_target == PLAYER3 ){
      (*****items) -> bead--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
  }
  else if ( command == '4' ){
    item_number = ANTIPOISON;
    item_target = menu_item_useselect(&st,&st2,&st3,&items);
    //printf("item_number:%d\n", item_number);
    //printf("item_target:%d\n", item_target);

    if ( item_target == NOTARGET ){
      //nothing
      return;
    }
    else if ( item_target == PLAYER ){
      (*****items) -> antipoison--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    else if ( item_target == PLAYER2 ){
      (*****items) -> antipoison--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    //item_target = 3
    else if ( item_target == PLAYER3 ){
      (*****items) -> antipoison--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
  }
  else if ( command == '5' ){
    item_number = ANTIPALYZE;
    item_target = menu_item_useselect(&st,&st2,&st3,&items);
    //printf("item_number:%d\n", item_number);
    //printf("item_target:%d\n", item_target);

    if ( item_target == NOTARGET ){
      //nothing
      return;
    }
    else if ( item_target == PLAYER ){
      (*****items) -> antipalyze--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    else if ( item_target == PLAYER2 ){
      (*****items) -> antipalyze--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
    //item_target = 3
    else if ( item_target == PLAYER3 ){
      (*****items) -> antipalyze--;
      menu_use_items_effect(&st,&st2,&st3,item_number,item_target);
      printf("\n");
      return;
    }
  }
}

void equip_change(int command, int input, Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip){

  if ( input == '1' ){
    if ( command == '1' ){
      (******pEquip) -> HpRing1--;
      (******p2Equip) -> HpRing1--;
      (******p3Equip) -> HpRing1--;
      (******pEquip) -> isEquip = 1;
    }
    else if ( command == '2' ){
      (******pEquip) -> MpRing1--;
      (******p2Equip) -> MpRing1--;
      (******p3Equip) -> MpRing1--;
      (******pEquip) -> isEquip = 2;
    }
  }
  else if ( input == '2' ){
    if ( command == '1' ){
      (******pEquip) -> HpRing1--;
      (******p2Equip) -> HpRing1--;
      (******p3Equip) -> HpRing1--;
      (******p2Equip) -> isEquip = 1;
    }
    else if ( command == '2' ){
      (******pEquip) -> MpRing1--;
      (******p2Equip) -> MpRing1--;
      (******p3Equip) -> MpRing1--;
      (******p2Equip) -> isEquip = 2;
    }
  }
  else if ( input == '3' ){
    if ( command == '1' ){
      (******pEquip) -> HpRing1--;
      (******p2Equip) -> HpRing1--;
      (******p3Equip) -> HpRing1--;
      (******p3Equip) -> isEquip = 1;
    }
    else if ( command == '2' ){
      (******pEquip) -> MpRing1--;
      (******p2Equip) -> MpRing1--;
      (******p3Equip) -> MpRing1--;
      (******p3Equip) -> isEquip = 2;
    }
  }
  else{
    return;
  }

}

int equip_command_check(int command, Equip *******pEquip){  //pEquipもp2Equipもp3Equipも装備品の個数は連携しているので、pEquipのみでOK

  if ( command == '1' && (******pEquip) -> HpRing1 == 0 ){
    command = 'e';
  }
  if ( command == '2' && (******pEquip) -> MpRing1 == 0 ){
    command = 'e';
  }

  return command;
}

void isEquip_check(Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip){

  pEquip_temp = (******pEquip) -> isEquip;
  p2Equip_temp = (******p2Equip) -> isEquip;
  p3Equip_temp = (******p3Equip) -> isEquip;

  /*printf("%d\n", pEquip_temp);
  printf("%d\n", p2Equip_temp);
  printf("%d\n", p3Equip_temp);*/
}

//もともと装備していた装備を外して個数を1プラスする(元の個数に戻す)
void before_equip_plus(int input, Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip){

  if ( input == '1' ){
    if ( pEquip_temp != 0 ){
      if ( pEquip_temp == 1 ){
        (******pEquip) -> HpRing1++;
        (******p2Equip) -> HpRing1++;
        (******p3Equip) -> HpRing1++;
      }
      else if ( pEquip_temp == 2 ){
        (******pEquip) -> MpRing1++;
        (******p2Equip) -> MpRing1++;
        (******p3Equip) -> MpRing1++;
      }
      return;
    }
    else{
      return;
    }
  }
  else if ( input == '2' ){
    if ( p2Equip_temp != 0 ){
      if ( p2Equip_temp == 1 ){
        (******pEquip) -> HpRing1++;
        (******p2Equip) -> HpRing1++;
        (******p3Equip) -> HpRing1++;
      }
      else if ( p3Equip_temp == 2 ){
        (******pEquip) -> MpRing1++;
        (******p2Equip) -> MpRing1++;
        (******p3Equip) -> MpRing1++;
      }
      return;
    }
    else{
      return;
    }
  }
  else if ( input == '3' ){
    if ( p3Equip_temp != 0 ){
      if ( p3Equip_temp == 1 ){
        (******pEquip) -> HpRing1++;
        (******p2Equip) -> HpRing1++;
        (******p3Equip) -> HpRing1++;
      }
      else if ( p3Equip_temp == 2 ){
        (******pEquip) -> MpRing1++;
        (******p2Equip) -> MpRing1++;
        (******p3Equip) -> MpRing1++;
      }
      return;
    }
    else{
      return;
    }
  }
  else{
    return;
  }
}

void equip_effect(Player *******st, int input, Equip *******pEquip, Equip *******p2Equip, Equip *******p3Equip){
  int hpTemp, mpTemp;

  /*if ( pEquip_temp == (******pEquip) -> isEquip ){
  return;
}
else if ( p2Equip_temp == (******p2Equip) -> isEquip ){
return;
}
else if ( p3Equip_temp == (******p3Equip) -> isEquip ){
return;
}*/

if ( input == '1' ){  //player1
  if ( pEquip_temp == 0 ){
    if ( (******pEquip) -> isEquip == 1 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
    else if ( (******pEquip) -> isEquip == 2 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( pEquip_temp == 1 ){
    if ( (******pEquip) -> isEquip == 0 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
    }
    else if ( (******pEquip) -> isEquip == 2 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( pEquip_temp == 2 ){
    if ( (******pEquip) -> isEquip == 0 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
    }
    else if ( (******pEquip) -> isEquip == 1 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
  }
}
else if ( input == '2' ){  //player2
  if ( p2Equip_temp == 0 ){
    if ( (******p2Equip) -> isEquip == 1 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
    else if ( (******pEquip) -> isEquip == 2 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( p2Equip_temp == 1 ){
    if ( (******p2Equip) -> isEquip == 0 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
    }
    else if ( (******p2Equip) -> isEquip == 2 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( p2Equip_temp == 2 ){
    if ( (******p2Equip) -> isEquip == 0 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
    }
    else if ( (******p2Equip) -> isEquip == 1 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
  }
}
else if ( input == '3' ){  //player3
  if ( p3Equip_temp == 0 ){
    if ( (******p3Equip) -> isEquip == 1 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
    else if ( (******pEquip) -> isEquip == 2 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( p3Equip_temp == 1 ){
    if ( (******p3Equip) -> isEquip == 0 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
    }
    else if ( (******p3Equip) -> isEquip == 2 ){
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp -= (int)(hpTemp * 0.05);
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp += (int)(mpTemp * 0.05);
    }
  }
  else if ( p3Equip_temp == 2 ){
    if ( (******p3Equip) -> isEquip == 0 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
    }
    else if ( (******p3Equip) -> isEquip == 1 ){
      mpTemp = (******st) -> maxmp;
      (******st) -> maxmp -= (int)(mpTemp * 0.05);
      hpTemp = (******st) -> maxhp;
      (******st) -> maxhp += (int)(hpTemp * 0.05);
    }
  }
}
else{
  return;
}

}

void display_isEquip(Equip *******pEquip){

  if ( (******pEquip) -> isEquip == 0 ){
    printf("装備無し\n");
  }
  else if ( (******pEquip) -> isEquip == 1 ){
    printf("HPリング1\n");
  }
  else if ( (******pEquip) -> isEquip == 2 ){
    printf("MPリング1\n");
  }

}

void display_menu_isEquip(Equip ******pEquip){

  if ( (*****pEquip) -> isEquip == 0 ){
    printf("装備無し\n");
  }
  else if ( (*****pEquip) -> isEquip == 1 ){
    printf("HPリング1\n");
  }
  else if ( (*****pEquip) -> isEquip == 2 ){
    printf("MPリング1\n");
  }

}

void unequip(Player ******st, Player ******st2, Player ******st3, Equip ******pEquip, Equip ******p2Equip, Equip ******p3Equip){
  int input;

  do {
    printf("\n");
    printf("<<<EQUIP>>>\n");
    printf("誰の装備を外しますか?(cを入力することでキャンセル)\n");

    printf("1.%s ", (*****st) -> name);
    display_isEquip(&pEquip);

    printf("2.%s ", (*****st2) -> name);
    display_isEquip(&p2Equip);

    printf("3.%s ", (*****st3) -> name);
    display_isEquip(&p3Equip);

    input = _getch();

    if ( input == '1' && (*****pEquip) -> isEquip == 0 ){
      printf("何も装備していません!\n");
      return;
    }
    if ( input == '2' && (*****p2Equip) -> isEquip == 0 ){
      printf("何も装備していません!\n");
      return;
    }
    if ( input == '3' && (*****p3Equip) -> isEquip == 0 ){
      printf("何も装備していません!\n");
      return;
    }

    if ( input == '1' || input == '2' || input == '3' ){
      isEquip_check(&pEquip,&p2Equip,&p3Equip);
      before_equip_plus(input,&pEquip,&p2Equip,&p3Equip);
      if ( input == '1' ){
        (*****pEquip) -> isEquip = 0;
        equip_effect(&st,input,&pEquip,&p2Equip,&p3Equip);
      }
      else if ( input == '2' ){
        (*****p2Equip) -> isEquip = 0;
        equip_effect(&st2,input,&pEquip,&p2Equip,&p3Equip);
      }
      else if ( input == '3' ){
        (*****p3Equip) -> isEquip = 0;
        equip_effect(&st3,input,&pEquip,&p2Equip,&p3Equip);
      }
    }

  } while ( input != 'c' );
}

void display_equip_change(Player ******st, Equip ******pEquip, Equip ******p2Equip, Equip ******p3Equip, int input){
  int command;
  int equip_count;
  int loop;

  equip_count = 0;
  printf("\n");
  printf("<<<EQUIP>>>\n");

  if ( input == '1' ){
    printf("%s:", (*****st) -> name);
  }
  else if ( input == '2' ){
    printf("%s:", (*****st) -> name);
  }
  else if ( input == '3' ){
    printf("%s:", (*****st) -> name);
  }
  else{
    return;
  }

  if ( input == '1' ){
    display_isEquip(&pEquip);
  }
  else if ( input == '2' ){
    display_isEquip(&p2Equip);
  }
  else if ( input == '3' ){
    display_isEquip(&p3Equip);
  }
  printf("\n");

  loop = 0;
  do {
    if ( loop > 0 ){
      break;
    }

    printf("何を装備しますか?(cを入力することでmenu画面に戻ります)\n");
    if ( (*****pEquip) -> HpRing1 > 0 ){
      printf("1.HPリング1(味方1人の最大HPを5%%増加) %d個\n", (*****pEquip) -> HpRing1);
      equip_count = 1;
    }
    if ( (*****pEquip) -> MpRing1 > 0 ){
      printf("2.MPリング1(味方1人の最大MPを5%%増加) %d個\n", (*****pEquip) -> MpRing1);
      equip_count = 1;
    }

    if ( equip_count == 0 && (*****pEquip) -> isEquip == 0 && (*****p2Equip) -> isEquip == 0 && (*****p3Equip) -> isEquip == 0 ){
      printf("装備品を持っていません!\n");
      printf("\n");
      return;
    }

    if ( equip_count == 0 && ( (*****pEquip) -> isEquip != 0 || (*****p2Equip) -> isEquip != 0 || (*****p3Equip) -> isEquip != 0 ) ){
      printf("アイテムは全て装備されています\n");
      printf("\n");
      return;
    }

    command = _getch();  //装備品に対する入力
    if ( command != 'c' ){
      command = equip_command_check(command,&pEquip); //ユーザー入力をチェック
    }

    if ( command == '1' ){
      isEquip_check(&pEquip,&p2Equip,&p3Equip);
      before_equip_plus(input,&pEquip,&p2Equip,&p3Equip);
      equip_change(command,input,&pEquip,&p2Equip,&p3Equip);
      equip_effect(&st,input,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( command == '2' ){
      isEquip_check(&pEquip,&p2Equip,&p3Equip);
      before_equip_plus(input,&pEquip,&p2Equip,&p3Equip);
      equip_change(command,input,&pEquip,&p2Equip,&p3Equip);
      equip_effect(&st,input,&pEquip,&p2Equip,&p3Equip);
    }

    loop++;
  } while ( command != 'c' );


}

int skill_count_check(int count){

  if ( count > 11 ){
    return -1;
  }

  return count;
}

void change_set_player_skill_list(Setting_skill ***********setting_skill, int idx){

  if ( (**********setting_skill) -> set_skill[idx] == RECOVER1 ){
    printf("%d:ケディア\n", idx);
  }
  else if ( (**********setting_skill) -> set_skill[idx] == CUREPOISON ){
    printf("%d:キュアポ\n", idx);
  }
  else if ( (**********setting_skill) -> set_skill[idx] == RECOVER2 ){
    printf("%d:ケディアス\n", idx);
  }
  else if ( (**********setting_skill) -> set_skill[idx] == ENFA ){
    printf("%dエンファ\n", idx);
  }

}

void change_set_player_skill(P_skill ***********player_skill, Setting_skill ***********setting_skill, int afterSkillID, int input){
  int beforeSkillID = 0;

  if ( (**********setting_skill) -> set_skill[input] == RECOVER1 ){
    beforeSkillID = RECOVER1;
  }
  else if ( (**********setting_skill) -> set_skill[input] == CUREPOISON ){
    beforeSkillID = CUREPOISON;
  }
  else if ( (**********setting_skill) -> set_skill[input] == RECOVER2 ){
    beforeSkillID = RECOVER2;
  }
  else if ( (**********setting_skill) -> set_skill[input] == ENFA ){
    beforeSkillID = ENFA;
  }

  (**********setting_skill) -> set_skill[input] = afterSkillID;

  if ( beforeSkillID == RECOVER1 ){
    (**********player_skill) -> recover1[0] = LEARNED;
  }
  else if ( beforeSkillID == CUREPOISON ){
    (**********player_skill) -> cure_poison[0] = LEARNED;
  }
  else if ( beforeSkillID == RECOVER2 ){
    (**********player_skill) -> recover2[0] = LEARNED;
  }
  else if ( beforeSkillID == ENFA ){
    (**********player_skill) -> enfa[0] = LEARNED;
  }

}

void input_change_set_player_skill(P_skill **********player_skill, Setting_skill **********setting_skill, int skillID){
  int input;

  for ( int i = 0; i < 10; i++ ){
    change_set_player_skill_list(&setting_skill,i);
  }

  printf("どのスキルを変更しますか?\n");
  input = _getch();

  if ( input == '0' ){
    input = 0;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '1' ){
    input = 1;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '2' ){
    input = 2;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '3' ){
    input = 4;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '5' ){
    input = 5;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '6' ){
    input = 6;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '7' ){
    input = 7;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '8' ){
    input = 8;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else if ( input == '9' ){
    input = 9;
    change_set_player_skill(&player_skill,&setting_skill,skillID,input);
  }
  else{
    printf("スキルの変更を中止しました!\n");
  }

}

int set_player_skill(P_skill *********player_skill, Setting_skill *********setting_skill, int skillID){
  int input;

  for ( int i = 0; i < 10; i++ ){
    if ( (********setting_skill) -> set_skill[i] == 0 ){
      (********setting_skill) -> set_skill[i] = skillID;
      return TRUE;
    }
  }
  //スキル枠に空きがない場合
  printf("\n");
  printf("スキルは全てセットされています...\n");
  printf("セットされているスキルを変更しますか?\n");
  printf("1.Yes 2.No\n");
  input = _getch();

  if ( input == '1' ){
    input_change_set_player_skill(&player_skill,&setting_skill,skillID);
    printf("スキルを変更しました!\n");
    return TRUE;
  }
  else{
    printf("スキルの変更を中止しました...\n");
    return FALSE;
  }
  printf("\n");

}

int learned_PhysicalSkill_list(P_skill ********player_skill, Setting_skill ********setting_skill){

  return 0;
}

int learned_FireSkill_list(P_skill ********player_skill, Setting_skill ********setting_skill){
  int input;

  do{
    if ( (*******player_skill) -> enfa[0] == LEARNED ){
      printf("0:エンファ 消費MP:4 (単体に火炎小ダメージ)\n");
    }
    else if ( (*******player_skill) -> enfa[0] == SETTING ){
      printf("0:エンファ セット済み\n");
    }
    else if ( (*******player_skill) -> enfa[0] == LEARNING ){
      printf("0:エンファ 習得中\n");
    }

    printf("\n");
    printf("セットしたいスキルを選んでください(セットが終了したらcを入力してください)\n");

    input = _getch();

    if ( input == '0' && (*******player_skill) -> enfa[0] == LEARNED ){
      if ( set_player_skill(&player_skill,&setting_skill,ENFA) == TRUE ){
        (*******player_skill) -> enfa[0] = SETTING;
      }

    }

  }while ( input != 'c' );

  return 0;
}

void check_set_skillID(Setting_skill ********setting_skill, int idx){

  if ( (*******setting_skill) -> set_skill[idx] == RECOVER1 ){
    printf("%d:ケディア 消費MP:3 (味方1人のHP小回復)\n", idx);
  }
  else if ( (*******setting_skill) -> set_skill[idx] == CUREPOISON ){
    printf("%d:キュアポ 消費MP:4 (味方1人のPOISON状態を回復)\n", idx);
  }
  else if ( (*******setting_skill) -> set_skill[idx] == RECOVER2 ){

  }
  else if ( (*******setting_skill) -> set_skill[idx] == ENFA ){
    printf("%d:エンファ 消費MP:4 (単体に火炎小ダメージ)\n", idx);
  }

}

void set_skill_list(P_skill *******player_skill, Setting_skill *******setting_skill){
  int input;
  int count;

  count = 1;

  for ( int i = 0; i < 10; i++ ){
    if ( (******setting_skill) -> set_skill[i] != 0 ){
      check_set_skillID(&setting_skill,i);
    }
  }

  printf("\n");
  do {
    printf("セットしたいスキルを選んでください(セットが終了したらcを入力してください)\n");
    printf("1.物理スキル  ");
    printf("2.火炎スキル\n");
    printf("3.氷結スキル  ");
    printf("4.電撃スキル\n");
    printf("5.衝撃スキル  ");
    printf("6.万能スキル\n");
    printf("7.呪殺スキル  ");
    printf("8.破魔スキル\n");
    printf("9.回復スキル  ");
    printf("a.補助スキル\n");
    printf("b.状態異常スキル   ");
    printf("d.属性防御スキル   ");
    printf("e.自動効果スキル\n");
    printf("\n");

    input = _getch();

    if ( input == 'c' ){
      return;
    }

    if ( input == '1' ){
      learned_PhysicalSkill_list(&player_skill,&setting_skill);
    }
    else if ( input == '2' ){
      learned_FireSkill_list(&player_skill,&setting_skill);
    }
    else if ( input == '3' ){

    }
    else if ( input == '4' ){

    }
    else if ( input == '5' ){

    }
    else if ( input == '6' ){

    }
    else if ( input == '7' ){

    }
    else if ( input == '8' ){

    }
    else if ( input == '9' ){

    }
    else if ( input == 'a' ){

    }
    else if ( input == 'b' ){

    }
    else if ( input == 'd' ){

    }
    else if ( input == 'e' ){

    }
    else{

    }

  } while ( input != 'c' );

}

//昇順にソート
void sort_setting_skill(Setting_skill *******setting_skill){
  int i, j, temp;

  for ( i = 0; i < 10; i++ ){
    for ( j = i+1; j < 10; j++ ){
      if ( (******setting_skill) -> set_skill[i] > (******setting_skill) -> set_skill[j] ){
        temp = (******setting_skill) -> set_skill[i];
        (******setting_skill) -> set_skill[i] = (******setting_skill) -> set_skill[j];
        (******setting_skill) -> set_skill[j] = temp;
      }
    }
  }

  for ( i = 0; i < 10; i++ ){
    printf("%d\n", (******setting_skill) -> set_skill[i]);
  }
}

void skill_set(Player ******st, P_skill ******player_skill, Setting_skill ******setting_skill){
  int input;

  sort_setting_skill(&setting_skill);

  printf("\n");
  printf("<<<SET>>>\n");

  printf("---%s's skill---\n", (*****st) -> name);

  set_skill_list(&player_skill,&setting_skill);

}

void item_menu(Player *****st, Player *****st2, Player *****st3, Items *****items){
  int command;
  int items_count;

  //to check programs
  //(****items) -> medicine = 1;
  //(****items) -> lifestone = 1;
  //(****items) -> antipoison = 1;
  //(****items) -> antipalyze = 0;

  printf("<<<ITEM>>>\n");
  do{
    items_count = 0;
    if ( (****items) -> medicine > 0 ){
      printf("1.傷薬%d個(味方１人のHPを50回復)\n", (****items) -> medicine);
      items_count = 1;
    }
    if ( (****items) -> lifestone > 0 ){
      printf("2.魔石%d個(味方１人のHPを最大体力の25%%回復)\n", (****items) -> lifestone);
      items_count = 1;
    }
    if ( (****items) -> bead > 0 ){
      printf("3.宝玉%d個(味方1人の体力を全回復)\n", (****items) -> bead);
      items_count = 1;
    }
    if ( (****items) -> antipoison > 0 ){
      printf("4.アンタイポイズン%d個(味方1人のPOISONを回復)\n", (****items) -> antipoison);
      items_count = 1;
    }
    if ( (****items) -> antipalyze > 0 ){
      printf("5.アンタイパライズ%d個(味方1人のPALYZEを回復)\n", (****items) -> antipalyze);
      items_count = 1;
    }

    if ( items_count == 0 ){
      printf("ITEMを所持していません\n");
      return;
    }

    printf("\n");
    printf("使用しない場合はcを入力してください!\n");

    command =  _getch();
    if ( command == '1' && (****items) -> medicine > 0 ){
      menu_item_use(&st,&st2,&st3,&items, command);
    }
    else if ( command == '2' && (****items) -> lifestone > 0 ){
      menu_item_use(&st,&st2,&st3,&items, command);
    }
    else if ( command == '3' && (****items) -> bead > 0 ){
      menu_item_use(&st,&st2,&st3,&items, command);
    }
    else if ( command == '4' && (****items) -> antipoison > 0 ){
      menu_item_use(&st,&st2,&st3,&items,command);
    }
    else if ( command == '5' && (****items) -> antipalyze > 0 ){
      menu_item_use(&st,&st2,&st3,&items,command);
    }
    else if ( command == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }
  }while ( command != 'c' );

}

void check_skillMenuId(Setting_skill *******setting_skill, int idx){

  if ( (******setting_skill) -> set_skill[idx] == RECOVER1 ){
    printf("%d:ケディア 消費MP:3 (味方1人のHP小回復)\n", idx);
  }
  else if ( (******setting_skill) -> set_skill[idx] == CUREPOISON ){
    printf("%d:キュアポ 消費MP:4 (味方1人のPOISON状態を回復)\n", idx);
  }
  else if ( (******setting_skill) -> set_skill[idx] == RECOVER2 ){
    printf("%d:ケディアス\n");
  }
  else if ( (******setting_skill) -> set_skill[idx] == ENFA ){
    printf("%d:エンファ 消費MP:4 (単体に火炎小ダメージ)\n", idx);
  }
}

int select_skill_target_from_menu(Player ********st, Player ********st2, Player ********st3, int skillID){
  int input;

  if ( skillID == RECOVER2 ){
    return PARTYALL;
  }
  /*else if ( skillID == 死亡者に作用するスキル)*/
  else{
    printf("\n");
    printf("誰にスキルを使用しますか?\n");
    if ( (*******st) -> badstatus != DEAD ){
      printf("1:%s\n", (*******st) -> name);
    }
    if ( (*******st2) -> badstatus != DEAD ){
      printf("2:%s\n", (*******st2) -> name);
    }
    if ( (*******st3) -> badstatus != DEAD ){
      printf("3:%s\n", (*******st3) -> name);
    }

    input = _getch();

    if ( input == '1' && (*******st) -> badstatus != DEAD ){
      return PLAYER;
    }
    else if ( input == '2' && (*******st2) -> badstatus != DEAD ){
      return PLAYER2;
    }
    else if ( input == '3' && (*******st3) -> badstatus != DEAD ){
      return PLAYER3;
    }
    else{
      printf("スキルの使用を中止します...\n");
      return NOTARGET;
    }
  }

}

int check_playerMP_from_menu(Player *********st, int skillMP){

  if ( (********st) -> mp < skillMP ){
    printf("MP不足!\n");
    return FALSE;
  }
  else{
    return TRUE;
  }
}

void use_skill_from_menu(Player ********st, Player ********st2, Player ********st3, int skill_user, int skill_target, int skillID){
  int base, recover_point, beforehp;

  if ( skillID == RECOVER1 ){
    if ( skill_user == PLAYER ){
      printf("%s>>ケディア\n", (*******st) -> name);
      sleep(1);
      if ( check_playerMP_from_menu(&st,3) == TRUE ){
        (*******st) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (*******st) -> magic * 3 + (*******st) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == PLAYER ){
          beforehp = (*******st) -> hp;

          (*******st) -> hp += recover_point;
          if ( (*******st) -> hp >= (*******st) -> maxhp ){
            (*******st) -> hp = (*******st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st) -> name, beforehp, (*******st) -> maxhp, (*******st) -> hp, (*******st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER2 ){
          beforehp = (*******st2) -> hp;

          (*******st2) -> hp += recover_point;
          if ( (*******st2) -> hp >= (*******st2) -> maxhp ){
            (*******st2) -> hp = (*******st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st2) -> name, beforehp, (*******st2) -> maxhp, (*******st2) -> hp, (*******st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER3 ){
          beforehp = (*******st3) -> hp;

          (*******st3) -> hp += recover_point;
          if ( (*******st3) -> hp >= (*******st3) -> maxhp ){
            (*******st3) -> hp = (*******st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st3) -> name, beforehp, (*******st3) -> maxhp, (*******st3) -> hp, (*******st3) -> maxhp);
          printf("\n");
        }
      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>ケディア\n", (*******st2) -> name);
      sleep(1);
      if ( check_playerMP_from_menu(&st2,3) == TRUE ){
        (*******st2) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (*******st2) -> magic * 3 + (*******st2) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == PLAYER ){
          beforehp = (*******st) -> hp;

          (*******st) -> hp += recover_point;
          if ( (*******st) -> hp >= (*******st) -> maxhp ){
            (*******st) -> hp = (*******st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st) -> name, beforehp, (*******st) -> maxhp, (*******st) -> hp, (*******st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER2 ){
          beforehp = (*******st2) -> hp;

          (*******st2) -> hp += recover_point;
          if ( (*******st2) -> hp >= (*******st2) -> maxhp ){
            (*******st2) -> hp = (*******st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st2) -> name, beforehp, (*******st2) -> maxhp, (*******st2) -> hp, (*******st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER3 ){
          beforehp = (*******st3) -> hp;

          (*******st3) -> hp += recover_point;
          if ( (*******st3) -> hp >= (*******st3) -> maxhp ){
            (*******st3) -> hp = (*******st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st3) -> name, beforehp, (*******st3) -> maxhp, (*******st3) -> hp, (*******st3) -> maxhp);
          printf("\n");
        }
      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>ケディア\n", (*******st3) -> name);
      sleep(1);
      if ( check_playerMP_from_menu(&st3,3) == TRUE ){
        (*******st3) -> mp -= 3;

        base = 25;
        recover_point = (rand() % ( base + (*******st3) -> magic * 3 + (*******st3) -> luk - base + 1) ) + base; //(rand()%(max - min + 1)) + min;

        if ( skill_target == PLAYER ){
          beforehp = (*******st) -> hp;

          (*******st) -> hp += recover_point;
          if ( (*******st) -> hp >= (*******st) -> maxhp ){
            (*******st) -> hp = (*******st) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st) -> name, beforehp, (*******st) -> maxhp, (*******st) -> hp, (*******st) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER2 ){
          beforehp = (*******st2) -> hp;

          (*******st2) -> hp += recover_point;
          if ( (*******st2) -> hp >= (*******st2) -> maxhp ){
            (*******st2) -> hp = (*******st2) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st2) -> name, beforehp, (*******st2) -> maxhp, (*******st2) -> hp, (*******st2) -> maxhp);
          printf("\n");
        }
        else if ( skill_target == PLAYER3 ){
          beforehp = (*******st3) -> hp;

          (*******st3) -> hp += recover_point;
          if ( (*******st3) -> hp >= (*******st3) -> maxhp ){
            (*******st3) -> hp = (*******st3) -> maxhp;
          }

          printf("%s: HP:%d/%d >> HP:%d/%d\n", (*******st3) -> name, beforehp, (*******st3) -> maxhp, (*******st3) -> hp, (*******st3) -> maxhp);
          printf("\n");
        }
      }
    }
  }
  else if ( skillID == CUREPOISON ){
    if ( skill_user == PLAYER ){
      printf("%s>>キュアポ\n", (*******st) -> name);
      sleep(1);

      if ( check_playerMP_from_menu(&st,4) == TRUE ){
        (*******st) -> mp -= 4;

        if ( skill_target == PLAYER ){
          if ( (*******st) -> badstatus == POISON ){
            (*******st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER2 ){
          if ( (*******st2) -> badstatus == POISON ){
            (*******st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st2) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st2) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER3 ){
          if ( (*******st3) -> badstatus == POISON ){
            (*******st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st3) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st3) -> name);
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == PLAYER2 ){
      printf("%s>>キュアポ\n", (*******st2) -> name);
      sleep(1);

      if ( check_playerMP_from_menu(&st2,4) == TRUE ){
        (*******st2) -> mp -= 4;

        if ( skill_target == PLAYER ){
          if ( (*******st) -> badstatus == POISON ){
            (*******st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER2 ){
          if ( (*******st2) -> badstatus == POISON ){
            (*******st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st2) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st2) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER3 ){
          if ( (*******st3) -> badstatus == POISON ){
            (*******st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st3) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st3) -> name);
            printf("\n");
          }
        }

      }
    }
    else if ( skill_user == PLAYER3 ){
      printf("%s>>キュアポ\n", (*******st3) -> name);
      sleep(1);

      if ( check_playerMP_from_menu(&st3,4) == TRUE ){
        (*******st3) -> mp -= 4;

        if ( skill_target == PLAYER ){
          if ( (*******st) -> badstatus == POISON ){
            (*******st) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER2 ){
          if ( (*******st2) -> badstatus == POISON ){
            (*******st2) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st2) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st2) -> name);
            printf("\n");
          }
        }
        else if ( skill_target == PLAYER3 ){
          if ( (*******st3) -> badstatus == POISON ){
            (*******st3) -> badstatus = GOOD;
            printf("%s: STATUS(POISON) >> STATUS(GOOD)\n", (*******st3) -> name);
            printf("\n");
          }
          else{
            printf("%s:無効果\n", (*******st3) -> name);
            printf("\n");
          }
        }

      }
    }
  }

}

void procedure_skill_from_menu(Player *******st, Player *******st2, Player *******st3, P_skill *******player_skill, Setting_skill *******setting_skill, int input, int skill_user){
  int skill_target;
  int skillID;

  if ( (******setting_skill) -> set_skill[input] == RECOVER1 ){
    printf("OK\n");
    skill_target = select_skill_target_from_menu(&st,&st2,&st3,RECOVER1);
    skillID = RECOVER1;
  }
  else if ( (******setting_skill) -> set_skill[input] == CUREPOISON ){
    skill_target = select_skill_target_from_menu(&st,&st2,&st3,CUREPOISON);
    skillID = CUREPOISON;
  }
  else if ( (******setting_skill) -> set_skill[input] == RECOVER2 ){
    skill_target = select_skill_target_from_menu(&st,&st2,&st3,RECOVER2);
    skillID = RECOVER2;
  }

  use_skill_from_menu(&st,&st2,&st3,skill_user,skill_target,skillID);

}

void skill_menu_list(Player ******st, Player ******st2, Player ******st3, P_skill ******player_skill, Setting_skill ******setting_skill, int skill_user){
  int input;

  printf("<<<skill>>>\n");

  for ( int i = 0; i < 10; i++ ){
    check_skillMenuId(&setting_skill,i);
  }

  printf("使用したいスキルを選択してください(使用しない場合はcを入力)\n");
  input = _getch();

  if ( input == '0' && (*****setting_skill) -> set_skill[0] != 0 ){
    input = 0;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '1' && (*****setting_skill) -> set_skill[1] != 0 ){
    input = 1;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '2' && (*****setting_skill) -> set_skill[2] != 0 ){
    input = 2;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '3' && (*****setting_skill) -> set_skill[3] != 0 ){
    input = 3;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '4' && (*****setting_skill) -> set_skill[4] != 0 ){
    input = 4;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '5' && (*****setting_skill) -> set_skill[5] != 0 ){
    input = 5;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '6' && (*****setting_skill) -> set_skill[6] != 0 ){
    input = 6;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '7' && (*****setting_skill) -> set_skill[7] != 0 ){
    input = 7;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '8' && (*****setting_skill) -> set_skill[8] != 0 ){
    input = 8;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else if ( input == '9' && (*****setting_skill) -> set_skill[9] != 0 ){
    input = 9;
    procedure_skill_from_menu(&st,&st2,&st3,&player_skill,&setting_skill,input,skill_user);
  }
  else{
    printf("スキルの使用を中止しました!\n");
  }

}

void skill_menu(Player *****st, Player *****st2, Player *****st3, P_skill *****player_skill, P_skill *****player_skill2, P_skill *****player_skill3, Setting_skill *****setting_skill){
  int input;
  int skill_user;

  do{
    printf("<<<skill>>>\n");
    printf("\n");
    printf("スキルを使用する人を選択して下さい(終了する場合はcを入力)\n");
    printf("1.%s\n", (****st) -> name);
    printf("2.%s\n", (****st2) -> name);
    printf("3.%s\n", (****st3) -> name);

    input = _getch();

    printf("\n");
    if ( input == '1' ){
      skill_user = PLAYER;
      skill_menu_list(&st,&st2,&st3,&player_skill,&setting_skill,skill_user);
    }
    else if ( input == '2' ){
      skill_user = PLAYER2;
      skill_menu_list(&st,&st2,&st3,&player_skill,&setting_skill,skill_user);
    }
    else if ( input == '3' ){
      skill_user = PLAYER3;
      skill_menu_list(&st,&st2,&st3,&player_skill,&setting_skill,skill_user);
    }

  }while ( input != 'c' );
}

void equip_menu(Player *****st, Player *****st2, Player *****st3, Equip *****pEquip, Equip *****p2Equip, Equip *****p3Equip){

  int input;

  /*(****pEquip) -> isEquip = 0;
  (****p2Equip) -> isEquip = 0;
  (****p3Equip) -> isEquip = 0;
  (****pEquip) -> HpRing1 = 1;
  (****p2Equip) -> HpRing1 = 1;
  (****p3Equip) -> HpRing1 = 1;*/

  do {
    printf("\n");
    printf("<<<EQUIP>>>\n");
    printf("誰の装備を変更しますか?(戻る場合はcを入力してください)\n");
    printf("1:%s ", (****st) -> name);
    display_menu_isEquip(&pEquip);
    printf("2:%s ", (****st2) -> name);
    display_menu_isEquip(&p2Equip);
    printf("3:%s ", (****st3) -> name);
    display_menu_isEquip(&p3Equip);
    printf("\n");
    printf("d:装備を外す\n");

    input = _getch();

    if ( input == '1' ){
      display_equip_change(&st,&pEquip,&p2Equip,&p3Equip,input);
    }
    else if ( input == '2' ){
      display_equip_change(&st2,&pEquip,&p2Equip,&p3Equip,input);
    }
    else if ( input == '3' ){
      display_equip_change(&st3,&pEquip,&p2Equip,&p3Equip,input);
    }
    else if ( input == 'd' ){
      unequip(&st,&st2,&st3,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }

  } while ( input != 'c' );

}

void set_menu(Player *****st, Player *****st2, Player *****st3, P_skill *****player_skill, P_skill *****player_skill2, P_skill *****player_skill3, Setting_skill *****setting_skill, Setting_skill *****setting_skill2, Setting_skill *****setting_skill3){
  int input;

  do {
    printf("\n");
    printf("<<<SET>>>\n");
    printf("スキルをセットするキャラクターを選んでください(セットしない場合はcを入力してください)\n");
    printf("1:%s\n", (****st) -> name);
    printf("2:%s\n", (****st2) -> name);
    printf("3:%s\n", (****st3) -> name);

    /*(****player_skill) -> recover1 = 1;
    (****player_skill) -> cure_poison = 1;

    (****player_skill2) -> recover1 = 1;
    (****player_skill2) -> cure_poison = 1;

    (****player_skill3) -> recover1 = 1;
    (****player_skill3) -> cure_poison = 1;*/

    input = _getch();

    if ( input == '1' ){
      skill_set(&st,&player_skill,&setting_skill);
    }
    else if ( input == '2' ){
      skill_set(&st2,&player_skill2,&setting_skill2);
    }
    else if ( input == '3' ){
      skill_set(&st3,&player_skill3,&setting_skill3);
    }
    else{
      //nothing
    }

  } while ( input != 'c' );
}

void status_menu(Player *****st, Player *****st2, Player *****st3){
  int command;

  do{
    printf("\n");
    printf("<<<STATUS>>>\n");
    printf("誰のSTATUSを表示しますか?(戻る場合はcを入力してください。)\n");
    printf("1:%s\n", (****st) -> name);
    printf("2:%s\n", (****st2) -> name);
    printf("3:%s\n", (****st3) -> name);

    command =  _getch();

    if ( command == '1' ){
      menu_player_status(&st);
    }
    else if ( command == '2' ){
      menu_player_status(&st2);
    }
    else if ( command == '3' ){
      menu_player_status(&st3);
    }
    else if ( command == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }

  } while( command != 'c' );

}

void map_menu(Map ***map, Area *****area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]){
  int i, j, input;

  printf("P:現在地 *:歩いた場所\n");
  printf("<<<<<<<MAP>>>>>>\n");
  for ( j = 0; j < area_data_line; j++ ){
    printf("   ");
    for ( i = 0; i < area_data_len; i++ ){
      if ( automap_area[j][i] == -1 || automap_area[j][i] == 0 ){
        printf(" ");
      }
      else if ( j == (**map) -> y && i == (**map) -> x ){
        printf("P");
        //automap_area[j][i] = 'P';
      }
      else if ( automap_area[j][i] == 1 ){
        printf("*");
      }
    }
    printf("\n");
  }

  printf("\n");

  do{
    printf("mapを閉じるにはcを入力してください。\n");
    input = _getch();
  }while( input != 'c' );

  printf("\n");

}

void display_menu(Player ****st, Player ****st2, Player ****st3, P_skill ****player_skill, P_skill ****player_skill2, P_skill ****player_skill3, Setting_skill ****setting_skill, Setting_skill ****setting_skill2, Setting_skill ****setting_skill3, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip, Map **map, Area ****area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]){

  int menu_end, input, battle_display_condition_count;

  do{
    printf("\n");
    printf("------MENU--------\n");
    printf("|  1:ITEM        |\n");
    printf("|  2:SKILL       |\n");
    printf("|  3:EQUIP       |\n");
    printf("|  4:SET         |\n");
    printf("|  5:STATUS      |\n");
    printf("|  6:MAP         |\n");
    printf("------------------\n");
    printf("\n");
    printf("GOLD:%d\n", (***st) -> gold);
    printf("\n");
    printf("      %3s                   %3s                   %3s\n", (***st) -> name, (***st2) -> name, (***st3) -> name);
    printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d          HP:%d/%d MP:%d/%d\n", (***st) -> hp, (***st) -> maxhp, (***st) -> mp, (***st) -> maxmp, (***st2) -> hp, (***st2) -> maxhp, (***st2) -> mp, (***st2) -> maxmp, (***st3) -> hp, (***st3) -> maxhp, (***st3) -> mp, (***st3) -> maxmp);

    //HPをグラフィックに表現
    menu_hp_graphycal_display(&st,&st2,&st3);
    //MPをグラフィックに表現
    menu_mp_graphycal_display(&st,&st2,&st3);

    //partyの状態異常ステータスを表示
    battle_display_condition_count = 0;
    menu_display_condition(&st, battle_display_condition_count);

    battle_display_condition_count++;
    menu_display_condition(&st2, battle_display_condition_count);

    battle_display_condition_count++;
    menu_display_condition(&st3, battle_display_condition_count);

    battle_display_condition_count = 0;
    printf("\n");

    printf(" LV:%d", (***st) -> lv);
    printf("                  LV:%d", (***st2) -> lv);
    printf("                      LV:%d", (***st3) -> lv);
    printf("\n");

    printf("メニュー終了時はcを押してください!\n");

    input =  _getch();
    printf("入力：%c\n", input);
    if ( input == '1' ){
      item_menu(&st,&st2,&st3,&items);
    }
    else if ( input == '2' ){
      skill_menu(&st,&st2,&st3,&player_skill,&player_skill2,&player_skill3,&setting_skill);
    }
    else if ( input == '3' ){
      equip_menu(&st,&st2,&st3,&pEquip,&p2Equip,&p3Equip);
    }
    else if ( input == '4' ){
      set_menu(&st,&st2,&st3,&player_skill,&player_skill2,&player_skill3,&setting_skill,&setting_skill2,&setting_skill3);
    }
    else if ( input == '5' ){
      status_menu(&st,&st2,&st3);
    }
    else if ( input == '6' ){
      map_menu(&map,&area,area_data_line,area_data_len,automap_area);
    }
    else if ( input == ''){   //ctrl + C
      printf("error!\n");
      exit(EXIT_FAILURE);
    }

  }while( input != 'c' );

  //printf("上下左右キーを押してダンジョン画面に戻ります\n");

}
