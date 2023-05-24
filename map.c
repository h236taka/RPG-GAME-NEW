#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include "rpg.h"

//マップに関するファイル

//battleからmap画面に戻る判定(1なら該当)
static int battle_to_map;

//eventからmap画面に戻る判定(1なら該当)
static int event_to_map;

int battle_mode;

extern int saveFile;

void display_3dmap(int area_data_number, int direction, Map ***map){

  if ( area_data_number == 100 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |＼                     ／ | \n");
      printf(" |  ＼                 ／   | \n");
      printf(" |    ＼_____________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |＼                     ／ | \n");
      printf(" |  ＼                 ／   | \n");
      printf(" |    ＼_____________／     | \n");
      printf(" |   　|  _________  |      | \n");
      printf(" |     | |         | |      | \n");
      printf(" |     | |  EXIT   | |      | \n");
      printf(" |     |_|_________|_|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 0 ){
    printf(" ---------------------------- \n");
    printf(" |＼                     ／ | \n");
    printf(" |  ＼                 ／   | \n");
    printf(" |    ＼_____________／     | \n");
    printf(" |   　|             |      | \n");
    printf(" |     |             |      | \n");
    printf(" |     |             |      | \n");
    printf(" |     |_____________|      | \n");
    printf(" |    ／              ＼    | \n");
    printf(" |  ／                  ＼  | \n");
    printf(" |／______________________＼| \n");
    printf("\n");
  }
  else if ( area_data_number == 1 ){
    printf(" ------------------------------ \n");
    printf(" |        ／|      |＼        | \n");
    printf(" |_____ ／  |      |  ＼ _____| \n");
    printf(" |     |    |      |    |     | \n");
    printf(" |   　|    |      |    |     | \n");
    printf(" |     |    |      |    |     | \n");
    printf(" |     |  ／        ＼  |     | \n");
    printf(" |_____|／            ＼|_____| \n");
    printf(" |                            | \n");
    printf(" |                            | \n");
    printf(" |____________________________| \n");
    printf("\n");
  }
  else if ( area_data_number == 2 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼ _____________________| \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |_____________|_______| \n");
      printf(" |   ／              ＼     | \n");
      printf(" | ／                  ＼   | \n");
      printf(" ／______________________＼_| \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |                       ／ | \n");
      printf(" |                     ／   | \n");
      printf(" |___________________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 3 || direction == 4 ){
      printf(" ---------------------------- \n");
      printf(" |＼                     ／ | \n");
      printf(" |  ＼                 ／   | \n");
      printf(" |    ＼_____________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 3 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |                       ／ | \n");
      printf(" |                     ／   | \n");
      printf(" |___________________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 2 || direction == 3 ){
      printf(" ---------------------------- \n");
      printf(" |＼                     ／ | \n");
      printf(" |  ＼                 ／   | \n");
      printf(" |    ＼_____________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼ _____________________| \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |_____________|_______| \n");
      printf(" |   ／              ＼     | \n");
      printf(" | ／                  ＼   | \n");
      printf(" ／______________________＼_| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 4 ){
    printf(" ---------------------------- \n");
    printf(" |＼                     ／ | \n");
    printf(" |  ＼                 ／   | \n");
    printf(" |    ＼_____________／     | \n");
    printf(" |   　|             |      | \n");
    printf(" |     |    STOP     |      | \n");
    printf(" |     |             |      | \n");
    printf(" |     |_____________|      | \n");
    printf(" |    ／              ＼    | \n");
    printf(" |  ／                  ＼  | \n");
    printf(" |／______________________＼| \n");
    printf("\n");
  }
  else if ( area_data_number == 5 ){
    printf(" ---------------------------- \n");
    printf(" |＼                     ／ | \n");
    printf(" |  ＼                 ／   | \n");
    printf(" |    ＼_____________／     | \n");
    printf(" |   　|             |      | \n");
    printf(" |     |    STOP     |      | \n");
    printf(" |     |             |      | \n");
    printf(" |     |_____________|      | \n");
    printf(" |    ／              ＼    | \n");
    printf(" |  ／                  ＼  | \n");
    printf(" |／______________________＼| \n");
    printf("\n");
  }
  else if ( area_data_number == 6 ){
    if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |                       ／ | \n");
      printf(" |                     ／   | \n");
      printf(" |___________________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 3 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼ _____________________| \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |_____________|_______| \n");
      printf(" |   ／              ＼     | \n");
      printf(" | ／                  ＼   | \n");
      printf(" ／______________________＼_| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 7 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |                          | \n");
      printf(" |                          | \n");
      printf(" |__________________________| \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|______| \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |＼                     ／ | \n");
      printf(" |  ＼                 ／   | \n");
      printf(" |    ＼_____________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 3 ){
      printf(" ---------------------------- \n");
      printf(" |                       ／ | \n");
      printf(" |                     ／   | \n");
      printf(" |___________________／     | \n");
      printf(" |   　|＼_________／|      | \n");
      printf(" |     | |        |  |      | \n");
      printf(" |     | |________|  |      | \n");
      printf(" |_____|／_________＼|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼ _____________________| \n");
      printf(" |    |＼_________／|       | \n");
      printf(" |    | |         | |       | \n");
      printf(" |    | |         | |       | \n");
      printf(" |    | |_________| |       | \n");
      printf(" |    |／_________＼|_______| \n");
      printf(" |   ／              ＼     | \n");
      printf(" | ／                  ＼   | \n");
      printf(" ／______________________＼_| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 8 ){
    if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼ _____________________| \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |             |       | \n");
      printf(" |    |_____________|_______| \n");
      printf(" |   ／              ＼     | \n");
      printf(" | ／                  ＼   | \n");
      printf(" ／______________________＼_| \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      printf(" ---------------------------- \n");
      printf(" |                       ／ | \n");
      printf(" |                     ／   | \n");
      printf(" |___________________／     | \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|      | \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 9 ){
    printf(" ---------------------------- \n");
    printf(" |＼                     ／ | \n");
    printf(" |  ＼                 ／   | \n");
    printf(" |    ＼_____________／     | \n");
    printf(" |   　|  _________  |      | \n");
    printf(" |     | |         | |      | \n");
    printf(" |     | |         | |      | \n");
    printf(" |     |_|_________|_|      | \n");
    printf(" |    ／              ＼    | \n");
    printf(" |  ／                  ＼  | \n");
    printf(" |／______________________＼| \n");
    printf("\n");
  }
  else if ( area_data_number == 10 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼                      | \n");
      printf(" |    |＼                   | \n");
      printf(" |    |  ＼                 | \n");
      printf(" |    |   |                 | \n");
      printf(" |    |  ／                 | \n");
      printf(" |    |／                   | \n");
      printf(" |   ／                     | \n");
      printf(" | ／                       | \n");
      printf(" ／_________________________| \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |                        ／| \n");
      printf(" |                      ／  | \n");
      printf(" |                   ／|    | \n");
      printf(" |   　            ／  |    | \n");
      printf(" |                |    |    | \n");
      printf(" |                |    |    | \n");
      printf(" |                 ＼  |    | \n");
      printf(" |                   ＼|    | \n");
      printf(" |                      ＼  | \n");
      printf(" |________________________＼| \n");
      printf("\n");
    }
    else if ( direction == 3 ){
      printf(" ---------------------------- \n");
      printf(" |                          | \n");
      printf(" |                          | \n");
      printf(" |__________________________| \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|______| \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 11 ){
    if ( direction == 1 ){
      printf(" ---------------------------- \n");
      printf(" |                        ／| \n");
      printf(" |                      ／  | \n");
      printf(" |                   ／|    | \n");
      printf(" |   　            ／  |    | \n");
      printf(" |                |    |    | \n");
      printf(" |                |    |    | \n");
      printf(" |                 ＼  |    | \n");
      printf(" |                   ＼|    | \n");
      printf(" |                      ＼  | \n");
      printf(" |________________________＼| \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf(" ---------------------------- \n");
      printf(" |＼                        | \n");
      printf(" |  ＼                      | \n");
      printf(" |    |＼                   | \n");
      printf(" |    |  ＼                 | \n");
      printf(" |    |   |                 | \n");
      printf(" |    |  ／                 | \n");
      printf(" |    |／                   | \n");
      printf(" |   ／                     | \n");
      printf(" | ／                       | \n");
      printf(" ／_________________________| \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      printf(" ---------------------------- \n");
      printf(" |                          | \n");
      printf(" |                          | \n");
      printf(" |__________________________| \n");
      printf(" |   　|             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |     |             |      | \n");
      printf(" |_____|_____________|______| \n");
      printf(" |    ／              ＼    | \n");
      printf(" |  ／                  ＼  | \n");
      printf(" |／______________________＼| \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 99 ){
    printf(" ____________________________ \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |--------------------------| \n");
    printf(" |__________________________| \n");
    printf("\n");
  }
}

void display_2dmap(int area_data_number, int direction, Map **map){

  if ( area_data_number == 100 ){  //EXIT手前
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↑  |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↓  |\n");
      printf("|  E  |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 0 ){  //直線
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↑  |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↓  |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_____\n");
      printf(" ←   \n");
      printf("_____ \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("____\n");
      printf(" →  \n");
      printf("____\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 1 ){    //十字路
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf(" |    |\n");
      printf("-      -\n");
      printf("   ↑  \n");
      printf("_      _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf(" |    |\n");
      printf("-      -\n");
      printf("   ↓  \n");
      printf("_      _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf(" |    |\n");
      printf("-      -\n");
      printf("    ←    \n");
      printf("_      _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf(" |    |\n");
      printf("-      -\n");
      printf("   →      \n");
      printf("_      _\n");
      printf(" |    |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 2 ){ //右折
    if ( direction == 1 ){ //north
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("|     \n");
      printf("| ↑  _\n");
      printf("|    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("|     \n");
      printf("| ↓  _\n");
      printf("|    |\n");
      printf("\n");
    }
    else if ( direction == 3 ){  //west
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("|     \n");
      printf("|  ← _\n");
      printf("|    |\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("|     \n");
      printf("|  → _\n");
      printf("|    |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 3 ){ //左折
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("      | \n");
      printf("_  ↑ |\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("      | \n");
      printf("_  ↓ |\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("      | \n");
      printf("_  ← |\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("______\n");
      printf("      | \n");
      printf("_  → |\n");
      printf(" |    |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 4 ){   //行き止まり
    display_3dmap(area_data_number, direction, &map);
    if ( direction == 1 ){
      printf("---MAP---\n");
      printf("______\n");
      printf("| ↑ |\n");
      printf("|    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↓  |\n");
      printf("|____ |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_____\n");
      printf("| ←\n");
      printf("|____\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("____\n");
      printf(" → |\n");
      printf("____|\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 5 ){
    display_3dmap(area_data_number, direction, &map);
    if ( direction == 1 ){
      printf("---MAP---\n");
      printf("_______\n");
      printf("|     |\n");
      printf("|_ ↑_|\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("__   __\n");
      printf("|  ↓  |\n");
      printf("|______|\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_______\n");
      printf("|     |\n");
      printf("|   ← \n");
      printf("|_____|\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_______\n");
      printf("|     |\n");
      printf(" →   |\n");
      printf("|_____|\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 6 ){
    display_3dmap(area_data_number, direction, &map);
    if ( direction == 1 ){
      printf("---MAP---\n");
      printf("|    |_\n");
      printf("|  ↑  \n");
      printf("|_______\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      printf("---MAP---\n");
      printf("|    |_\n");
      printf("|  ↓  \n");
      printf("|_______\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      printf("---MAP---\n");
      printf("|    |_\n");
      printf("|   ← \n");
      printf("|_______\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 7 ){
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("________\n");
      printf("       \n");
      printf("_  ↑  _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("________\n");
      printf("       \n");
      printf("_  ↓  _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("________\n");
      printf("       \n");
      printf("_  ←  _\n");
      printf(" |    |\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("________\n");
      printf("       \n");
      printf("_  →  _\n");
      printf(" |    |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 8 ){
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↑  |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_|    |\n");
      printf("   ↓ | \n");
      printf("______|\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_____\n");
      printf(" ←   \n");
      printf("_____ \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_|    |\n");
      printf("   → | \n");
      printf("______|\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 9 ){
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↑ |\n");
      printf("|    |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("|    |\n");
      printf("| ↓ |\n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("_____\n");
      printf(" ←   \n");
      printf("_____ \n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("____\n");
      printf(" →  \n");
      printf("____\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 10 ){
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ↑ \n");
      printf("|   \n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("|    \n");
      printf("| ↓  \n");
      printf("\n");
    }
    else if ( direction == 3 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("| ← \n");
      printf("|   \n");
      printf("\n");
    }
  }
  else if ( area_data_number == 11 ){
    if ( direction == 1 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("   ↑ |\n");
      printf("\n");
    }
    else if ( direction == 2 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("   ↓ |\n");
      printf("\n");
    }
    else if ( direction == 4 ){
      display_3dmap(area_data_number, direction, &map);
      printf("---MAP---\n");
      printf("   → |\n");
      printf("\n");
    }
  }
  else if ( area_data_number == 99 ){
    display_3dmap(area_data_number, direction, &map);
    printf("---MAP---\n");
    printf("ダークゾーン\n");
    printf("\n");
  }
}

int enemy_encount(Map **map){
  int encounter;

  encounter = (rand() % ( 10 - 1 + 1)) + 1;  //1~10の乱数
  if ( (*map) -> walk_step <= 4 ){
    if ( encounter == 1 ){
      printf("エンカウント！\n");
      (*map) -> walk_step = 0;
      return 1;
    }
  }
  else if ( (*map) -> walk_step < 9 ){
    if ( encounter >= 1 && encounter <= 3 ){
      printf("エンカウント！\n");
      (*map) -> walk_step = 0;
      return 1;
    }
  }
  else{
    if ( encounter >= 1 && encounter <= 6 ){
      printf("エンカウント!\n");
      (*map) -> walk_step = 0;
      return 1;

    }
  }

  return 0;
}

void check_dangeonId(Area ****area){

  if ( (***area) -> dangeonId == 1 ){
    printf("---1F廊下---\n");
  }
  else if ( (***area) -> dangeonId == 2 ){
    printf("---1F図書館---\n");
  }


}

int search_dangeon(Area ****area, Map **map, SearchDangeon ****search, int area_data_line, int area_data_len, int area_data[area_data_line][area_data_len]){
  int search_id;

  search_id = 0;

  if ( (***area) -> dangeonId == 2 ){
    //(***search) -> search_item2 = 0;
    if ( (*map) -> y == 25 && (*map) -> x == 4 && (***search) -> search_item1 == 0 ){
      printf("足元に何か落ちている...\n");
      sleep(1);
      search_id = 1;
      (***search) -> search_item1 = 1;
    }
    if ( (*map) -> y == 16 && (*map) -> x == 0 && (***search) -> search_item2 == 0 ){
      printf("足元に何か落ちている...\n");
      sleep(1);
      search_id = 2;
      (***search) -> search_item2 = 1;
    }
  }

  return search_id;
}

void get_search_event(int search_id, Player ****st, Items ****items, Equip ****pEquip, Equip ****p2Equip, Equip ****p3Equip){

  if ( search_id == 0 ){
    printf("何も見つからなかった...\n");
    sleep(1);
  }
  else if ( search_id == 1 ){
    printf("%sは傷薬を見つけた!\n", (***st) -> name);
    (***items) -> medicine++;
    sleep(1);
  }
  else if ( search_id == 2 ){
    printf("%sはMPリングを見つけた!\n", (***st) -> name);
    (***pEquip) -> MpRing1++;
    (***p2Equip) -> MpRing1++;
    (***p3Equip) -> MpRing1++;
  }
}

void player_move(Player ***st, Player ***st2, Player ***st3, P_skill ***player_skill, P_skill ***player_skill2, P_skill ***player_skill3, Setting_skill ***setting_skill, Setting_skill ***setting_skill2, Setting_skill ***setting_skill3, Items ***items, Equip ***pEquip, Equip ***p2Equip, Equip ***p3Equip, SearchDangeon ***search, Map *map, Area ***area, int area_data_line, int area_data_len, int area_data[area_data_line][area_data_len], int automap_area[area_data_line][area_data_len]){
  int input, dummy, area_data_number;   //direction = 1; ↑ direction = 2; ↓ direction = 3; ← direction = 4; →
  int is_move;
  int search_id;
  int encount_enemy_pattern;
  static int direction;
  static int first_move_count;  //初期値0  スタート時点でメニュー画面を開いた時の処理のためのstatic変数

  //area_data = -1; -> 壁
  //area_data = 0; -> 直線
  //area_data = 1; -> 十字路
  //area_data = 2; -> 北方向の右折路
  //area_data = 3; ->　北方向の左折路
  //area_data = 4; -> 行き止まり
  //area_data = 5; -> 小部屋
  //area_data = 6; -> 南方向の右折路
  //area_data = 7; -> T字路
  //area_data = 8; -> 南方向の左折路
  //area_data = 9; -> 小部屋行き止まり手前
  //area_data = 10; -> 2列通路左側
  //area_data = 11; -> 2列通路右側
  //area_data_number = 99; -> ダークゾーン
  //area_data = 100; ->ダンジョンの初期位置
  //area_data = 101; EXIT

  battle_mode = 0;

  //battleからmap画面に戻ったとき
  if ( battle_to_map == 1 ){
    printf("battle_to_map:%d\n", battle_to_map);
    battle_to_map = 0;
    area_data_number = area_data[map -> y][map -> x];
    display_2dmap(area_data_number, direction, &map);
  }

  //eventからmap画面に戻ったとき
  if ( event_to_map == 1 ){
    event_to_map = 0;
    area_data_number = area_data[map -> y][map -> x];
    display_2dmap(area_data_number, direction, &map);
  }

  if( _kbhit() ){
    dummy = _getch();

    check_dangeonId(&area);

    if ( (**area) -> encount == 1 ){
      printf("ENEMY ENCOUNT --YES--\n");
    }
    else{
      printf("ENEMY ENCOUNT --NO--\n");
    }

    if ( dummy == 's' ){  //search
      printf("%sは足元を調べた...\n", (**st) -> name);
      search_id = search_dangeon(&area, &map, &search, area_data_line, area_data_len, area_data);
      sleep(2);

      get_search_event(search_id,&st,&items,&pEquip,&p2Equip,&p3Equip);

      if ( first_move_count == 0 ){
        direction = 1;
      }
      area_data_number = area_data[map -> y][map -> x];
      display_2dmap(area_data_number, direction, &map);
    }

    if ( dummy == 'm' ){  //menu
      display_menu(&st,&st2,&st3,&player_skill,&player_skill2,&player_skill3,&setting_skill,&setting_skill2,&setting_skill3,&items,&pEquip,&p2Equip,&p3Equip,&map,&area,area_data_line,area_data_len,automap_area);
      if ( first_move_count == 0 ){
        direction = 1;
      }
      area_data_number = area_data[map -> y][map -> x];
      display_2dmap(area_data_number, direction, &map);
    }

    if( dummy == 0 || dummy == 224 ){
      is_move = 1;
      input = _getch();

      if ( input == 0x48 ){   //上キー入力
        first_move_count++;
        map -> y--;

        area_data_number = area_data[map -> y][map -> x];
        if ( area_data_number == 0 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 1 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 100 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          //automap_area1[map -> y][map -> x] = 10000;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 2 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 3 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 4 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 5 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 6 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 7 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 8 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 9 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 10 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 11 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 99 ){
          printf("Move:North\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 1;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else{
          printf("壁にぶつかった!\n");
          is_move = 0;
          map -> y++;    //移動出来ないのでyの値を元に戻す
          //direction = 1;
          area_data_number = area_data[map -> y][map -> x];
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number,direction,&map);
        }
      }
      else if ( input == 0x50 ){  //下キー
        first_move_count++;
        map -> y++;
        area_data_number = area_data[map -> y][map -> x];
        //printf("area_data_number:%d\n", area_data_number);
        if ( area_data_number == 0 || area_data_number == 1 || area_data_number == 100 || area_data_number == 101 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 4 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 5 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 6 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 7 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 8 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 9 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 10 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 11 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 99 ){
          printf("Move:South\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 2;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else{
          printf("壁にぶつかった!\n");
          is_move = 0;
          map -> y--;   //移動出来ないのでyの値を元に戻す
          //direction = 2;
          area_data_number = area_data[map -> y][map -> x];
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number,direction,&map);
        }
      }
      else if ( input == 0x4b ){  //左キー
        first_move_count++;
        map -> x--;
        area_data_number = area_data[map -> y][map -> x];
        if ( area_data_number == 0 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 1 ){
          printf("Move:West\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 2 ){
          printf("Move:West\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 3 ){
          printf("Move:West\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 4 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 5 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 6 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 7 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 8 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 9 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 10 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 99 ){
          printf("Move:West\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 3;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else{
          printf("壁にぶつかった!\n");
          map -> x++;
          //direction = 3;
          area_data_number = area_data[map -> y][map -> x];
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
      }
      else if ( input == 0x4d ){   //右キー
        first_move_count++;
        map -> x++;
        area_data_number = area_data[map -> y][map -> x];
        if ( area_data_number == 0 ){
          printf("Move:East\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 1 ){
          printf("Move:East\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 2 ){
          printf("Move:East\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 3 ){
          printf("Move:East\n");
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 4 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 5 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 6 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 7 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 8 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 9 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 11 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else if ( area_data_number == 99 ){
          printf("Move:East\n");
          //printf("area_data_number:%d\n", area_data_number);
          automap_area[map -> y][map -> x] = 1;
          direction = 4;
          map -> walk_step++;
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
        else{
          printf("壁にぶつかった!\n");
          map -> x--;
          is_move = 0;
          //direction = 4;
          area_data_number = area_data[map -> y][map -> x];
          //printf("area_data_number:%d\n", area_data_number);
          printf("x座標:%d y座標:%d\n", map -> x, map -> y);
          display_2dmap(area_data_number, direction, &map);
        }
      }
      else{
        printf("マップ画面に関係のないコマンドが入力されました\n");
        system("pause");
      }
    }

    if ( is_move = 1 ){
      if ( map -> walk_step >= 1 && (**area) -> encount == 1 ){
        battle_mode = enemy_encount(&map);
      }
    }

  }
}


void area1_map(Area **area, Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search){
  int area_data_len, area_data_line, enemy_count, encount_pattern, clear_count;

  Map map;
  //name hp, maxhp, mp, maxmp, atk, magic, str, agi, luk, lv, exp, gold, badstatus, physical_attack, gun_attack, fire, ice, elec, wave, almighty, death, expel, poison, palyze, charm, close, stone, panic, sleep, curse, boss_count, enemy_id
  Enemy slime = {"スライム", 10, 10, 0, 0, 2, 1, 1, 1, 1, 1, 5, 30, 0, 150, 100, 200, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 0, 1};
  Enemy kobalt = {"コボルト", 20, 20, 0, 0, 2, 1, 2, 1, 1, 2, 10, 55, 0, 80, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 2};
  Enemy goblin = {"ゴブリン", 65, 65, 0, 0, 3, 1, 2, 2, 1, 3, 25, 500, 0, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 1, 3}; //boss

  int area_data[16][3] = {
    {-1, 0, -1},   //event2
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},   //event1
    {-1, 0, -1},
    {-1, 0, -1},     //start
    {-1, 4, -1} };  //15
    //   exit

  int automap_area1[16][3] = {
    {-1, 0, -1},   //event2
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},
    {-1, 0, -1},   //event1
    {-1, 0, -1},
    {-1, 0, -1},     //start
    {-1, 0, -1} };

  //start地点の設定
  map.y = 14;
  map.x = 1;
  automap_area1[map.y][map.x] = 1;
  map.walk_step = 0;

  (*area) -> encount = 0;

  /*printf("---1F廊下---\n");
  sleep(1);
  printf("%s「なんだここ？」\n", (*st2) -> name);
  sleep(2);
  printf("%s「学校だよね・・・？」\n", (*st3) -> name);
  sleep(2);
  printf("どこからか威厳のある声が響き渡る・・・\n");
  sleep(1);
  printf("？？？「お困りのようですね」\n");
  sleep(2);
  printf("%s「誰？」\n", (*st2) -> name);
  sleep(2);
  printf("？？？「私は人間を助けにきたのです」\n");
  sleep(1);
  printf("？？？「残念なことに、この学校は魔界へと堕ちてしまいました」\n");
  sleep(2);
  printf("%s「魔界？」\n", (*st3) -> name);
  sleep(2);
  printf("？？？「ええ、魔界です」\n");
  sleep(2);
  printf("？？？「魔界とは、悪魔の住処」\n");
  sleep(2);
  printf("？？？「あなた方人間がいて良い場所ではないのです」\n");
  sleep(2);
  printf("%s「じゃあ、ここから元の世界に戻してください！」\n", (*st2) -> name);
  sleep(2);
  printf("？？？「それは私にも出来ません」\n");
  sleep(2);
  printf("？？？「私に出来ることはあなた方に力を授けることくらい・・・」\n");
  sleep(2);
  printf("？？？「目を瞑りなさい」\n");
  sleep(1);
  printf("%s達は目を静かに瞑った\n", (*st) -> name);
  sleep(2);
  printf("%s達は力がみなぎるのを感じた！\n", (*st) -> name);
  sleep(1);
  printf("？？？「これであなた方３人は悪魔と戦うことが出来ます」\n");
  sleep(2);
  printf("%s「悪魔と戦う？」\n", (*st) -> name);
  sleep(2);
  printf("？？？「ええ、悪魔と戦い経験を積んで魔界から脱出するのです」\n");
  sleep(2);
  printf("？？？「あなた方の成長を楽しみにしていますよ・・・」\n");
  sleep(1);
  printf("威厳のある声は聞こえなくなった\n");
  sleep(2);
  printf("%s「なんだったんだろう」\n", (*st3) -> name);
  sleep(2);
  printf("%s「悪魔と戦うしか魔界から出る方法はないみたいだね」\n", (*st2) -> name);
  sleep(2);*/
  (*area) -> dangeonId = 1; //1F廊下

  printf("---1F廊下---\n");

  if ( (*area) -> encount == 1 ){
    printf("ENEMY ENCOUNT --YES--\n");
  }
  else{
    printf("ENEMY ENCOUNT --NO--\n");
  }

  printf(" ---------------------------- \n");
  printf(" |＼                     ／ | \n");
  printf(" |  ＼                 ／   | \n");
  printf(" |    ＼_____________／     | \n");
  printf(" |   　|             |      | \n");
  printf(" |     |             |      | \n");
  printf(" |     |             |      | \n");
  printf(" |     |_____________|      | \n");
  printf(" |    ／              ＼    | \n");
  printf(" |  ／                  ＼  | \n");
  printf(" |／______________________＼| \n");
  printf("\n");

  printf("---MAP---\n");
  printf("| ↑  |\n");
  printf("|____ |\n");

  area_data_len = 3;
  area_data_line = sizeof(area_data) / sizeof(int) / area_data_len;

  //encount_pattern = 1; 敵１体
  //encount_pattern = 2; 同じ敵2体
  //encount_pattern = 3; 同じ敵３体
  //encount_pattern = 4; 同じ敵４体
  //encount_pattern = 5; 違う敵２体
  //encount_pattern = 6; 違う敵３体
  //encount_pattern = 7; 違う敵４体
  //encount_pattern = 8; 敵４体(敵２体を１グループとして２グループ)
  //encount_pattern = 9; 敵４体(同じ敵３体と違う敵１体)
  //encount_pattern = 10; 敵３体(同じ敵２体と違う敵１体)
  clear_count = 0;
  do{
    player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area1);  //playerの移動に関する関数
    //event処理
    if ( map.x == 1 && map.y == 12 && (*area) -> event1a == 0 ){
      printf("突然目の前に敵が現れた!\n");
      encount_pattern = 2;
      slime.boss_count = 2;  //通常の敵を強制戦闘用に変更
      game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &slime, encount_pattern);

      slime.boss_count = 0;  //元に戻す
      (*area) -> event1a = 1;

      sleep(1);
      printf("足元に何か落ちている・・・\n");
      sleep(1);
      printf("%sは傷薬を5個手に入れた!\n", (*st) -> name);
      (*items) -> medicine += 5;

      battle_to_map = 1;

      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area1);

    }
    if ( map.x == 1 && map.y == 9 && (*area) -> event1b == 0 ){
      printf("突然目の前に敵が現れた!\n");
      encount_pattern = 3;
      slime.boss_count = 2;  //通常の敵を強制戦闘用に変更

      game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &slime, encount_pattern);

      slime.boss_count = 0;  //元に戻す
      (*area) -> event1b = 1;

      battle_to_map = 1;

      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area1);

    }
    if ( map.x == 1 && map.y == 5 && (*area) -> event1c == 0 ){
      printf("突然目の前に敵が現れた!\n");
      encount_pattern = 1;
      kobalt.boss_count = 2;  //通常の敵を強制戦闘用に変更

      game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &kobalt, encount_pattern);

      kobalt.boss_count = 0;  //元に戻す
      (*area) -> event1c = 1;

      battle_to_map = 1;

      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area1);

    }
    if ( map.x == 1 && map.y == 1 && (*area) -> event1d == 0 ){
      printf("この先から強力な気配を感じる・・・\n");
      sleep(1);
      printf("%s「この先にヤバそうな悪魔がいるから気を付けよう！」\n", (*st2) -> name);
      (*area) -> event1d = 1;

      event_to_map = 1;

      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area1);

    }
    if ( map.x == 1 && map.y == 0 && (*area) -> boss1 == 0 ){
      printf("BOSSが現れた!\n");

      encount_pattern = 1;

      game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &goblin, encount_pattern);

      (*area) -> boss1 = 1;
      printf("BOSSを倒した!\n");
      sleep(1);
      printf("足元に何か落ちている...\n");
      sleep(1);
      printf("%sはHPリング1を手に入れた!\n", (*st) -> name);
      (*pEquip) -> HpRing1++;
      (*p2Equip) -> HpRing1++;
      (*p3Equip) -> HpRing1++;
      sleep(1);
      clear_count = 1;
    }

  }while ( clear_count == 0 );

  printf("ダンジョンから出た!\n");

}

void area2_map(Area **area, Player **st, Player **st2, Player **st3, P_skill **player_skill, P_skill **player_skill2, P_skill **player_skill3, Setting_skill **setting_skill, Setting_skill **setting_skill2, Setting_skill **setting_skill3, Items **items, Equip **pEquip, Equip **p2Equip, Equip **p3Equip, SearchDangeon **search){

  int area_data_len, area_data_line;
  int i, j, file_output;
  int enemy_count, encount_pattern, clear_count;
  int enemy_appearance_per;
  Map map;
  FILE *fp;

  //name hp, maxhp, mp, maxmp, atk, magic, str, agi, luk, lv, exp, gold, badstatus, physical_attack, gun_attack, fire, ice, elec, wave, almighty, death, expel, poison, palyze, charm, close, stone, panic, sleep, curse, boss_count, enemy_id
  Enemy slime = {"スライム", 10, 10, 0, 0, 2, 1, 1, 1, 1, 1, 5, 30, 0, 150, 100, 200, 100, 100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 0, 1};
  Enemy kobalt = {"コボルト", 20, 20, 0, 0, 2, 1, 2, 1, 1, 2, 10, 55, 0, 80, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 2};
  Enemy zombiedog = {"ゾンビドッグ", 30, 30, 0, 0, 2, 1, 3, 5, 1, 3, 8, 45, 0, 100, 100, 200, 200, 100, 100, 100, -1, 200, 100, 100, 100, 100, 100, 100, 100, 100, 0, 4};
  Enemy ghoul = {"グール", 30, 30, 10, 10, 1, 1, 1, 1, 1, 2, 10, 60, 0, 100, 100, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 5};
  Enemy zombie = {"ゾンビ", 55, 55, 12, 12, 3, 1, 3, 2, 1, 2, 6, 40, 0, 100, 100, 200, 100, 200, 100, 100, -1, 200, 100, 100, 100, 100, 100, 100, 100, -1, 0, 6};
  Enemy goblin_normal = {"ゴブリン", 70, 70, 0, 0, 3, 1, 3, 2, 1, 3, 10, 70, 0, 100, 150, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 7};  //通常敵
  Enemy onmoraki = {"オンモラキ", 50, 50, 15, 15, 2, 3, 2, 3, 2, 4, 12, 65, 0, 80, 100, -1, 200, 100, 100, 100, -1, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 8};
  Enemy gremlin = {"グレムリン", 350, 350, 500, 500, 4, 5, 4, 5, 5, 6, 100, 800, 0, 100, 100, 200, 200, 100, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 9}; //boss

  int area_data[27][10] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  4, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  4,  0,  0,  1,  0,  0,  9,  5, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 5,  9,  0,  0,  1,  0,  0,  4, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 4,  0,  0,  0,  1,  0,  0,  7,  0,  4},
    {-1, -1, -1, -1,  0, -1, -1,  0, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1,  6,  0,  4},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 4,  0,  0,  0,  1,  0,  0,  0,  0,  4},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {4,   7,  0,  0,  1,  0,  0,  0,  0,  4},
    {-1,  0, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  0, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  4, -1, -1, 100, -1,-1, -1, -1, -1},     //start
    {-1, -1, -1, -1, 101, -1, -1, -1, -1, -1} };  //26

  int automap_area2[27][10] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0,  0, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {-1, -1, -1, -1,  0, -1, -1,  0, -1, -1},
    {-1, -1, -1, -1,  0, -1, -1,  0,  0,  0},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1},
    {0,   0,  0,  0,  0,  0,  0,  0,  0,  0},
    {-1,  0, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  0, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1,  0, -1, -1,  0, -1,-1, -1, -1, -1},     //start
    {-1, -1, -1, -1,  0, -1, -1, -1, -1, -1} };  //26

  area_data_len = 10;
  area_data_line = sizeof(area_data) / sizeof(int) / area_data_len;

  //Automapデータの呼び出し
  if ( saveFile == 1 ){
    if ( getFileSize( "AutoMapArea2/saveFile1_AutoMapArea2.dat") != 0 ){
      if ( ( fp = fopen("AutoMapArea2/saveFile1_AutoMapArea2.dat", "rb") ) != NULL ){
        for ( j = 0; j < area_data_line; j++ ){
          for ( i = 0; i < area_data_len; i++ ){
            fread(&file_output, sizeof(int), 1, fp);
            //printf("file_output:%d", file_output);
            if ( file_output != -10 ){
              automap_area2[j][i] = file_output;
              //printf("%d ",automap_area2[j][i]);
            }
          }
          //printf("\n");
        }
        fclose(fp);
      }
    }
  }
  else if ( saveFile == 2 ){
    if ( getFileSize( "AutoMapArea2/saveFile2_AutoMapArea2.dat") != 0 ){
      if ( ( fp = fopen("AutoMapArea2/saveFile2_AutoMapArea2.dat", "rb") ) != NULL ){
        for ( j = 0; j < area_data_line; j++ ){
          for ( i = 0; i < area_data_len; i++ ){
            fread(&file_output, sizeof(int), 1, fp);
            //printf("file_output:%d", file_output);
            if ( file_output != -10 ){
              automap_area2[j][i] = file_output;
              //printf("%d ",automap_area2[j][i]);
            }
          }
          //printf("\n");
        }
        fclose(fp);
      }
    }
  }
  else if ( saveFile == 3 ){
    if ( getFileSize( "AutoMapArea2.dat") != 0 ){
      if ( ( fp = fopen("AutoMapArea2/saveFile3_AutoMapArea2.dat", "rb") ) != NULL ){
        for ( j = 0; j < area_data_line; j++ ){
          for ( i = 0; i < area_data_len; i++ ){
            fread(&file_output, sizeof(int), 1, fp);
            //printf("file_output:%d", file_output);
            if ( file_output != -10 ){
              automap_area2[j][i] = file_output;
              //printf("%d ",automap_area2[j][i]);
            }
          }
          //printf("\n");
        }
        fclose(fp);
      }
    }
  }
  else{

  }

  //start地点の設定
  map.y = 25;
  map.x = 4;
  automap_area2[map.y][map.x] = 1;
  map.walk_step = 0;

  (*area) -> encount = 1;

  (*area) -> dangeonId = 2; //図書館

  printf("---1F図書館---\n");

  if ( (*area) -> encount == 1 ){
    printf("ENEMY ENCOUNT --YES--\n");
  }
  else{
    printf("ENEMY ENCOUNT --NO--\n");
  }

  printf(" ---------------------------- \n");
  printf(" |＼                     ／ | \n");
  printf(" |  ＼                 ／   | \n");
  printf(" |    ＼_____________／     | \n");
  printf(" |   　|             |      | \n");
  printf(" |     |             |      | \n");
  printf(" |     |             |      | \n");
  printf(" |     |_____________|      | \n");
  printf(" |    ／              ＼    | \n");
  printf(" |  ／                  ＼  | \n");
  printf(" |／______________________＼| \n");
  printf("\n");

  printf("---MAP---\n");
  printf("| ↑  |\n");
  printf("|____ |\n");

  clear_count = 0;
  do{
    player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area2);  //playerの移動に関する関数
    //event処理
    if ( map.x == 8 && map.y == 3 && (*area) -> boss2 == 0 ){
      printf("\n");
      printf("...\n");
      sleep(2);
      printf("？「誰？」\n");
      sleep(2);
      printf("？「人間がいる～！」\n");
      sleep(2);
      printf("？「僕はグレムリンって言うんだ！」\n");
      sleep(2);
      printf("グレムリン「ここには本がいっぱいあってたくさん勉強できるから楽しいね！！」\n");
      sleep(2);
      printf("グレムリン「何だか賢くなった気がする～」\n");
      sleep(2);
      printf("グレムリン「ん？ここから出て行けって？」\n");
      sleep(2);
      printf("グレムリン「まさか、僕の勉強の邪魔をする気だな」\n");
      sleep(2);
      printf("グレムリン「こうなったら、僕の賢さを見せつけてやる！」\n");
      sleep(1);

      encount_pattern = 1;
      game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &gremlin, encount_pattern);

      (*area) -> boss2 = 1;
    }
    else if ( map.x == 7 && map.y == 3 && (*area) -> event2a == 0 ){
      printf("この先から強力な気配を感じる...\n");
      printf("\n");
      (*area) -> event2a = 1;
      event_to_map = 1;
      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area2);
    }
    else if ( map.x == 4 && map.y == 26 ){
      printf("ダンジョンから脱出した...\n");
      sleep(1);
      printf("\n");

      save_autoMap(&area,area_data_line,area_data_len,automap_area2);

      return;
    }
    else if ( map.x == 0 && map.y == 11 ){  //map.x 0 map.y 11
      printf("目の前が光に包まれた...\n");
      sleep(1);
      printf("%sはワープした!\n", (*st) -> name);
      map.x = 4;
      map.y = 25;
      event_to_map = 1;

      player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area2);
    }
    else{
      //敵とエンカウント
      if ( battle_mode == 1 ){
        enemy_appearance_per = (rand() % ( 100 - 1 + 1 ) + 1);
        if ( enemy_appearance_per >= 1 && enemy_appearance_per <= 10 ){
          encount_pattern = 1;
          //zombie1体
          game_battle(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &zombie, encount_pattern);
        }
        else if ( enemy_appearance_per <= 25 ){  //オンモラキ１体+ゾンビドッグ1体+コボルト1体
          encount_pattern = 6;
          game_battle_encount_pattern6(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &zombiedog, &onmoraki, &kobalt, encount_pattern);
        }
        else if ( enemy_appearance_per <= 40 ){  //スライム1体+ゾンビ1体
          encount_pattern = 5;
          game_battle_encount_pattern5(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &slime, &zombie, encount_pattern);
        }
        else if ( enemy_appearance_per <= 60 ){  //コボルト1体+ゴブリン1体
          encount_pattern = 5;
          game_battle_encount_pattern5(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &goblin_normal, &kobalt, encount_pattern);
        }
        else if ( enemy_appearance_per <= 75 ){ //ゴブリン1体+オンモラキ1体
          encount_pattern = 5;
          game_battle_encount_pattern5(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2,&setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &goblin_normal, &onmoraki, encount_pattern);
        }
        else if ( enemy_appearance_per <= 85 ){  //スライム1体+ゾンビドッグ1体+コボルト1体+ゾンビ1体
          encount_pattern = 7;
          game_battle_encount_pattern7(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &slime, &kobalt, &zombiedog, &zombie,encount_pattern);
        }
        else{
          encount_pattern = 5;   //ゾンビ1体+オンモラキ1体
          game_battle_encount_pattern5(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &zombie, &onmoraki, encount_pattern);
        }

        battle_mode = 0;

        battle_to_map = 1;
        player_move(&st, &st2, &st3, &player_skill, &player_skill2, &player_skill3, &setting_skill, &setting_skill2, &setting_skill3, &items, &pEquip, &p2Equip, &p3Equip, &search, &map, &area, area_data_line, area_data_len, area_data, automap_area2);
      }
    }

  }while ( clear_count == 0 );

}

void save_area2(int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]){
  int i, j;
  int temp;
  int checkNum;
  FILE *fp;

  if ( saveFile == 1 ){
    if ( ( fp = fopen( "AutoMapArea2/saveFile1_AutoMapArea2.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else if ( saveFile == 2 ){
    if ( ( fp = fopen( "AutoMapArea2/saveFile2_AutoMapArea2.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else if ( saveFile == 3 ){
    if ( ( fp = fopen( "AutoMapArea2/saveFile3_AutoMapArea2.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else{

  }

  for ( j = 0; j < area_data_line; j++ ){
    for ( i = 0; i < area_data_len; i++ ){
      temp = automap_area[j][i];
      fwrite(&temp, sizeof(int), 1, fp);
    }
  }

  fclose(fp);
}

void save_area3(int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]){
  int i, j;
  int temp;
  int checkNum;
  FILE *fp;

  if ( saveFile == 1 ){
    if ( ( fp = fopen( "AutoMapArea3/saveFile1_AutoMapArea3.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else if ( saveFile == 2 ){
    if ( ( fp = fopen( "AutoMapArea3/saveFile2_AutoMapArea3.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else if ( saveFile == 3 ){
    if ( ( fp = fopen( "AutoMapArea3/saveFile3_AutoMapArea3.dat", "wb" ) ) == NULL ){
      printf("マップデータを記録できませんでした\n");
      return;
    }
  }
  else{

  }

  for ( j = 0; j < area_data_line; j++ ){
    for ( i = 0; i < area_data_len; i++ ){
      temp = automap_area[j][i];
      fwrite(&temp, sizeof(int), 1, fp);
    }
  }

  fclose(fp);
}

void save_autoMap(Area ***area, int area_data_line, int area_data_len, int automap_area[area_data_line][area_data_len]){
  int input;
  int i, j;
  FILE *fp;

  if ( (**area) -> dangeonId == 2 ){
    save_area2(area_data_line,area_data_len,automap_area);
  }
  else if ( (**area) -> dangeonId == 3 ){
    save_area3(area_data_line,area_data_len,automap_area);
  }

}
