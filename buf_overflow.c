#include <stdio.h>
#include <string.h>

int main() {
    int auth_flag = 0;       // 0이면 미인증, 1이면 인증 성공
    char buffer[8];          // 8바이트 크기의 입력 공간

    printf("현재 auth_flag의 값: %d (주소: %p)\n", auth_flag, (void*)&auth_flag);
    printf("buffer의 주소: %p\n", (void*)buffer);
    printf("------------------------------------------\n");

    printf("이름을 입력하세요 (8글자 이내): ");
    
    // 위험한 코드: 입력 길이를 제한하지 않는 %s 사용
    scanf("%s", buffer); 

    printf("\n입력된 문자열: %s\n", buffer);
    printf("입력 후 auth_flag의 값: %d\n", auth_flag);

    if (auth_flag != 0) {
        printf("!!! [경고] 인증을 우회하였습니다! 관리자 권한을 획득합니다. !!!\n");
    } else {
        printf("인증에 실패하였습니다. 일반 사용자 모드입니다.\n");
    }

    return 0;
}
