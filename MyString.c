#include <stdio.h>
#include <string.h>

int main() {
    // 1.���Ķ���ͳ�ʼ��
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];

    // 2.��ȡ���ĳ���
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    printf("str1�ĳ���Ϊ��%d\n", str1len);
    printf("str2�ĳ���Ϊ��%d\n", str2len);

    // 3.��������
    for (int i = 0; i < str1len; ++i) {
        printf("str1�ĵ�%d���ַ��� %c\n", i, str1[i]);
    }

    // 4.���ĸ�ֵ
    strcpy(str3, str1);
    printf("str3��ֵ����ַ��� %s\n", str3);

    // 5.���ıȽ�
    if (strcmp(str1, "Hello, ") == 0) {
        printf("�ַ������\n");
    } else {
        printf("�ַ��������\n");
    }

    // 6.����ƴ��
    strcat(str3, str2);
    printf("ƴ�Ӻ��str3: %s", str3);

    return 0;
}
