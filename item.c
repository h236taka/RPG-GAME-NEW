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

//アイテムに関するファイル

//アイテム使用者選択
int battle_item_useselect(Items *****items, Player *****st, Player *****st2, Player *****st3){
  //item_targetとはアイテムを使用する対象メンバー(主人公は１、２人目は２、３人目は３)
  int item_target;
  int command;

  do{
    printf("使用する対象を選択してください(使用しない場合はcを入力)\n");
    if ( (****st) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("1:%s ", (****st) -> name);
    }

    if ( (****st2) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("2:%s ", (****st2) -> name);
    }

    if ( (****st3) -> badstatus == DEAD ){
      //nothing
    }
    else{
      printf("3:%s ", (****st3) -> name);
    }
    printf("\n");

    command =  _getch();
    if ( command == '1' ){
      if ( (****st) -> badstatus == DEAD ){
        command = 'e';  //error
      }
      else{
        item_target = 1;
      }
    }
    else if ( command == '2' ){
      if ( (****st2) -> badstatus == DEAD ){
        command = 'e';
      }
      else{
        item_target = 2;
      }
    }
    else if ( command == '3' ){
      if ( (****st3) -> badstatus == DEAD ){
        command = 'e';
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

void battle_HPRecoverItem_process(Player ******st, int recover_point){
  int beforehp;

  beforehp = (*****st) -> hp;
  (*****st) -> hp += recover_point;
  if ( (*****st) -> hp >= (*****st) -> maxhp ){
    (*****st) -> hp = (*****st) -> maxhp;
  }
  printf("%s HP:%d/%d >> HP:%d/%d\n", (*****st) -> name, beforehp, (*****st) -> maxhp, (*****st) -> hp, (*****st) -> maxhp);

}

void battle_MPRecoverItem_process(Player ******st, int recover_point){
  int beforemp;

  beforemp = (*****st) -> mp;
  (*****st) -> mp += recover_point;
  if ( (*****st) -> mp >= (*****st) -> maxmp ){
    (*****st) -> mp = (*****st) -> maxmp;
  }
  printf("%s MP:%d/%d >> MP:%d/%d\n", (*****st) -> name, beforemp, (*****st) -> maxmp, (*****st) -> mp, (*****st) -> maxmp);

}

void battle_BadStatusRecoverItem_process(Player ******st, int Badstatus){

  if ( (*****st) -> badstatus == Badstatus ){
    (*****st) -> badstatus = GOOD;
    printf("%sの状態異常は消えた!\n", (*****st) -> name, (*****st) -> name);
  }
  else{
    printf("無効果!\n");
  }
  printf("\n");
}

//アイテム使用
void use_items_effect(Player *****st, Player *****st2, Player *****st3, int item_number, int item_target){
  int recover_point, beforehp;

  //傷薬
  if ( item_number == MEDICINE ){
    recover_point = 50;

    if ( item_target == PLAYER ){
      battle_HPRecoverItem_process(&st,recover_point);
    }
    else if ( item_target == PLAYER2 ){
      battle_HPRecoverItem_process(&st2,recover_point);
    }
    else if ( item_target == PLAYER3 ){
      battle_HPRecoverItem_process(&st3,recover_point);
    }
  }
  //魔石
  else if ( item_number == LIFESTONE ){
    if ( item_target == PLAYER ){
      recover_point = (****st) -> maxhp * 0.25;
      battle_HPRecoverItem_process(&st,recover_point);
    }
    else if ( item_target == PLAYER2 ){
      recover_point = (****st2) -> maxhp * 0.25;
      battle_HPRecoverItem_process(&st2,recover_point);
    }
    else if ( item_target == PLAYER3 ){
      recover_point = (****st3) -> maxhp * 0.25;
      battle_HPRecoverItem_process(&st3,recover_point);
    }
  }
  else if ( item_number == BEAD ){   //宝玉
    if ( item_target == PLAYER ){
      recover_point = (****st) -> maxhp;
      battle_HPRecoverItem_process(&st,recover_point);
    }
    else if ( item_target == PLAYER2 ){
      recover_point = (****st2) -> maxhp;
      battle_HPRecoverItem_process(&st2,recover_point);
    }
    else if ( item_target == PLAYER3 ){
      recover_point = (****st3) -> maxhp;
      battle_HPRecoverItem_process(&st3,recover_point);
    }
  }
  //antipoison
  else if ( item_number == ANTIPOISON ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,POISON);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,POISON);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,POISON);
    }
  }
  //antipalyze
  else if ( item_number == ANTIPALYZE ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,PALYZE);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,PALYZE);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,PALYZE);
    }
  }
  else if ( item_number == ANTICHARM ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,CHARM);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,CHARM);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,CHARM);
    }
  }
  else if ( item_number == ANTICLOSE ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,CLOSE);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,CLOSE);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,CLOSE);
    }
  }
  else if ( item_number == ANTISTONE ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,STONE);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,STONE);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,STONE);
    }
  }
  else if ( item_number == ANTIPANIC ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,PANIC);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,PANIC);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,PANIC);
    }
  }
  else if ( item_number == ANTISLEEP ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,SLEEP);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,SLEEP);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,SLEEP);
    }
  }
  else if ( item_number == ANTICURSE ){
    if ( item_target == PLAYER ){
      battle_BadStatusRecoverItem_process(&st,CURSE);
    }
    else if ( item_target == PLAYER2 ){
      battle_BadStatusRecoverItem_process(&st2,CURSE);
    }
    else if ( item_target == PLAYER3 ){
      battle_BadStatusRecoverItem_process(&st3,CURSE);
    }
  }
  else if ( item_number == MINDAMIN ){
    if ( item_target == PLAYER ){
      recover_point = (****st) -> maxmp * 0.20;
      battle_MPRecoverItem_process(&st,recover_point);
    }
    else if ( item_target == PLAYER2 ){
      recover_point = (****st2) -> maxmp * 0.20;
      battle_MPRecoverItem_process(&st2,recover_point);
    }
    else if ( item_target == PLAYER3 ){
      recover_point = (****st3) -> maxmp * 0.20;
      battle_MPRecoverItem_process(&st3,recover_point);
    }
  }
}

