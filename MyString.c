#include <stdio.h>
#include <string.h>

int main() {
    // 1.串的定义和初始化
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];

    // 2.获取串的长度
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    printf("str1的长度为：%d\n", str1len);
    printf("str2的长度为：%d\n", str2len);

    // 3.串的索引
    for (int i = 0; i < str1len; ++i) {
        printf("str1的第%d个字符是 %c\n", i, str1[i]);
    }

    // 4.串的赋值
    strcpy(str3, str1);
    printf("str3赋值后的字符串 %s\n", str3);

    // 5.串的比较
    if (strcmp(str1, "Hello, ") == 0) {
        printf("字符串相等\n");
    } else {
        printf("字符串不相等\n");
    }

    // 6.串的拼接
    strcat(str3, str2);
    printf("拼接后的str3: %s", str3);

    return 0;
}
