#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>
#include <wchar.h>
#include "rpg.h"

//main関数

//メモ：構造体は相当な領域を使用することから構造体変数を関数に渡すのではなく、参照渡し(pointer)を行った方がよい

//プレイ時間に関するグローバルな型・変数
time_t start_time, end_time;
int play_time;

int tempArray[SIZE] = {0};  //処理量削減のための配列
/* tempArray[0]はスキルがLEARNINGになっているかの一時的な情報を保持


*/

int main(void){
  int load, input;   //input:プレイヤーの入力
  Player player;
  Player player2;
  Player player3;
  Items items = {0};
  Equip pEquip = {0};  //1人目のplayer
  Equip p2Equip = {0}; //2人目のメンバー
  Equip p3Equip = {0}; //3人目のメンバー

  Area area = {0};

  SearchDangeon search = {0};

  //boss_count = １ならばボス扱い
  //boss_count = 2ならば強制戦闘
  //enemy_skillが0以外なら敵はスキルを使用

  //Enemy pixie = {"ピクシー", 55, 55, 15, 15, 1, 3, 1, 5, 5, 3, 25, 40, 0, 100, 150, 100, 100, 50, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 101};
  //Enemy angel = {"エンジェル", 108, 108, 30, 30, 2, 5, 3, 5, 2, 4, 50, 100, 0, 100, 100, 100, 100, 150, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 1, 101};

  srand((unsigned int)time(NULL));

  P_skill player_skill = {0};
  P_skill player_skill2 = {0};
  P_skill player_skill3 = {0};
  Setting_skill setting_skill = {0};
  Setting_skill setting_skill2 = {0};
  Setting_skill setting_skill3 = {0};

  do{
    printf("MAIN MENU\n");
    printf("1:<<<LOAD GAME>>>\n");
    printf("2:<<<NEW  GAME>>>\n");
    printf("3:<<<DELETE SAVE DATA>>>\n");
    printf("4:<<<COPY SAVE DATA>>>\n");
    printf("5.<<<DEBUG MODE>>>\n");
    printf("1~6を入力してください(ゲームを起動しない場合はcを入力してください)\n");
    input = _getch();
    if ( input == '1' ){
      load = LOADGAME;
      save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
    }
    else if ( input == '2' ){
      //new gameでは、player.stage_clearは0
      //prologue();
      start_time = time(NULL);
      //printf("start_time:%d\n", start_time);
      game_start(&player, &player2, &player3);
      load = NEWGAME;
      game_story1(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &area);
      save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
    }
    else if ( input == '3' ){
      delete_saveData();
    }
    else if ( input == '4' ){
      copy_saveData();
    }
    else if ( input == '5' ){
      Debug_Mode(&player,&player2,&player3);
    }
    else if ( input == '' ){
      printf("強制終了\n");
      exit(EXIT_FAILURE);
    }
    else if ( input == 'c' ){
      printf("ゲームを終了します・・・\n");
      exit(EXIT_SUCCESS);
    }
  }while ( input != '1' && input != '2' && input != '3' );

  //printf("%d\n", player.stage_clear);
  load = 0;
  if ( player.stage_clear == 1 || player.stage_clear == 1.1 ){
    //start_time = time(NULL);
    game_story2(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items,&pEquip, &p2Equip, &p3Equip, &search, &area);//図書館ステージ
    save_load(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, load);
  }
  else if ( player.stage_clear == 2 ){
    //game_story3(&player, &player2, &player3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items,&pEquip, &p2Equip, &p3Equip, &search, &area);  //校舎2F
    printf("Wait・・・\n");
  }

  return 0;
}
