// 1. 코드 영역 (Code/Text Section) : 실행되는 함수(기계어 명령) 자체가 위치
#include <stdio.h>
#include <stdlib.h>

// 2. 데이터 영역 (Data Section) : 전역 변수와 정적 변수가 위치
int global_initialized = 10; 
static int static_initialized = 20;

 // 3. 스택 영역 (Stack Section) : 함수 호출 시, 내부의 지역 변수와 매개변수가 위치
void dummy_function() {
    return;
}
 // 3. 스택 영역 (Stack Section) : 함수 내부의 지역 변수와 매개변수가 위치
int main() {
    int stack_var = 100;
    int stack_var2 = 200;

    // 4. 힙 영역 (Heap Section) : 프로그래머가 malloc 등으로 동적 할당한 공간
    int *heap_ptr1 = (int*)malloc(sizeof(int));
    int *heap_ptr2 = (int*)malloc(sizeof(int));

    printf("=== 메모리 영역별 주소 확인 ===\n\n");

    // 코드 영역 주소 출력
    printf("[Code 영역] 함수 주소:      %p\n", (void*)dummy_function);
    printf("[Code 영역] main 함수 주소: %p\n\n", (void*)main);

    // 데이터 영역 주소 출력
    printf("[Data 영역] 전역 변수 주소: %p\n", (void*)&global_initialized);
    printf("[Data 영역] 정적 변수 주소: %p\n\n", (void*)&static_initialized);

    // 힙 영역 주소 출력 (주소가 점점 높아지는지 확인)
    printf("[Heap 영역] 첫 번째 할당:   %p\n", (void*)heap_ptr1);
    printf("[Heap 영역] 두 번째 할당:   %p\n\n", (void*)heap_ptr2);

    // 스택 영역 주소 출력 (주소가 점점 낮아지는지 확인)
    printf("[Stack 영역] 첫 번째 지역변수: %p\n", (void*)&stack_var);
    printf("[Stack 영역] 두 번째 지역변수: %p\n\n", (void*)&stack_var2);


    // 힙 영역에 할당한 메모리 해제(반납)
    free(heap_ptr1);
    free(heap_ptr2);

    return 0;
}
