#include "532.h"
int main() {
    char str[20], str2[20], str3, item2[2];
    int item, temp, num;
    printf("------------------------------------------\n");
    printf("1.输入英文字符大小写转换\n");
    printf("2.字符串比较函数\n");
    printf("3.输入两个字符串将前一项复制到后一项\n");
    printf("4.判断是否为数字串\n");
    printf("5.字符串转为数值，进行四则运算\n");
    printf("6.将数字字符串转为数字\n");
    printf("7.两个字符串拼接\n");
    printf("8.判断字符串是否为字母\n");
    printf("9.除去字符串左边空格\n");
    printf("10.查找字符串中字符位置\n");
    printf("11.十进制转十六进制转八进制转二进制\n");
    printf("------------------------------------------\n");
    while(1){
        printf("请输入选项：");
        scanf("%s", item2);
        item = (int)deal(item2);
        if(item == 1){
            scanf("%s", str);
            getchar();
            toggle(str);
            printf("%s\n", str);
        }
        else if(item == 2){
            scanf("%s", str);
            scanf("%s", str2);
            getchar();
            temp = relative(str,str2);
            if(temp == 1) printf("第一项大\n");
            else printf("第二项大\n");
        }
        else if(item == 3) {
            scanf("%s", str);
            getchar();
            copy(str,str2);
            printf("已复制\t%s\n", str2);
        }
        else if(item == 4) {
            scanf("%s", str);
            getchar();
            temp = IfNum(str);
            if(temp == 1) printf("是数字\n");
            else printf("非数字\n");
        }
        else if(item == 6) {
            scanf("%s", str);
            getchar();
            printf("已转换为数字\t%lf\n", deal(str));
        }
        else if(item == 5) {
            getchar();
            gets(str);
            printf("计算后的结果为\t%lf\n", FourRules(str));
        }
        else if(item == 7) {
            scanf("%s", str);
            scanf("%s", str2);
            getchar();
            add(str,str2);
            printf("拼接后结果%s\n", str);
        }
        else if(item == 8){
            scanf("%s", str);
            getchar();
            temp = Ifchar(str);
            if(temp == 0) printf("是字母\n");
            else printf("非字母\n");
        }
        else if(item == 9) {
            scanf("%s", str);
            getchar();
            lstrip(str);
            printf("去空格后%s\n", str);
        }
        else if(item == 10) {
            scanf("%s", str);
            getchar();
            scanf("%c", &str3);
            temp = lfind(str, str3);
            if(temp == -1) printf("未找到\n");
            else printf("已找到,在 %d 处\n", temp);
        }
        else if(item == 11) {
            scanf("%s", str);
            scanf("%d", &num);
            getchar();
            decimalchange(num, str);
        }
        else if(item == 0)
            break;
    } return 0;
}
