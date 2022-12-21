#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

//badstatus表示
void display_condition(Player ***st){

  if ( (**st) -> badstatus == GOOD ){
    printf("STATUS:GOOD\n");
  }
  else if ( (**st) -> badstatus == DEAD ){
    printf("STATUS:DEAD\n");
  }
  else if ( (**st) -> badstatus == POISON ){
    printf("STATUS:POISON\n");
  }
}

void display_status(Player **st, Player **st2, Player **st3){

  printf("パーティの能力を表示します\n");
  printf("\n");

  //主人公
  printf("%sの能力は・・・\n", (*st) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st) -> name, (*st) -> lv, (*st) -> sumexp, (*st) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st) -> hp, (*st) -> maxhp, (*st) -> mp, (*st) -> maxmp);

  display_condition(&st);

  printf("力:%d\n", (*st) -> atk);
  printf("魔:%d\n", (*st) -> magic);
  printf("体:%d\n", (*st) -> str);
  printf("速:%d\n", (*st) -> agi);
  printf("運:%d\n", (*st) -> luk);
  printf("GOLD:%d\n", (*st) -> gold);

  //２人目
  printf("%sの能力は・・・\n", (*st2) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st2) -> name, (*st2) -> lv, (*st2) -> sumexp, (*st2) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st2) -> hp, (*st2) -> maxhp, (*st2) -> mp, (*st2) -> maxmp);

  display_condition(&st2);

  printf("力:%d\n", (*st2) -> atk);
  printf("魔:%d\n", (*st2) -> magic);
  printf("体:%d\n", (*st2) -> str);
  printf("速:%d\n", (*st2) -> agi);
  printf("運:%d\n", (*st2) -> luk);

  //３人目
  printf("%sの能力は・・・\n", (*st3) -> name);
  printf("%s LV:%d EXP:%d NEXT EXP:%d\n", (*st3) -> name, (*st3) -> lv, (*st3) -> sumexp, (*st3) -> nextexp);
  printf("HP:%d/%d MP:%d/%d\n", (*st3) -> hp, (*st3) -> maxhp, (*st3) -> mp, (*st3) -> maxmp);

  display_condition(&st3);

  printf("力:%d\n", (*st3) -> atk);
  printf("魔:%d\n", (*st3) -> magic);
  printf("体:%d\n", (*st3) -> str);
  printf("速:%d\n", (*st3) -> agi);
  printf("運:%d\n", (*st3) -> luk);

  printf("\n");
}
