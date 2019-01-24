#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int getNum(char num1[], char num2[]);
void Reverse(char num[]);
void addition(char str1[], char str2[], int str3[]);
void deal(char str[]);
void deal(char str[])
{
    char temp[100];
    int i = 0;
    strcpy(temp, str);
    if(str[0] == '-'){
        for (i = 1; temp[i] != '\0'; ++i)
            str[i-1] = temp[i];
        str[i-1] = '\0';
    }
}

int getNum(char num1[], char num2[])
{
    int count = 0;
    scanf("%s", num1);
    scanf("%s", num2);
    if(num1[0] == '-' && num2[0] != '-')
        count++;
    if(num1[0] != '-' && num2[0] == '-')
        count += 2;
    if(num1[0] == '-' && num2[0] == '-')
        count += 3;
    deal(num1);deal(num2);
    Reverse(num1);
    Reverse(num2);
    return count;
}

void Reverse(char num[])
{
    char numTemp[100];
    int len, i;
    len = (int)strlen(num);
    for (i = 0; num[i] != '\0'; ++i)
        numTemp[i] = num[len-i-1];
    numTemp[i] = '\0';
    strcpy(num, numTemp);
}

void subtraction(char str1[], char str2[], int str3[])
{
    char temp[100];
    int i, j, num1, num2, carry = 0, minus = 0;
    if((strlen(str1) < strlen(str2))||(strlen(str1) == strlen(str2) && str1[0] < str2[0])){
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
        minus = 1;
    }
    for(i = 0; i < strlen(str2); i++) {
        num1 = str1[i] - '0';
        num2 = str2[i] - '0';
        str3[i] = (num1 - num2 - carry + 10) % 10;
        if(num1 - num2 - carry < 0) carry = 1;
        else carry = 0;
    }
    for(; i <= strlen(str1); i++){
        if(str1[i] != '\0')
            num1 = str1[i]-'0';
        else num1 = 0;
        str3[i] = (num1 - carry + 10) % 10;
        if(num1 - carry < 0) carry = 1;
        else carry = 0;
    }
    if(str3[i - 2] != 0)
        str3[i - 1] = -1;
    else str3[i - 2] = -1;
    for (j = 0; str3[j] != -1; ++j);
    if(minus == 1) printf("-");
    for (i = 0; str3[i] != -1; ++i)
        printf("%d", str3[j-i-1]);
    printf("\n");
}
void addition(char str1[], char str2[], int str3[])
{
    char temp[100];
    int i, j, num1, num2, carry = 0;
    if((strlen(str1) < strlen(str2))||(strlen(str1) == strlen(str2) && str1[0] < str2[0])){
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }
    for(i = 0; i < strlen(str2); i++){
        num1 = str1[i]-'0';
        num2 = str2[i]-'0';
        str3[i] = (num1 + num2 + carry) % 10;
        carry = (num1 + num2 + carry) / 10;
    }
    for(; i <= strlen(str1); i++){
        if(str1[i] != '\0')
            num1 = str1[i]-'0';
        else num1 = 0;
        str3[i] = (num1 + carry) % 10;
        carry = (num1 + carry) / 10;
    }
    if(str3[i-1] != 0)
        str3[i] = -1;
    else str3[i - 1] = -1;
    for (j = 0; str3[j] != -1; ++j);
    for (i = 0; str3[i] != -1; ++i)
        printf("%d", str3[j-i-1]);
    printf("\n");
}

int main()
{
    char num1[100], num2[100];
    int item, PriNum[100] = {0}, type;
    printf("--------------------------\n");
    printf("0.退出\n");
    printf("1.加法\n");
    printf("2.减法\n");
    printf("--------------------------\n");
    while(1){
        printf("请输入：");
        scanf("%d", &item);
        if (item != 1 && item != 2)
            break;
        type = getNum(num1, num2);
        if(item == 1) {
            if (type == 0)
                addition(num1, num2, PriNum);
            else if (type == 1)
                subtraction(num2, num1, PriNum);
            else if (type == 2)
                subtraction(num1, num2, PriNum);
            else if (type == 3) {
                printf("-");
                addition(num1, num2, PriNum);
            }
        }
        else if(item == 2) {
            if (type == 0)
                subtraction(num1, num2, PriNum);
            else if (type == 1) {
                printf("-");
                addition(num1, num2, PriNum);
            }
            else if (type == 2)
                addition(num1, num2, PriNum);
            else if (type == 3)
                subtraction(num2, num1, PriNum);
        }
    } return 0;
}
