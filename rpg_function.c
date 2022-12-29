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

void buy_goods(Player ***st, Items ***items, int goods_number){
  int sum, count, price;
  int input;

  printf("何個購入しますか?(1~99個まで,入力が完了したらエンターキーを押してください)\n");
  scanf("%d", &count);

  if ( count < 1 || count > 99 ){
    printf("個数を入力し直してください\n");
    return;
  }

  if ( goods_number == 1 ){
    price = 100;
  }
  else if ( goods_number == 2 ){
    price = 150;
  }

  sum = 0;
  for ( int i = 1; i <= count; i++ ){
    sum += price;
    if ( (**st) -> gold < sum ){
      printf("\n");
      printf("所持金が足りません...\n");
      return;
    }
  }

  printf("\n");
  printf("%d個購入しました\n", count);
  printf("\n");

  (**st) -> gold -= sum;

  if ( goods_number == 1 ){
    (**items) -> medicine += count;
  }
  else if ( goods_number == 2 ){
    (**items) -> antipoison += count;
  }

}

void goods_shop(Player **st, Items **items){
  int input;
  int goods_number;

  do{
    sleep(1);
    printf("---SHOP---\n");
    printf("何を買いますか？(所持金: %dG)\n", (*st) -> gold);
    printf("1.傷薬:100G(味方１人のHPを50回復)\n");
    printf("2.アンタイポイズン:150G(味方1人のPOISONを回復)\n");
    printf("c.購入を止める\n");
    input = _getch();

    if ( input == '1' ){
      goods_number = 1;
      buy_goods(&st,&items,goods_number);
    }
    else if ( input == '2' ){
      goods_number = 2;
      buy_goods(&st,&items,goods_number);
    }
  } while ( input != 'c' );

}
