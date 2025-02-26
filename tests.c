#include <assert.h>
#include <stdio.h>
#define DINO_IMPLEMENTION 
#include "dinoarray.h"

#define PROJECT_NAME "dinoArray"

char simpleTest(void) {
    int* arr = dinoCreate(int);
    dinoPush(arr, 5);
    assert(arr[0] == 5);
    dinoDestroy(arr);
    printf("SimpleTest Passed\n");
    return 0;
}

char pushPopTest(void) {
    int* arr2 = dinoCreate(int);
    for (int i = 0; i < 100; i++) {
        dinoPush(arr2, i);
    }
    for (int i = 0; i < 100; i++) {
        assert(arr2[i] == i);
    }
    dinoDestroy(arr2);
    printf("pushPopTest Passed\n");
    return 0;
}

char passToFunc2(int** arr) {
    for (int i = 100; i < 200; i++) {
        dinoPush(*arr, i);
    }
    return 0;
}

char passToFunc(void) {
    int* arr2 = dinoCreate(int);
    for (int i = 0; i < 100; i++) {
        dinoPush(arr2, i);
    }
    for (int i = 0; i < 100; i++) {
        assert(arr2[i] == i);
    }
    passToFunc2(&arr2);
    for (int i = 100; i < 200; i++) {
        assert(arr2[i] == i);
    }
    dinoDestroy(arr2);
    printf("passToFunc Passed\n");
    return 0;
}

int main(void) {
    printf("Starting Tests...\n");
    simpleTest();
    pushPopTest();
    passToFunc();
    printf("Finished Tests\n");
    return 0;
}
