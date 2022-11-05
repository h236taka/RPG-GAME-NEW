#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

void hp_graphycal_display(Player ****st, Player ****st2, Player ****st3){

  printf(" ------------");
  printf("          ------------");
  printf("             ------------\n");

  if ( (***st) -> hp == (***st) -> maxhp ){
    printf(" |//////////|");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.9 ){
    printf(" |/////////||");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.8 ){
    printf(" |////////| |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.7 ){
    printf(" |///////|  |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.6 ){
    printf(" |//////|   |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.5 ){
    printf(" |/////|    |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.4 ){
    printf(" |////|     |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.3 ){
    printf(" |///|      |");
  }
  else if ( (***st) -> hp >= (***st) -> maxhp * 0.2 ){
    printf(" |//|       |");
  }
  else if ( (***st) -> hp > 0 ){
    printf(" |/|        |");
  }
  else if ( (***st) -> hp == 0 ){
    printf(" ||         |");
  }

  if ( (***st2) -> hp == (***st2) -> maxhp ){
    printf("          |//////////|");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.9 ){
    printf("          |/////////||");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.8 ){
    printf("          |////////| |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.7 ){
    printf("          |///////|  |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.6 ){
    printf("          |//////|   |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.5 ){
    printf("          |/////|    |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.4 ){
    printf("          |////|     |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.3 ){
    printf("          |///|      |");
  }
  else if ( (***st2) -> hp >= (***st2) -> maxhp * 0.2 ){
    printf("          |//|       |");
  }
  else if ( (***st2) -> hp > 0 ){
    printf("          |/|        |");
  }
  else if ( (***st2) -> hp == 0 ){
    printf("          ||         |");
  }

  if ( (***st3) -> hp == (***st3) -> maxhp ){
    printf("             |//////////|\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.9 ){
    printf("             |/////////||\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.8 ){
    printf("             |////////| |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.7 ){
    printf("             |///////|  |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.6 ){
    printf("             |//////|   |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.5 ){
    printf("             |/////|    |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.4 ){
    printf("             |////|     |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.3 ){
    printf("             |///|      |\n");
  }
  else if ( (***st3) -> hp >= (***st3) -> maxhp * 0.2 ){
    printf("             |//|       |\n");
  }
  else if ( (***st3) -> hp > 0 ){
    printf("             |/|        |\n");
  }
  else if ( (***st3) -> hp == 0 ){
    printf("             ||         |\n");
  }

  printf(" ------------");
  printf("          ------------");
  printf("             ------------\n");
}

void mp_graphycal_display(Player ****st, Player ****st2, Player ****st3){

  printf(" ------------");
  printf("          ------------");
  printf("             ------------\n");

  if ( (***st) -> mp == (***st) -> maxmp ){
    printf(" |//////////|");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.9 ){
    printf(" |/////////||");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.8 ){
    printf(" |////////| |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.7 ){
    printf(" |///////|  |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.6 ){
    printf(" |//////|   |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.5 ){
    printf(" |/////|    |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.4 ){
    printf(" |////|     |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.3 ){
    printf(" |///|      |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.2 ){
    printf(" |//|       |");
  }
  else if ( (***st) -> mp >= (***st) -> maxmp * 0.1 ){
    printf(" |/|        |");
  }
  else if ( (***st) -> mp == 0 ){
    printf(" ||         |");
  }

  if ( (***st2) -> mp == (***st2) -> maxmp ){
    printf("          |//////////|");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.9 ){
    printf("          |/////////||");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.8 ){
    printf("          |////////| |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.7 ){
    printf("          |///////|  |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.6 ){
    printf("          |//////|   |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.5 ){
    printf("          |/////|    |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.4 ){
    printf("          |////|     |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.3 ){
    printf("          |///|      |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.2 ){
    printf("          |//|       |");
  }
  else if ( (***st2) -> mp >= (***st2) -> maxmp * 0.1 ){
    printf("          |/|        |");
  }
  else if ( (***st2) -> mp == 0 ){
    printf("          ||         |");
  }

  if ( (***st3) -> mp == (***st3) -> maxmp ){
    printf("             |//////////|\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.9 ){
    printf("             |/////////||\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.8 ){
    printf("             |////////| |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.7 ){
    printf("             |///////|  |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.6 ){
    printf("             |//////|   |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.5 ){
    printf("             |/////|    |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.4 ){
    printf("             |////|     |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.3 ){
    printf("             |///|      |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.2 ){
    printf("             |//|       |\n");
  }
  else if ( (***st3) -> mp >= (***st3) -> maxmp * 0.1 ){
    printf("             |/|        |\n");
  }
  else if ( (***st3) -> mp == 0 ){
    printf("             ||         |\n");
  }

  printf(" ------------");
  printf("          ------------");
  printf("             ------------\n");
}

//Playerの状態を表示
void battle_display_condition(Player ****st, int battle_display_condition_count){

  if ( battle_display_condition_count == 0 ){
    if ( (***st) -> badstatus == GOOD ){
      printf(" STATUS:GOOD");
    }
    else if ( (***st) -> badstatus == DEAD ){
      printf(" STATUS:DEAD");
    }
    else if ( (***st) -> badstatus == POISON ){
      printf(" STATUS:POISON");
    }
    else if ( (***st) -> badstatus == PALYZE ){
      printf(" STATUS:PALYZE");
    }
    else if ( (***st) -> badstatus == CHARM ){
      printf(" STATUS:CHARM");
    }
    else if ( (***st) -> badstatus == CLOSE ){
      printf(" STATUS:CLOSE");
    }
    else if ( (***st) -> badstatus == STONE ){
      printf(" STATUS:STONE");
    }
    else if ( (***st) -> badstatus == PANIC ){
      printf(" STATUS:PANIC");
    }
    else if ( (***st) -> badstatus == SLEEP ){
      printf(" STATUS:SLEEP");
    }
    else if ( (***st) -> badstatus == CURSE ){
      printf(" STATUS:CURSE");
    }
  }
  else if ( battle_display_condition_count == 1 ){
    if ( (***st) -> badstatus == GOOD ){
      printf("           STATUS:GOOD");
    }
    else if ( (***st) -> badstatus == DEAD ){
      printf("           STATUS:DEAD");
    }
    else if ( (***st) -> badstatus == POISON ){
      printf("           STATUS:POISON");
    }
    else if ( (***st) -> badstatus == PALYZE ){
      printf("           STATUS:PALYZE");
    }
    else if ( (***st) -> badstatus == CHARM ){
      printf("           STATUS:CHARM");
    }
    else if ( (***st) -> badstatus == CLOSE ){
      printf("           STATUS:CLOSE");
    }
    else if ( (***st) -> badstatus == STONE ){
      printf("           STATUS:STONE");
    }
    else if ( (***st) -> badstatus == PANIC ){
      printf("           STATUS:PANIC");
    }
    else if ( (***st) -> badstatus == SLEEP ){
      printf("           STATUS:SLEEP");
    }
    else if ( (***st) -> badstatus == CURSE ){
      printf("           STATUS:CURSE");
    }
  }
  else{
    if ( (***st) -> badstatus == GOOD ){
      printf("              STATUS:GOOD");
    }
    else if ( (***st) -> badstatus == DEAD ){
      printf("              STATUS:DEAD");
    }
    else if ( (***st) -> badstatus == POISON ){
      printf("              STATUS:POISON");
    }
    else if ( (***st) -> badstatus == PALYZE ){
      printf("              STATUS:PALYZE");
    }
    else if ( (***st) -> badstatus == CHARM ){
      printf("              STATUS:CHARM");
    }
    else if ( (***st) -> badstatus == CLOSE ){
      printf("              STATUS:CLOSE");
    }
    else if ( (***st) -> badstatus == STONE ){
      printf("              STATUS:STONE");
    }
    else if ( (***st) -> badstatus == PANIC ){
      printf("              STATUS:PANIC");
    }
    else if ( (***st) -> badstatus == SLEEP ){
      printf("              STATUS:SLEEP");
    }
    else if ( (***st) -> badstatus == CURSE ){
      printf("              STATUS:CURSE");
    }
  }
}

void encount_pattern1_layout(Enemy ****enemy, int encount_pattern){
  if ( (***enemy) -> badstatus == GOOD ){
    printf("                         %s(GOOD)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == POISON ){
    printf("                         %s(POISON)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == PALYZE ){
    printf("                         %s(PALYZE)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == CHARM ){
    printf("                         %s(CHARM)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == CLOSE ){
    printf("                         %s(CLOSE)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == STONE ){
    printf("                         %s(STONE)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == PANIC ){
    printf("                         %s(PANIC)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == SLEEP ){
    printf("                         %s(SLEEP)\n", (***enemy) -> name);
  }
  else if ( (***enemy) -> badstatus == CURSE ){
    printf("                         %s(CURSE)\n", (***enemy) -> name);
  }
  printf("\n");
}

void encount_pattern2_layout(Enemy ****enemy, Enemy *enemy_copy1, int encount_pattern){

  if ( (***enemy) -> badstatus == GOOD ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(GOOD)            %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(GOOD)            %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(GOOD)            %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(GOOD)            %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(GOOD)            %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(GOOD)            %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(GOOD)            %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(GOOD)            %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(GOOD)            %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == DEAD ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("                                 %s(GOOD)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("                                 %s(POISON)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("                                 %s(PALYZE)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("                                 %s(CHARM)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("                                 %s(CLOSE)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("                                 %s(STONE)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("                                 %s(PANIC)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("                                 %s(SLEEP)\n", enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("                                 %s(CURSE)\n", enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == POISON ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == PALYZE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == CHARM ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(CHARM)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(CHARM)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(CHARM)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(CHARM)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(CHARM)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(CHARM)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(CHARM)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(CHARM)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(CHARM)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == CLOSE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(CLOSE)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(CLOSE)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(CLOSE)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(CLOSE)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(CLOSE)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(CLOSE)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(CLOSE)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(CLOSE)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(CLOSE)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == STONE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(STONE)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(STONE)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(STONE)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(STONE)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(STONE)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(STONE)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(STONE)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(STONE)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(STONE)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == PANIC ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(PANIC)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(PANIC)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(PANIC)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(PANIC)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(PANIC)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(PANIC)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(PANIC)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(PANIC)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(PANIC)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == SLEEP ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(SLEEP)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(SLEEP)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(SLEEP)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(SLEEP)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(SLEEP)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(SLEEP)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(SLEEP)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(SLEEP)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(SLEEP)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }
  else if ( (***enemy) -> badstatus == CURSE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      printf("             %s(CURSE)           %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      printf("             %s(CURSE)           %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      printf("             %s(CURSE)           %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      printf("             %s(CURSE)           %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      printf("             %s(CURSE)           %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      printf("             %s(CURSE)           %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      printf("             %s(CURSE)           %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      printf("             %s(CURSE)           %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      printf("             %s(CURSE)           %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name);
    }
  }

  if ( enemy_copy1 -> badstatus == DEAD ){
    if ( (***enemy) -> badstatus == GOOD ){
      printf("             %s(GOOD)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == POISON ){
      printf("             %s(POISON)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == PALYZE ){
      printf("             %s(PALYZE)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == CHARM ){
      printf("             %s(CHARM)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == CLOSE ){
      printf("             %s(CLOSE)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == STONE ){
      printf("             %s(STONE)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == PANIC ){
      printf("             %s(PANIC)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == SLEEP ){
      printf("             %s(SLEEP)               \n", (***enemy) -> name);
    }
    else if ( (***enemy) -> badstatus == CURSE ){
      printf("             %s(CURSE)               \n", (***enemy) -> name);
    }
  }
  printf("\n");

}

void encount_pattern3_layout(Enemy ****enemy, Enemy *enemy_copy1, Enemy * enemy_copy2, int encount_pattern){
  if ( (***enemy) -> badstatus == GOOD ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(GOOD)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(GOOD)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(GOOD)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(GOOD)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(GOOD)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(GOOD)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(GOOD)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(GOOD)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(GOOD)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(GOOD)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == DEAD ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(GOOD)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(GOOD)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(GOOD)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(GOOD)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(GOOD)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(GOOD)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(GOOD)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(GOOD)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(GOOD)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(GOOD)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("                        %s(GOOD)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("                        \n");
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("                        %s(POISON)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("                        %s(PALYZE)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("                        %s(CHARM)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("                        %s(CLOSE)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("                        %s(STONE)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("                        %s(PANIC)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("                        %s(SLEEP)\n", enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("                        %s(CURSE)\n", enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(POISON)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(POISON)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(POISON)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(POISON)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(POISON)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(POISON)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(POISON)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(POISON)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(POISON)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(POISON)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(PALYZE)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(PALYZE)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(PALYZE)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(PALYZE)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(PALYZE)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(PALYZE)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(PALYZE)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(PALYZE)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(PALYZE)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(PALYZE)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(CHARM)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(CHARM)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(CHARM)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(CHARM)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(CHARM)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(CHARM)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(CHARM)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(CHARM)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(CHARM)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(CHARM)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(CLOSE)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(CLOSE)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(CLOSE)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(CLOSE)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(CLOSE)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(CLOSE)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(CLOSE)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(CLOSE)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(CLOSE)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(CLOSE)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(STONE)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(STONE)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(STONE)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(STONE)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(STONE)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(STONE)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(STONE)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(STONE)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(STONE)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(STONE)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(PANIC)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(PANIC)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(PANIC)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(PANIC)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(PANIC)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(PANIC)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(PANIC)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(PANIC)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(PANIC)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(PANIC)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(SLEEP)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(SLEEP)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(SLEEP)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(SLEEP)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(SLEEP)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(SLEEP)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(SLEEP)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(SLEEP)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(SLEEP)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(SLEEP)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("              %s(CURSE)          %s(GOOD)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("              %s(CURSE)          \n", enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("              %s(CURSE)          %s(POISON)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("              %s(CURSE)          %s(PALYZE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("              %s(CURSE)          %s(CHARM)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("              %s(CURSE)          %s(CLOSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("              %s(CURSE)          %s(STONE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("              %s(CURSE)          %s(PANIC)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("              %s(CURSE)          %s(SLEEP)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("              %s(CURSE)          %s(CURSE)\n", enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == POISON ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(POISON)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(POISON)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(POISON)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(POISON)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(POISON)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(POISON)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(POISON)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(POISON)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(POISON)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(POISON)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == PALYZE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PALYZE)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PALYZE)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == CHARM ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CHARM)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CHARM)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CHARM)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CHARM)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CHARM)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CHARM)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CHARM)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CHARM)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CHARM)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CHARM)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == CLOSE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CLOSE)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CLOSE)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == STONE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(STONE)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(STONE)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(STONE)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(STONE)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(STONE)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(STONE)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(STONE)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(STONE)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(STONE)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(STONE)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == PANIC ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(PANIC)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(PANIC)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(PANIC)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(PANIC)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(PANIC)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(PANIC)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(PANIC)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(PANIC)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(PANIC)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(PANIC)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == SLEEP ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(SLEEP)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(SLEEP)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
  else if ( (***enemy) -> badstatus == CURSE ){
    if ( enemy_copy1 -> badstatus == GOOD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(GOOD)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(GOOD)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(GOOD)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(GOOD)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(GOOD)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(GOOD)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(GOOD)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(GOOD)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(GOOD)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(GOOD)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == DEAD ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)                      %s(GOOD)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)                      \n", (***enemy) -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)                      %s(POISON)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)                      %s(PALYZE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)                      %s(CHARM)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)                      %s(CLOSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)                      %s(STONE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)                      %s(PANIC)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)                      %s(SLEEP)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)                      %s(CURSE)\n", (***enemy) -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == POISON ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(POISON)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(POISON)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(POISON)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(POISON)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(POISON)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(POISON)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(POISON)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(POISON)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(POISON)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(POISON)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PALYZE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(PALYZE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(PALYZE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CHARM ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(CHARM)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(CHARM)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(CHARM)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(CHARM)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(CHARM)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(CHARM)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(CHARM)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(CHARM)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(CHARM)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(CHARM)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CLOSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(CLOSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(CLOSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == STONE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(STONE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(STONE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(STONE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(STONE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(STONE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(STONE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(STONE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(STONE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(STONE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(STONE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == PANIC ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(PANIC)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(PANIC)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(PANIC)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(PANIC)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(PANIC)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(PANIC)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(PANIC)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(PANIC)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(PANIC)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(PANIC)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == SLEEP ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(SLEEP)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(SLEEP)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
    else if ( enemy_copy1 -> badstatus == CURSE ){
      if ( enemy_copy2 -> badstatus == GOOD ){
        printf("  %s(CURSE)            %s(CURSE)          %s(GOOD)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == DEAD ){
        printf("  %s(CURSE)            %s(CURSE)          \n", (***enemy) -> name, enemy_copy1 -> name);
      }
      else if ( enemy_copy2 -> badstatus == POISON ){
        printf("  %s(CURSE)            %s(CURSE)          %s(POISON)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PALYZE ){
        printf("  %s(CURSE)            %s(CURSE)          %s(PALYZE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CHARM ){
        printf("  %s(CURSE)            %s(CURSE)          %s(CHARM)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CLOSE ){
        printf("  %s(CURSE)            %s(CURSE)          %s(CLOSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == STONE ){
        printf("  %s(CURSE)            %s(CURSE)          %s(STONE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == PANIC ){
        printf("  %s(CURSE)            %s(CURSE)          %s(PANIC)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == SLEEP ){
        printf("  %s(CURSE)            %s(CURSE)          %s(SLEEP)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
      else if ( enemy_copy2 -> badstatus == CURSE ){
        printf("  %s(CURSE)            %s(CURSE)          %s(CURSE)\n", (***enemy) -> name, enemy_copy1 -> name, enemy_copy2 -> name);
      }
    }
  }
}
