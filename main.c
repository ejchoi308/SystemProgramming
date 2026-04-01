// main.c
#include <stdio.h>
#include "cal.h"

int main() {
    int x = 10, y = 20;
    printf("시스템 프로그래밍 실습: %d + %d = %d\n", x, y, add(x, y));
    return 0;
}