int battle_item_use(Items ****items, Player ****st, Player ****st2, Player ****st3){
  int items_count, item_target, item_number, turn_decrease, loop_count;
  int command;

  items_count = 0;
  //(***items) -> medicine = 10;
  //(***items) -> lifestone = 10;
  //(***items) -> bead = 2;

  loop_count = 0;
  do {
    printf("<<<<<<ITEMS>>>>>>\n");
    if ( (***items) -> medicine > 0 ){
      printf("1.傷薬%d個(味方１人のHPを50回復)\n", (***items) -> medicine);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> lifestone > 0 ){
      printf("2.魔石%d個(味方１人のHPを最大HPの25%%回復)\n", (***items) -> lifestone);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> bead > 0 ){
      printf("3.宝玉%d個(味方1人のHPを全回復)\n", (***items) -> bead);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> antipoison > 0 ){
      printf("4.アンタイポイズン%d個(味方1人のPOISONを回復)\n", (***items) -> antipoison);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> antipalyze > 0 ){
      printf("5.アンタイパライズ%d個(味方1人のPALYZEを回復)\n", (***items) -> antipalyze);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> anticharm > 0 ){
      printf("6.アンタイチャーム%d個(味方1人のCHARMを回復)\n", (***items) -> anticharm);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> anticlose > 0 ){
      printf("7.アンタイクローズ%d個(味方1人のCLOSEを回復)\n", (***items) -> anticlose);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> antistone > 0 ){
      printf("8.アンタイストーン%d個(味方1人のSTONEを回復)\n", (***items) -> antistone);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> antipanic > 0 ){
      printf("9.アンタイパニック%d個(味方1人のPANICを回復)\n", (***items) -> antipanic);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> antisleep > 0 ){
      printf("a.アンタイスリープ%d個(味方1人のSLEEPを回復)\n", (***items) -> antisleep);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> anticurse > 0 ){
      printf("b.アンタイカース%d個(味方1人のCURSEを回復)\n", (***items) -> anticurse);
      printf("\n");
      items_count++;
    }
    if ( (***items) -> mindamin > 0 ){
      printf("d.マインダミン%d個(味方１人のMPを最大MPの20%%回復)\n", (***items) -> mindamin);
      printf("\n");
      items_count++;
    }

    if ( items_count == 0 ){
      printf("使用可能なITEMはありません\n");
      printf("\n");
      turn_decrease = 0.0;
      //printf("turn_decrease:%d\n", turn_decrease);
      return turn_decrease;
    }

    printf("使用したいアイテムを選択してください(使用しない場合はcを入力)\n");
    command =  _getch();

    if ( command == '1' && (***items) -> medicine > 0 ){
      //傷薬はアイテムナンバー1
      item_number = MEDICINE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> medicine--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> medicine--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> medicine--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '2' && (***items) -> lifestone > 0 ){
      //魔石はアイテムナンバー2
      item_number = LIFESTONE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> lifestone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> lifestone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> lifestone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '3' && (***items) -> bead > 0 ){
      item_number = BEAD;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> bead--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> bead--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> bead--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '4' && (***items) -> antipoison > 0 ){
      item_number = ANTIPOISON;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> antipoison--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> antipoison--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> antipoison--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '5' && (***items) -> antipalyze > 0 ){
      item_number = ANTIPALYZE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> antipalyze--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> antipalyze--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> antipalyze--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '6' && (***items) -> anticharm > 0 ){
      item_number = ANTICHARM;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> anticharm--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> anticharm--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> anticharm--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '7' && (***items) -> anticlose > 0 ){
      item_number = ANTICLOSE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> anticlose--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> anticlose--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> anticlose--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '8' && (***items) -> antistone > 0 ){
      item_number = ANTISTONE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> antistone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> antistone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> antistone--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == '9' && (***items) -> antipanic > 0 ){
      item_number = ANTIPANIC;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> antipanic--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> antipanic--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> antipanic--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == 'a' && (***items) -> antisleep > 0 ){
      item_number = ANTISLEEP;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> antisleep--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> antisleep--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> antisleep--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == 'b' && (***items) -> anticurse > 0 ){
      item_number = ANTICURSE;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> anticurse--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> anticurse--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> anticurse--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == 'd' && (***items) -> mindamin > 0 ){
      item_number = MINDAMIN;
      item_target = battle_item_useselect(&items,&st,&st2,&st3);
      //printf("item_number:%d\n", item_number);
      //printf("item_target:%d\n", item_target);

      if ( item_target == NOTARGET ){
        //nothing
        turn_decrease = 0.0;
      }
      else if ( item_target == PLAYER ){
        (***items) -> mindamin--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      else if ( item_target == PLAYER2 ){
        (***items) -> mindamin--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
      //item_target = 3
      else if ( item_target == PLAYER3 ){
        (***items) -> mindamin--;
        use_items_effect(&st,&st2,&st3,item_number,item_target);
        turn_decrease = -1;
        loop_count++;
      }
    }
    else if ( command == 'c' ){
      turn_decrease = 0.0;
      loop_count++;
    }

  }while( loop_count == 0 );


  return turn_decrease;
}

int item_drop_caluculate(int drop_base, int drop_per){ //ドロップしたか計算
  int drop_count;

  drop_count = 0;

  for ( int i = 1; i <= drop_base; i++ ){
    if ( i == drop_per ){
      drop_count++;
      //printf("increment\n");
    }
  }

  return drop_count;
}

void item_drop(Player ****st, Player ****st2, Player ****st3, Enemy **enemy, Items ****items, int encount_pattern){
  int drop_per, drop_count, loop;
  double drop_base;

  loop = 0;
  drop_count = 0;
  //スライム
  if ( (*enemy) -> enemy_id == SLIME ){
    drop_base = 10;  //drop最低率は10%

    drop_base = drop_base + ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1 );
    if ( drop_base > 100 ){
      drop_base = 100;
    }
    //printf("before drop_base:%f\n", drop_base);
    drop_base = round(drop_base);
    //printf("after drop_base:%f\n", drop_base);

    if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
      while ( loop != encount_pattern ){
        drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
        drop_count += item_drop_caluculate(drop_base,drop_per);
        loop++;
      }
    }
    else{
      drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
      drop_count += item_drop_caluculate(drop_base,drop_per);
    }

    //printf("drop_count:%d\n", drop_count);

    if ( drop_count != 0 ){
      printf("DROP ITEM:傷薬×%d\n", drop_count);
      sleep(1);
      (***items) -> medicine += drop_count;
    }
  }
  //コボルト
  else if ( (*enemy) -> enemy_id == KOBALT ){
    drop_base = 15;  //drop最低率は15%

    drop_base = drop_base + ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1 );
    if ( drop_base > 100 ){
      drop_base = 100;
    }

    //printf("before drop_base:%f\n", drop_base);
    drop_base = round(drop_base);
    //printf("after drop_base:%f\n", drop_base);

    if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
      while ( loop != encount_pattern ){
        drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
        drop_count += item_drop_caluculate(drop_base,drop_per);
        loop++;
      }
    }
    else{
      drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
      drop_count += item_drop_caluculate(drop_base,drop_per);
    }

    //printf("drop_count:%d\n", drop_count);

    if ( drop_count != 0 ){
      printf("DROP ITEM:魔石×%d\n", drop_count);
      sleep(1);
      (***items) -> lifestone += drop_count;
    }

  }
  else if ( (*enemy) -> enemy_id == ZOMBIE ){
    drop_base = 15;

    drop_base = drop_base + ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1 );
    if ( drop_base > 100 ){
      drop_base = 100;
    }
    //printf("before drop_base:%f\n", drop_base);
    drop_base = round(drop_base);
    //printf("after drop_base:%f\n", drop_base);
    if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
      while ( loop != encount_pattern ){
        drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
        drop_count += item_drop_caluculate(drop_base,drop_per);
        loop++;
      }
    }
    else{
      drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
      drop_count += item_drop_caluculate(drop_base,drop_per);
    }

    //printf("drop_count:%d\n", drop_count);

    if ( drop_count != 0 ){
      printf("DROP ITEM:アンタイパライズ×%d\n", drop_count);
      sleep(1);
      (***items) -> antipalyze += drop_count;
    }
  }
  else if ( (*enemy) -> enemy_id == ONMORAKI ){
    drop_base = 8;

    drop_base = drop_base + ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1 );
    if ( drop_base > 100 ){
      drop_base = 100;
    }

    //printf("before drop_base:%f\n", drop_base);
    drop_base = round(drop_base);
    //printf("after drop_base:%f\n", drop_base);
    if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
      while ( loop != encount_pattern ){
        drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
        drop_count += item_drop_caluculate(drop_base,drop_per);
        loop++;
      }
    }
    else{
      drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
      drop_count += item_drop_caluculate(drop_base,drop_per);
    }

    //printf("drop_count:%d\n", drop_count);

    if ( drop_count != 0 ){
      printf("DROP ITEM:宝玉×%d\n", drop_count);
      sleep(1);
      (***items) -> bead += drop_count;
      return;
    }

    //レアドロップ判定
    drop_base = 1;
    drop_base = drop_base + ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1 );
    if ( drop_base > 100 ){
      drop_base = 100;
    }
    drop_base = round(drop_base);

    loop = 0;
    drop_count = 0;
    if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
      while ( loop != encount_pattern ){
        drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
        drop_count += item_drop_caluculate(drop_base,drop_per);
        loop++;
      }
    }
    else{
      drop_per = (rand() % ( 100 - 1 + 1 ) + 1);  //アイテムドロップ率の乱数
      drop_count += item_drop_caluculate(drop_base,drop_per);
    }

    if ( drop_count != 0 ){
      printf("DROP ITEM:オンモラキの破片×%d\n", drop_count);
      sleep(1);
      (***items) -> onmorakiPiece += drop_count;
      (***items) -> isGetRareDrop = ON;
      return;
    }

  }

}
