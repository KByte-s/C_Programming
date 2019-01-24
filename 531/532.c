//
// Created by 11039 on 2018/5/31.
//
#include "532.h"
void toggle(char str[])
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
}

int relative(char str1[], char str2[])
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; str1[i] != '\0'; ++i)
        sum1 += (int)deal(&str1[i]);
    for (int j = 0; str2[j] != '\0'; ++j)
        sum2 += (int)deal(&str2[j]);
    if(sum1 >= sum2)
        return 1;
    return 0;
}

void copy(char *strold, char *strnew)
{
    while(*strold != '\0'){
        *strnew = *strold;
        strnew++;
        strold++;
    }
    *strnew = '\0';
}

int IfNum(char str[])
{
    for (int i = 0; str[i] != '\0'; ++i)
        if(str[i] <= '0' || str[i] >= '9')
            return 0;
    return 1;
}

int Symbol(char str)
{
    if(str == '+')return 0;
    else if(str == '-') return 1;
    else if(str == '*') return 2;
    else if(str == '/') return 3;
    else if(str >= '0' && str <= '9') return 4;
    else return -1;
}

double deal(char nums[])
{
    double num = 0;
    for (int i = 0; i < strlen(nums); ++i)
        num += (nums[i] - '0') * pow(10,(strlen(nums) - i - 1));
    return num;
}

double FourRules(char str[])
{
   char *p = str, nums[20];
   double sum = 0, num1, num2;
   int temp = 0, oper, i;
   while (*p == ' ') p++;
   if(*p == '+') {
       temp = 1; p++;
   }
   else if(*p == '-') {
       temp = 2; p++;
   }
   while (Symbol(*p) != 4) p++;
   for (i = 0; Symbol(*p) == 4; ++i, p++)
       nums[i] = *p;
   nums[i] = '\0'; p--;
   num1 = deal(nums);
   if(temp == 2) num1 *= -1;
   while (Symbol(*p) < 0 || Symbol(*p) > 3)
       p++;
   oper = Symbol(*p);
   p++;
   while (Symbol(*p) == -1) p++;
   if(*p == '+') {
        temp = 1; p++;
   }
   else if(*p == '-') {
        temp = 2; p++;
   }
   while (Symbol(*p) != 4) p++;
   for (i = 0; Symbol(*p) == 4; ++i, p++)
       nums[i] = *p;
   nums[i] = '\0';
   p--;
   num2 = deal(nums);
   if(temp == 2) num2 *= -1;
   if(oper == 0)
       sum = num1 + num2;
   else if(oper == 1)
       sum = num1 - num2;
   else if(oper == 2)
       sum = num1 * num2;
   else if(oper ==3)
       sum = num1 / num2;
   return sum;
}

void add(char fir[], char sec[])
{
    int n, m;
    n = strlen(fir);
    m = strlen(sec);
    for(int i = 0; i < m+1; i++)
        fir[n+i] = sec[i];
}

int Ifchar(char str[])
{
    for (int i = 0; str[i] != '\0'; ++i)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 1;
    return 0;
}

void lstrip(char str[])
{
    char strs[100]; int i;
    strcpy(strs, str);
    for (i = 0; strs[i] != '\0'; ++i)
        if(strs[i] != ' ')
            str[i] = strs[i];
    str[i] = '\0';
}

int lfind(char str[], char aim)
{
    int i;
    for (i = 0; str[i] != '\0'; ++i)
        if (str[i] == aim)
            return i;
    return -1;
}

void decimalchange(int class, char str[])
{
    int num = (int)deal(str);
    char s[10];
    if(class == 16)
        printf("%x\n", num);
    else if(class == 8)
        printf("%o\n", num);
    else if(class == 2){
        itoa(num, s, 2);
        printf("%s\n", s);
    }
    else printf("为十进制数“%d”\n", num);
}
