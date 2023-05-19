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

extern int tempArray[SIZE];
//encountpatternが1~4のとき

int check_enemyDeadCount1(Enemy **enemy){
  int enemy_deadcount;

  enemy_deadcount = 1;
  if ( (*enemy) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  return enemy_deadcount;
}

int check_enemyDeadCount2(Enemy **enemy, Enemy *enemy_copy1){
  int enemy_deadcount;

  enemy_deadcount = 2;
  if ( (*enemy) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy1 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  return enemy_deadcount;
}

int check_enemyDeadCount3(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2){
  int enemy_deadcount;

  enemy_deadcount = 3;
  if ( (*enemy) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy1 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy2 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  return enemy_deadcount;
}

int check_enemyDeadCount4(Enemy **enemy, Enemy *enemy_copy1, Enemy *enemy_copy2, Enemy *enemy_copy3){
  int enemy_deadcount;

  enemy_deadcount = 4;
  if ( (*enemy) -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy1 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy2 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  if ( enemy_copy3 -> badstatus == DEAD ){
    //nothing
  }
  else{
    enemy_deadcount--;
  }

  return enemy_deadcount;
}

void player_badstatus_recover(Player ****st){

  if ( (***st) -> badstatus == GOOD || (***st) -> badstatus == POISON || (***st) -> badstatus == DEAD || (***st) -> badstatus == CLOSE || (***st) -> badstatus == CURSE ){
    //ステータスはそのまま
  }
  else{
    (***st) -> badstatus = GOOD;
  }

}

int is_backAttack(Player ****st, Player ****st2, Player ****st3){
  int backAttackPer;
  int backAttackBase;

  backAttackBase = 30 - ( (***st) -> luk * 0.1 + (***st2) -> luk * 0.1 + (***st3) -> luk * 0.1);
  if ( backAttackBase <= 0 ){
    backAttackBase = 1;
  }
  //backAttackBase = 100;

  backAttackPer = (rand() % ( 100 - 1 + 1 ) + 1);

  for ( int i = 0; i < backAttackBase; i++ ){
    if ( i == backAttackPer ){
      printf("\a");
      printf("敵の先制攻撃!\n");
      return TRUE;
    }
  }

  return FALSE;
}

//敵１種類の戦闘関数
void game_battle(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, Enemy *enemy, int encount_pattern){  //構造体のポインタを引数にまたポインタ指定（ダブルポインタ)

  int player_damage, skill_damage, enemy_damage, enemy_move, player_guard, player_guard2, player_guard3, move_finish;
  int skill_count, use_skill_count, skill_reaction, recover_point, battle_display_condition_count, enemy_temp;
  int result_exp, result_gold;
  int command;
  int skill_command;
  int skill_target, skill_user;
  double player_turn, enemy_turn, turn_decrease, enemy_turn_temp;
  int enemy_deadcount;
  int backAttack;

  Enemy enemy_copy1;
  Enemy enemy_copy2;
  Enemy enemy_copy3;

  if ( enemy -> boss_count == 0 ){
    printf("------NORMAL BATTLE------\n");
    printf("\a");
    sleep(1);
    if ( encount_pattern == 1 ){
      printf("%sが現れた!\n", enemy -> name);
      enemy_temp = 1;
      sleep(1);
    }
    else if ( encount_pattern == 2 ){   //同じ敵2体
      printf("%sが２体が現れた!\n", enemy -> name);
      enemy_temp = 2;
      enemy_data_copy(&enemy,&enemy_copy1);
    }
    else if ( encount_pattern == 3 ){   //同じ敵３体
      printf("%sが３体が現れた!\n", enemy -> name);
      enemy_temp = 3;
      enemy_data_copy(&enemy,&enemy_copy1);
      enemy_data_copy(&enemy,&enemy_copy2);
    }
    else if ( encount_pattern == 4 ){   //同じ敵４体
      printf("%sが４体が現れた!\n", enemy -> name);
      enemy_temp = 4;
      enemy_data_copy(&enemy,&enemy_copy1);
      enemy_data_copy(&enemy,&enemy_copy2);
      enemy_data_copy(&enemy,&enemy_copy3);
    }
    printf("\n");
    sleep(1);

    //バックアタックかどうかチェック(敵の先制攻撃か)
    backAttack = FALSE;
    if ( is_backAttack(&st,&st2,&st3) == TRUE ){
      backAttack = TRUE;
      //printf("OK\n");
    }
  }
  else if ( enemy -> boss_count == 2 ){
    printf("------MID BOSS BATTLE------\n");
    printf("\a");
    sleep(1);
    if ( encount_pattern == 1 ){
      printf("%sが現れた!\n", enemy -> name);
      enemy_temp = 1;
      sleep(1);
    }
    else if ( encount_pattern == 2 ){   //同じ敵2体
      printf("%sが２体が現れた!\n", enemy -> name);
      enemy_temp = 2;
      enemy_data_copy(&enemy,&enemy_copy1);
    }
    else if ( encount_pattern == 3 ){   //同じ敵３体
      printf("%sが３体が現れた!\n", enemy -> name);
      enemy_temp = 3;
      enemy_data_copy(&enemy,&enemy_copy1);
      enemy_data_copy(&enemy,&enemy_copy2);
    }
    else if ( encount_pattern == 4 ){   //同じ敵４体
      printf("%sが４体が現れた!\n", enemy -> name);
      enemy_temp = 4;
      enemy_data_copy(&enemy,&enemy_copy1);
      enemy_data_copy(&enemy,&enemy_copy2);
      enemy_data_copy(&enemy,&enemy_copy3);
    }
    printf("\n");
    sleep(1);
  }
  else{
    printf("<<<<<<<BOSS BATTLE>>>>>>>\n");
    sleep(1);
    printf("\a");
    if ( encount_pattern == 1 ){
      printf("%sが現れた!\n", enemy -> name);
      enemy_temp = 1;
      sleep(1);
    }
    printf("\n");
    sleep(1);
  }

  player_turn = 3;
  //味方パーティが生きている人数を初期プレイヤーターンとして設定
  if ( (**st) -> badstatus == DEAD ){
    player_turn--;
  }
  if ( (**st2) -> badstatus == DEAD ){
    player_turn--;
  }
  if ( (**st3) -> badstatus == DEAD ){
    player_turn--;
  }

  enemy_deadcount = 0; //enemyが死んだか判定
  skill_count = 0; //skillがあるか判定
  use_skill_count = 0; //skillの使用に関する判定
  do {
    skill_reaction = 1;
    if ( backAttack == FALSE ){
      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");
      //戦闘画面のレイアウト
      if ( encount_pattern == 1 ){
        encount_pattern1_layout(&enemy,encount_pattern);
      }
      else if ( encount_pattern == 2 ){
        encount_pattern2_layout(&enemy,&enemy_copy1,encount_pattern);
      }
      else if ( encount_pattern == 3 ){
        encount_pattern3_layout(&enemy, &enemy_copy1, &enemy_copy2, encount_pattern);
      }
      else if ( encount_pattern == 4 ){
        encount_pattern4_layout(&enemy, &enemy_copy1, &enemy_copy2, &enemy_copy3, encount_pattern);
      }
      else{
        printf("EncountPatternが存在しません\n");
        return;
      }
      printf("\n");

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");
    }
    else{
      //printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
    }
    printf("\n");
    //player_turnの処理
    //主人公のターン
    player_turn = 3;
    do{
      if ( backAttack == TRUE ){
        backAttack = FALSE;
        break;
      }
      do{
        move_finish = 0;  //各playerがplayer_turnが減少する行動を行ったら1になる
        player_guard = 0; //主人公のガードを使用に関する判定
        if ( (**st) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st) -> name);
          printf("\n");
          move_finish++;
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
        }
        else{
          display_player_turn(&st, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 1 ){   //敵１体
              turn_decrease = player_attack_for_enemy(&st, &enemy, &enemy_deadcount);
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish++;
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){    //敵2体
              do{
                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target2(&enemy,&enemy_copy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy1, &enemy_deadcount);  //本当はenemy_copy1だがenemy_copy1はenemyと同じステータス
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){   //敵３体
              do{

                command = player_normal_attack_target3(&enemy,&enemy_copy1,&enemy_copy2);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1,２,3のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' );
              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){   //敵４体
              do{

                command = player_normal_attack_target4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '4' ){
                  turn_decrease = player_attack_for_enemyCopy(&st, &enemy_copy3, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '9' ){
                  break;
                }
                else{
                  printf("1,2,3,4のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' && command != '4' );
              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }
          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill,&setting_skill);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill) -> set_skill[0] != 0 ){
                    skill_user = PLAYER;

                    use_skill_count = (**setting_skill) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill) -> set_skill[1] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill) -> set_skill[2] != 0 ){
                    skill_user = PLAYER;

                    use_skill_count = (**setting_skill) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill) -> set_skill[3] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill) -> set_skill[4] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill) -> set_skill[5] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill) -> set_skill[6] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill) -> set_skill[7] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill) -> set_skill[8] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill) -> set_skill[9] != 0 ){
                    skill_user = PLAYER;
                    use_skill_count = (**setting_skill) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st,&player_skill,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st,&player_skill,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }

          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard++;
            move_finish++;
            turn_decrease = -1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);

          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            //printf("turn_decrease:%f\n", turn_decrease);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st) == 1 ){
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              player_turn = 0;
              move_finish = 1;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 1 ){
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){
              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){
              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }

            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st);
          }
        }
        //printf("enemy_deadcount:%d\n", enemy_deadcount);
      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

      if ( player_turn == 0 ){
        break;
      }

      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");

      //戦闘画面のレイアウト
      if ( encount_pattern == 1 ){
        encount_pattern1_layout(&enemy,encount_pattern);
      }
      else if ( encount_pattern == 2 ){
        encount_pattern2_layout(&enemy,&enemy_copy1,encount_pattern);
      }
      else if ( encount_pattern == 3 ){
        encount_pattern3_layout(&enemy,&enemy_copy1,&enemy_copy2,encount_pattern);
      }

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");

      do{
        //２人目のターン
        move_finish = 0;
        player_guard2 = 0;

        if ( (**st2) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st2) -> name);
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
          move_finish++;
        }
        else{
          //printf("%f\n", player_turn);
          display_player_turn(&st2, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 1 ){   //敵１体
              turn_decrease = player_attack_for_enemy(&st2, &enemy, &enemy_deadcount);
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish++;
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){    //敵2体
              do{

                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target2(&enemy,&enemy_copy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st2, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){   //敵３体
              do{

                command = player_normal_attack_target3(&enemy,&enemy_copy1,&enemy_copy2);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st2, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1,2,3のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' );
              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){   //敵４体
              do{

                command = player_normal_attack_target4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st2, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command =='2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '4' ){
                  turn_decrease = player_attack_for_enemyCopy(&st2, &enemy_copy3, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1,2,3,4のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' && command != '4' );
              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }

          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill2,&setting_skill2);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill2) -> set_skill[0] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill2) -> set_skill[1] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill2) -> set_skill[2] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill2) -> set_skill[3] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill2) -> set_skill[4] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill2) -> set_skill[5] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill2) -> set_skill[6] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill2) -> set_skill[7] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill2) -> set_skill[8] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill2) -> set_skill[9] != 0 ){
                    skill_user = PLAYER2;
                    use_skill_count = (**setting_skill2) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill2,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st2,&player_skill2,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st2,&player_skill2,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }
          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard2++;
            turn_decrease = -1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish++;
          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st2) == 1 ){
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              move_finish = 1;
              player_turn = 0;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard2 = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 1 ){
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){
              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){
              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }
            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st2) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st2);
          }
        }
      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

      if ( player_turn == 0 ){
        break;
      }

      printf("                 <<<<<<<PLAYER TURN>>>>>>>\n");
      printf("\n");

      //戦闘画面のレイアウト
      if ( encount_pattern == 1 ){
        encount_pattern1_layout(&enemy,encount_pattern);
      }
      else if ( encount_pattern == 2 ){
        encount_pattern2_layout(&enemy,&enemy_copy1,encount_pattern);
      }
      else if ( encount_pattern == 3 ){
        encount_pattern3_layout(&enemy,&enemy_copy1,&enemy_copy2,encount_pattern);
      }

      printf("       %2s                  %2s                 %2s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);

      printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d        HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);

      //HPをグラフィックに表現
      hp_graphycal_display(&st,&st2,&st3);
      //MPをグラフィックに表現
      mp_graphycal_display(&st,&st2,&st3);

      //partyの状態異常ステータスを表示
      battle_display_condition_count = 0;
      battle_display_condition(&st, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st2, battle_display_condition_count);

      battle_display_condition_count++;
      battle_display_condition(&st3, battle_display_condition_count);
      battle_display_condition_count = 0;
      printf("\n");
      printf("\n");

      do{
        move_finish = 0;
        player_guard3 = 0;

        if ( (**st3) -> badstatus == DEAD ){
          printf("%sは死んでいて行動できない!\n", (**st3) -> name);
          turn_decrease = -1;
          player_turn = calculate_player_turn(player_turn, turn_decrease);
          move_finish++;
        }
        else{
          //printf("%f\n", player_turn);
          display_player_turn(&st3, player_turn);
          printf("1.ATTACK 2.SKILL 3.GUARD 4.ITEMS 5.ESCAPE 6.NEXT TURN\n");
          printf("\n");
          printf("1~6を入力してください\n");
          command =  _getch();
          if ( command == '1' ){   //攻撃コマンド
            if ( encount_pattern == 1 ){   //敵１体
              turn_decrease = player_attack_for_enemy(&st3, &enemy, &enemy_deadcount);
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish++;
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){    //敵2体
              do{

                //どちらの敵に攻撃するかチェック
                command = player_normal_attack_target2(&enemy,&enemy_copy1);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st3, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1か２を入力してください\n");
                }
              }while ( command != '1' && command != '2' );
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){   //敵３体
              do{

                command = player_normal_attack_target3(&enemy,&enemy_copy1,&enemy_copy2);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st3, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1,２,3のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' );

              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){   //敵４体
              do{

                command = player_normal_attack_target4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);

                if ( command == '1' ){
                  turn_decrease = player_attack_for_enemy(&st3, &enemy, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '2' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy1, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '3' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy2, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == '4' ){
                  turn_decrease = player_attack_for_enemyCopy(&st3, &enemy_copy3, &enemy_deadcount);
                  player_turn = calculate_player_turn(player_turn, turn_decrease);
                  move_finish++;
                }
                else if ( command == 'c' ){
                  break;
                }
                else{
                  printf("1,2,3,4のいずれかを入力してください\n");
                }
              }while ( command != '1' && command != '2' && command != '3' && command != '4' );

              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }
          }
          else if ( command == '2' ){ //skillコマンド
            skill_count = battle_player_skill_list(&player_skill3,&setting_skill3);

            if ( skill_count != 0 ){
              do {
                skill_target = NOTARGET;
                printf("使用したいSKILL番号を入力してください! (使用しない場合はcを入力してください)\n");
                skill_command = _getch();
                if ( skill_command == '0' ){
                  if ( (**setting_skill3) -> set_skill[0] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[0];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '1' ){
                  if ( (**setting_skill3) -> set_skill[1] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[1];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '2' ){
                  if ( (**setting_skill3) -> set_skill[2] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[2];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '3' ){
                  if ( (**setting_skill3) -> set_skill[3] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[3];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '4' ){
                  if ( (**setting_skill3) -> set_skill[4] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[4];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '5' ){
                  if ( (**setting_skill3) -> set_skill[5] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[5];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '6' ){
                  if ( (**setting_skill3) -> set_skill[6] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[6];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '7' ){
                  if ( (**setting_skill3) -> set_skill[7] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[7];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '8' ){
                  if ( (**setting_skill3) -> set_skill[8] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[8];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == '9' ){
                  if ( (**setting_skill3) -> set_skill[9] != 0 ){
                    skill_user = PLAYER3;
                    use_skill_count = (**setting_skill3) -> set_skill[9];
                    if ( who_is_skillTarget(use_skill_count) == PARTY ){
                      skill_target = select_player_skillTarget(&st,&st2,&st3);
                      if ( skill_target != NOTARGET ){
                        turn_decrease = player_skill_forParty(&st,&st2,&st3,&player_skill3,use_skill_count,skill_target,skill_user);
                      }
                    }
                    else if ( who_is_skillTarget(use_skill_count) == PARTYALL ){

                    }
                    else if ( who_is_skillTarget(use_skill_count) == ENEMYALL ){

                    }
                    else{  //ENEMY
                      if ( encount_pattern == 1 ){
                        skill_target = ENEMY1;
                        //enemyに対してスキルの使用関数
                        if ( is_enemy_alive(&enemy) == TRUE ){
                          turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                        }
                        else{
                          skill_target = NOTARGET;
                        }
                      }
                      else if ( encount_pattern == 2 ){
                        skill_target = select_encount_pattern2_skillTarget(&enemy,&enemy_copy1);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 3 ){
                        skill_target = select_encount_pattern3_skillTarget(&enemy,&enemy_copy1,&enemy_copy2);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                      else if ( encount_pattern == 4 ){
                        skill_target = select_encount_pattern4_skillTarget(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
                        if ( skill_target == ENEMY1 ){
                          if ( is_enemy_alive(&enemy) == TRUE ){
                            turn_decrease = player_skill_forEnemy(&st3,&player_skill3,&enemy,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY2 ){
                          if ( is_enemyCopy_alive(&enemy_copy1) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy1,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY3 ){
                          if ( is_enemyCopy_alive(&enemy_copy2) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy2,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                        else if ( skill_target == ENEMY4 ){
                          if ( is_enemyCopy_alive(&enemy_copy3) == TRUE ){
                            turn_decrease = player_skill_forEnemyCopy(&st3,&player_skill3,&enemy_copy3,use_skill_count);
                          }
                          else{
                            skill_target = NOTARGET;
                          }
                        }
                      }
                    }

                    if ( skill_target != NOTARGET ){
                      move_finish++;
                      player_turn = calculate_player_turn(player_turn, turn_decrease);
                    }
                    else{
                      //turn消費無し
                    }
                  }
                  printf("\n");
                }
                else if ( skill_command == 'c' ){
                  printf("\n");
                  break;
                }
              }while ( skill_user == NOTARGET );    //skillを使うと数値は0ではない
            }
          }
          else if ( command == '3' ){  //防御コマンド

            //enemy_attackのテンプレート
            player_guard3++;
            player_turn--;
            move_finish++;
          }
          else if ( command == '4' ){  //item使用
            turn_decrease = battle_item_use(&items,&st,&st2,&st3);
            if ( turn_decrease == 0 ){
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 0;
            }
            else{
              player_turn = calculate_player_turn(player_turn, turn_decrease);
              move_finish = 1;
            }

          }
          else if ( command == '5' ){  //逃走する
            if ( enemy -> boss_count == 0 ){
              printf("逃走中・・・\n");
              sleep(2);
              if ( battle_escape(&st3) == 1 ){
                return;
              }
              else{
                player_turn = 0;
                move_finish = 1;
              }
            }
            else{
              printf("逃走失敗!\n");
              sleep(1);
              move_finish = 1;
              player_turn = 0;
            }
          }
          else if ( command == '6' ){
            turn_decrease = 0.1;
            player_turn = calculate_player_turn(player_turn, turn_decrease);
            move_finish = 1;
            player_guard3 = 0;
          }
          //イレギュラーな入力が行われるとenemy_deadcountの値が最大までインクリメントされてしまうのでこの処理を追加
          else{
            if ( encount_pattern == 1 ){
              enemy_deadcount = check_enemyDeadCount1(&enemy);
            }
            else if ( encount_pattern == 2 ){
              enemy_deadcount = check_enemyDeadCount2(&enemy,&enemy_copy1);
            }
            else if ( encount_pattern == 3 ){
              enemy_deadcount = check_enemyDeadCount3(&enemy,&enemy_copy1,&enemy_copy2);
            }
            else if ( encount_pattern == 4 ){
              enemy_deadcount = check_enemyDeadCount4(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3);
            }

            printf("コマンドを正しく入力してください\n");
            system("pause");
            printf("\n");
          }

          if ( (**st3) -> badstatus == POISON ){ //毒状態時
            poison_effect(&st3);
          }
        }

      }while ( move_finish != 1 );

      if ( enemy_deadcount == enemy_temp ){
        break;
      }

    }while ( player_turn != 0 );

    //enemy_turn;
    if ( enemy_deadcount == enemy_temp ){
      break;
    }

    //関係のない値の代入
    enemy_turn_temp = -2;

    //敵の攻撃
    do {
      if ( encount_pattern == 1 ){
        enemy_turn = 1;
        if ( enemy_turn != enemy_turn_temp && enemy_turn_temp != -2 ){
          enemy_turn = enemy_turn_temp;
        }

        printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
        printf("\n");
        encount_pattern1_layout(&enemy,encount_pattern);
        printf("\n");
        sleep(1);

        printf("       %3s                   %3s                    %3s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);
        printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d          HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);
        battle_display_condition_count = 0;
        hp_graphycal_display(&st,&st2,&st3);
        mp_graphycal_display(&st,&st2,&st3);
        battle_display_condition(&st, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st2, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st3, battle_display_condition_count);
        printf("\n");

        display_enemy_turn(&enemy, enemy_turn);
        //enemyの攻撃
        //printf("%f\n", enemy_turn);
        sleep(1);
        enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy, player_guard, player_guard2, player_guard3, enemy_turn);
        sleep(1);
        //printf("%f\n", enemy_turn);

        if ( enemy_turn <= 0 ){
          break;
        }
      }
      else if ( encount_pattern == 2 ){
        enemy_turn = 2;
        if ( enemy -> badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy1.badstatus == DEAD ){
          enemy_turn--;
        }
        //printf("enemy_turn:%f\n", enemy_turn);
        //printf("enemy_turn_temp:%f\n", enemy_turn_temp);

        if ( enemy_turn != enemy_turn_temp && enemy_turn_temp != -2 ){
          enemy_turn = enemy_turn_temp;
        }
        //printf("enemy_turn:%f\n", enemy_turn);
        //printf("enemy_turn_temp:%f\n", enemy_turn_temp);

        printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
        printf("\n");
        encount_pattern2_layout(&enemy,&enemy_copy1,encount_pattern);
        printf("\n");
        sleep(1);

        printf("       %3s                   %3s                    %3s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);
        printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d          HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);
        battle_display_condition_count = 0;
        hp_graphycal_display(&st,&st2,&st3);
        mp_graphycal_display(&st,&st2,&st3);
        battle_display_condition(&st, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st2, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st3, battle_display_condition_count);
        printf("\n");
        //printf("enemy's badstatus:%d\n", enemy -> badstatus);
        //printf("enemy_copy1's badstatus:%d\n", enemy_copy1.badstatus);
        if ( enemy -> badstatus != DEAD ){
          display_enemy_turn(&enemy, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
          printf("\n");
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy1.badstatus != DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy1, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy1, player_guard, player_guard2, player_guard3, enemy_turn);
          //printf("OK!\n");
          sleep(1);
          //printf("%f\n", enemy_turn);
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

      }
      else if ( encount_pattern == 3 ){
        enemy_turn = 3;
        if ( enemy -> badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy1.badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy2.badstatus == DEAD ){
          enemy_turn--;
        }

        if ( enemy_turn != enemy_turn_temp && enemy_turn_temp != -2 ){
          enemy_turn = enemy_turn_temp;
        }
        //printf("enemy_turn:%f\n", enemy_turn);
        printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
        printf("\n");
        encount_pattern3_layout(&enemy,&enemy_copy1,&enemy_copy2,encount_pattern);
        printf("\n");
        sleep(1);

        printf("       %3s                   %3s                    %3s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);
        printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d          HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);
        battle_display_condition_count = 0;
        hp_graphycal_display(&st,&st2,&st3);
        mp_graphycal_display(&st,&st2,&st3);
        battle_display_condition(&st, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st2, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st3, battle_display_condition_count);
        printf("\n");
        //printf("enemy's badstatus:%d\n", enemy -> badstatus);
        //printf("enemy_copy1's badstatus:%d\n", enemy_copy1.badstatus);
        if ( enemy -> badstatus != DEAD ){
          display_enemy_turn(&enemy, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
          printf("\n");
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy1.badstatus != DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy1, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy1, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //rintf("%f\n", enemy_turn);
        }
        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy2.badstatus != DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy2, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy2, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
        }

      }
      else if ( encount_pattern == 4 ){
        enemy_turn = 4;
        if ( enemy -> badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy1.badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy2.badstatus == DEAD ){
          enemy_turn--;
        }
        if ( enemy_copy3.badstatus == DEAD ){
          enemy_turn--;
        }

        if ( enemy_turn != enemy_turn_temp && enemy_turn_temp != -2 ){
          enemy_turn = enemy_turn_temp;
        }
        //printf("enemy_turn:%f\n", enemy_turn);
        printf("                 <<<<<<<ENEMY TURN>>>>>>>\n");
        printf("\n");
        encount_pattern4_layout(&enemy,&enemy_copy1,&enemy_copy2,&enemy_copy3,encount_pattern);
        printf("\n");
        sleep(1);

        printf("       %3s                   %3s                    %3s\n", (**st) -> name, (**st2) -> name, (**st3) -> name);
        printf(" HP:%d/%d MP:%d/%d       HP:%d/%d MP:%d/%d          HP:%d/%d MP:%d/%d\n", (**st) -> hp, (**st) -> maxhp, (**st) -> mp, (**st) -> maxmp, (**st2) -> hp, (**st2) -> maxhp, (**st2) -> mp, (**st2) -> maxmp, (**st3) -> hp, (**st3) -> maxhp, (**st3) -> mp, (**st3) -> maxmp);
        battle_display_condition_count = 0;
        hp_graphycal_display(&st,&st2,&st3);
        mp_graphycal_display(&st,&st2,&st3);
        battle_display_condition(&st, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st2, battle_display_condition_count);
        battle_display_condition_count++;
        battle_display_condition(&st3, battle_display_condition_count);
        printf("\n");
        //printf("enemy's badstatus:%d\n", enemy -> badstatus);
        //printf("enemy_copy1's badstatus:%d\n", enemy_copy1.badstatus);
        if ( enemy -> badstatus != DEAD ){
          display_enemy_turn(&enemy, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
          printf("\n");
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy1.badstatus !=DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy1, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy1, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
        }
        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy2.badstatus != DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy2, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy2, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

        if ( enemy_copy3.badstatus != DEAD ){
          sleep(1);
          display_enemy_copy_turn(&enemy_copy3, enemy_turn);
          //enemyの攻撃
          //printf("%f\n", enemy_turn);
          sleep(1);
          enemy_turn = enemy_copy_attack_pattern(&st, &st2, &st3, &pEquip, &p2Equip, &p3Equip, &enemy_copy3, player_guard, player_guard2, player_guard3, enemy_turn);
          sleep(1);
          //printf("%f\n", enemy_turn);
        }

        if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
          display_gameover();
        }
        if ( enemy_turn <= 0 ){
          break;
        }

      }
      if ( (**st) -> badstatus == DEAD && (**st2) -> badstatus == DEAD && (**st3) -> badstatus == DEAD ){
        display_gameover();
      }

      enemy_turn_temp = enemy_turn;

    } while ( enemy_turn > 0 );

  }while( enemy_deadcount != enemy_temp || ( (**st) -> badstatus != DEAD && (**st2) -> badstatus != DEAD && (**st3) -> badstatus != DEAD ) );

  enemy -> badstatus = GOOD;  //敵の状態をGOODに戻す
  enemy_copy1.badstatus = GOOD;
  enemy -> hp = enemy -> maxhp;
  enemy -> mp = enemy -> maxmp;

  result_exp = 0;
  result_gold = 0;
  int battle_experience;

  if ( encount_pattern == 1 ){
    result_exp = enemy -> exp;
    result_gold = enemy -> gold;
    battle_experience = enemy -> lv;
  }
  else if ( encount_pattern == 2 ){
    result_exp = enemy -> exp + enemy_copy1.exp;
    result_gold = enemy -> gold + enemy_copy1.gold;
    battle_experience = enemy -> lv + enemy_copy1.lv;
  }
  else if ( encount_pattern == 3 ){
    result_exp = enemy -> exp + enemy_copy1.exp + enemy_copy2.exp;
    result_gold = enemy -> gold + enemy_copy1.gold + enemy_copy2.gold;
    battle_experience = enemy -> lv + enemy_copy1.lv + enemy_copy2.lv;
  }
  else if ( encount_pattern == 4 ){
    result_exp = enemy -> exp + enemy_copy1.exp + enemy_copy2.exp + enemy_copy3.exp;
    result_gold = enemy -> gold + enemy_copy1.gold + enemy_copy2.gold + enemy_copy3.gold;
    battle_experience = enemy -> lv + enemy_copy1.lv + enemy_copy2.lv + enemy_copy3.lv;
  }

  //スキルの熟練度チェック
  if ( is_skill_learning(&player_skill) == TRUE ){
    add_battleExperience(&st,&player_skill,battle_experience);
  }
  if ( is_skill_learning(&player_skill2) == TRUE ){
    add_battleExperience(&st2,&player_skill2,battle_experience);
  }
  if ( is_skill_learning(&player_skill3) == TRUE ){
    add_battleExperience(&st3,&player_skill3,battle_experience);
  }

  printf("\a");
  sleep(1);
  printf("%s達は戦闘に勝利した!\n", (**st) -> name);
  printf("------RESULT------\n");
  printf("  EXP:%d GOLD:%d\n", result_exp, result_gold);
  printf("  EP:%d\n", battle_experience);
  if ( is_skill_learning(&player_skill) == TRUE ){
    add_battleExperience(&st,&player_skill,battle_experience);
  }
  if ( is_skill_learning(&player_skill2) == TRUE ){
    add_battleExperience(&st2,&player_skill2,battle_experience);
  }
  if ( is_skill_learning(&player_skill3) == TRUE ){
    add_battleExperience(&st3,&player_skill3,battle_experience);
  }
  printf("\n");

  //アイテムドロップ
  if ( encount_pattern == 1 || encount_pattern == 2 || encount_pattern == 3 || encount_pattern == 4 ){
    item_drop(&st,&st2,&st3,&enemy,&items,encount_pattern);
  }

  if ( (**st) -> badstatus == DEAD ){
    //経験値獲得無し
  }
  else{
    (**st) -> exp += result_exp;
    (**st) -> sumexp += result_exp;
    level_up(&st, &player_skill,&setting_skill);
  }
  if ( (**st2) -> badstatus == DEAD ){
    //獲得経験値なし
  }
  else{
    (**st2) -> exp += result_exp;
    (**st2) -> sumexp += result_exp;
    level_up(&st2, &player_skill2,&setting_skill2);
  }
  if ( (**st3) -> badstatus == DEAD ){
    //獲得経験値なし
  }
  else{
    (**st3) -> exp += result_exp;
    (**st3) -> sumexp += result_exp;
    level_up(&st3, &player_skill3,&setting_skill3);
  }

  (**st) -> gold += result_gold;

  player_badstatus_recover(&st);
  player_badstatus_recover(&st2);
  player_badstatus_recover(&st3);
}
