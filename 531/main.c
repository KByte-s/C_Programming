#include "532.h"
int main() {
    char str[20], str2[20], str3, item2[2];
    int item, temp, num;
    printf("------------------------------------------\n");
    printf("1.����Ӣ���ַ���Сдת��\n");
    printf("2.�ַ����ȽϺ���\n");
    printf("3.���������ַ�����ǰһ��Ƶ���һ��\n");
    printf("4.�ж��Ƿ�Ϊ���ִ�\n");
    printf("5.�ַ���תΪ��ֵ��������������\n");
    printf("6.�������ַ���תΪ����\n");
    printf("7.�����ַ���ƴ��\n");
    printf("8.�ж��ַ����Ƿ�Ϊ��ĸ\n");
    printf("9.��ȥ�ַ�����߿ո�\n");
    printf("10.�����ַ������ַ�λ��\n");
    printf("11.ʮ����תʮ������ת�˽���ת������\n");
    printf("------------------------------------------\n");
    while(1){
        printf("������ѡ�");
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
            if(temp == 1) printf("��һ���\n");
            else printf("�ڶ����\n");
        }
        else if(item == 3) {
            scanf("%s", str);
            getchar();
            copy(str,str2);
            printf("�Ѹ���\t%s\n", str2);
        }
        else if(item == 4) {
            scanf("%s", str);
            getchar();
            temp = IfNum(str);
            if(temp == 1) printf("������\n");
            else printf("������\n");
        }
        else if(item == 6) {
            scanf("%s", str);
            getchar();
            printf("��ת��Ϊ����\t%lf\n", deal(str));
        }
        else if(item == 5) {
            getchar();
            gets(str);
            printf("�����Ľ��Ϊ\t%lf\n", FourRules(str));
        }
        else if(item == 7) {
            scanf("%s", str);
            scanf("%s", str2);
            getchar();
            add(str,str2);
            printf("ƴ�Ӻ���%s\n", str);
        }
        else if(item == 8){
            scanf("%s", str);
            getchar();
            temp = Ifchar(str);
            if(temp == 0) printf("����ĸ\n");
            else printf("����ĸ\n");
        }
        else if(item == 9) {
            scanf("%s", str);
            getchar();
            lstrip(str);
            printf("ȥ�ո��%s\n", str);
        }
        else if(item == 10) {
            scanf("%s", str);
            getchar();
            scanf("%c", &str3);
            temp = lfind(str, str3);
            if(temp == -1) printf("δ�ҵ�\n");
            else printf("���ҵ�,�� %d ��\n", temp);
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
