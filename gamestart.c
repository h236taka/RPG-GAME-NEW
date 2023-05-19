#include <stdio.h>
#include <time.h>

void main(){
  struct timespec req = {0, 100000000};

  printf("　　　　　＊\n"); //左は全角5つ分のスペース。
  nanosleep(&req,NULL);
  printf("　　　　＊＊＊\n"); //左は全角4つ分のスペース。
  nanosleep(&req,NULL);
  printf("　　　＊＊＊＊＊\n"); //左は全角3つ分のスペース。
  nanosleep(&req,NULL);
  printf("＊＊＊＊＊＊＊＊＊＊＊\n"); //アスタリスクは11個。
  nanosleep(&req,NULL);
  printf("　＊＊＊＊＊＊＊＊＊\n"); //左は全角1つ分のスペース。
  nanosleep(&req,NULL);
  printf("　　＊＊＊＊＊＊＊\n"); //左は全角2つ分のスペース。
  nanosleep(&req,NULL);
  printf("　　　＊＊＊＊＊\n"); //左は全角3つ分のスペース。
  nanosleep(&req,NULL);
  printf("　　＊＊＊　＊＊＊\n"); //左は全角2つ分のスペース。
  nanosleep(&req,NULL);
  printf("　＊＊＊　　　＊＊＊\n"); //左は全角1つ分のスペース。
  nanosleep(&req,NULL);
  printf("　＊＊　　　　　＊＊\n"); //左は全角1つ分のスペース。
  nanosleep(&req,NULL);

}
