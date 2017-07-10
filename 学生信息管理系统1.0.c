#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ShowMenu_1();
void ShowMenu_2();
void AddStuIfm(char Number[10], char Name[10], char Gender[3], int Age, int Math, int Engilsh, int Chinese);//////////////////添加学生信息
void FindStuIfm_1(char Temp_1[10], int Key);
void FindStuIfm_2(int Temp_1, int Key);
void AllShowIfm();/////////////////////显示所有学生信息
void DelStuIfm(char Number[10]);/////////////////删除学生信息
void RevStuIfm(char Number[10]);//////////////修改学生信息
typedef struct student
{
    char Name[10];
    char Number[10];
    char Gender[3];
    int Age;
    int Math;
    int Engilsh;
    int Chinese;
    int Total;
    struct student *next;
}Stu;
Stu *Head = NULL;
Stu *End = NULL;
int main()
{
    int Key;
    char Number[10], Name[10], Gender[3];
    int Age, Math, Chinese, Engilsh;
    ShowMenu_1();
    do
    {
      scanf("%d", &Key);
    switch(Key)
    {
        case 1:
            printf("请输入学号:");
            do
            {
                scanf("%s", Number);
                if(strlen(Number) != 9)
                    printf("输入有误!请重新输入:");
            }while(strlen(Number) != 9);

            printf("请输入姓名:");
            scanf("%s", Name);

            printf("请输入性别:");
            do
            {
                scanf("%s", Gender);
                if(strcmp(Gender, "男") != 0 && strcmp(Gender, "女") != 0)
                    printf("输入有误!请重新输入:");
            }while(strcmp(Gender, "男") != 0 && strcmp(Gender, "女") != 0);

            printf("请输入年龄:");
            do
            {
                scanf("%d", &Age);
                if(Age<0 || Age>100)
                    printf("输入有误!请重新输入:");
            }while(Age<0 || Age>100);

            printf("请输入数学成绩:");
            do
            {
                 scanf("%d", &Math);
                if(Math<0 || Math>150)
                    printf("输入有误!请重新输入:");
            }while(Math<0 || Math>150);

            printf("请输入语文成绩:");
            do
            {
                  scanf("%d", &Chinese);
                if(Chinese<0 || Chinese>150)
                    printf("输入有误!请重新输入:");
            }while(Chinese<0 || Chinese>150);

            printf("请输入英语成绩:");
              do
            {
                  scanf("%d", &Engilsh);
                if(Engilsh<0 || Engilsh>150)
                    printf("输入有误!请重新输入:");
            }while(Engilsh<0 || Engilsh>150);

            AddStuIfm(Number, Name, Gender, Age, Math, Engilsh, Chinese);
            break;
        case 2:
            printf("请输入要删除学生信息的学号:\n");
            scanf("%s", Number);
            DelStuIfm(Number);
            break;
        case 3:
            printf("请输入要修改学生信息的学号:\n");
            scanf("%s", Number);
            RevStuIfm(Number);
            break;
        case 4:
            ShowMenu_2();
            break;
        case 5:
            AllShowIfm();
            break;
    }
    }while(Key != 0);

    return 0;
}
void ShowMenu_1()
{
    printf("******************************欢迎使用学生信息管理系统**********************************\n");
    printf("*                                                                                      *\n");
    printf("*                                                                                      *\n");
    printf("*                         1)添加学生信息                                               *\n");
    printf("*                         2)删除学生信息(根据学号删除)                                 *\n");
    printf("*                         3)修改学生信息(根据学号修改)                                 *\n");
    printf("*                         4)查询学生信息                                               *\n");
    printf("*                         5)显示所有学生信息及统计信息                                 *\n");
    printf("*                         0)退出程序                                                   *\n");
    printf("*                                                                                      *\n");
    printf("*                                                                                      *\n");
    printf("****************************************************************************************\n");
}
void ShowMenu_2()
{
    int Key;
    char Number_1[10];
    char Name_1[10];
    int Math_1=0, Chinese_1=0, Engilsh_1=0, Total_1=0;
    system("cls");
    printf("****************************************************************************************\n");
    printf("*                                                                                      *\n");
    printf("*                                                                                      *\n");
    printf("*                         1)根据学号查询                                               *\n");
    printf("*                         2)根据姓名查询                                               *\n");
    printf("*                         3)根据数学成绩查询                                           *\n");
    printf("*                         4)根据语文成绩查询                                           *\n");
    printf("*                         5)根据英语成绩查询                                           *\n");
    printf("*                         6)根据总成绩查询                                             *\n");
    printf("*                         0)返回主菜单                                                 *\n");
    printf("*                                                                                      *\n");
    printf("*                                                                                      *\n");
    printf("****************************************************************************************\n");
    scanf("%d", &Key);
    switch(Key)
    {
        case 1:
            printf("请输入学号:");
            scanf("%s", Number_1);
            FindStuIfm_1(Number_1, Key);
            break;
        case 2:
            printf("请输入姓名:");
            scanf("%s", Name_1);
            FindStuIfm_1(Name_1, Key);
            break;
        case 3:
            printf("请输入数学成绩:");
            scanf("%d", &Math_1);
            FindStuIfm_2(Math_1, Key);
            break;
        case 4:
            printf("请输入语文成绩:");
            scanf("%d", &Chinese_1);
            FindStuIfm_2(Chinese_1, Key);
            break;
        case 5:
            printf("请输入英语成绩:");
            scanf("%d", &Engilsh_1);
            FindStuIfm_2(Engilsh_1, Key);
            break;
        case 6:
            printf("请输入总成绩:");
            scanf("%d", &Total_1);
            FindStuIfm_2(Total_1, Key);
            break;
        case 0:
            system("cls");
            ShowMenu_1();
            break;
    }
}
void AddStuIfm(char Number[10], char Name[10], char Gender[3], int Age, int Math, int Engilsh, int Chinese)
{
    Stu *pTemp = malloc(sizeof(Stu));
    strcpy(pTemp->Number, Number);
    strcpy(pTemp->Name, Name);
    strcpy(pTemp->Gender, Gender);
   pTemp->Age = Age;
   pTemp->Chinese = Chinese;
   pTemp->Engilsh = Engilsh;
   pTemp->Math = Math;
   pTemp->Total = Math+Chinese+Engilsh;
    if(Head == NULL)
    {
        Head = pTemp;
        End = pTemp;
    }
    else
    {
        End->next = pTemp;
        End = pTemp;
    }
    system("cls");
    ShowMenu_1();
    printf("***********************学生信息添加成功！***********************\n");
    printf("请继续输入指令:");
}
void FindStuIfm_1(char Temp_1[10], int Key)
{
    Stu *pTemp = Head;
    char Temp_2[10];
    while(pTemp != End->next)
    {
        if(Key == 1)
            strcpy(Temp_2, pTemp->Number);
        else if(Key == 2)
            strcpy(Temp_2, pTemp->Name);
        if(strcmp(Temp_2, Temp_1) == 0)
        {
            printf("|学号     |姓名     |性别     |年龄     |语文     |数学     |英语     |总成绩   |\n");
            printf("*********************************************************************************\n");
            printf("|%-9s|%-9s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|\n", pTemp->Number, pTemp->Name, pTemp->Gender, pTemp->Age, pTemp->Chinese, pTemp->Math, pTemp->Engilsh, pTemp->Total);
            printf("---------------------------------------------------------------------------------\n");
        }
            pTemp = pTemp->next;
    }
    system("pause");
    system("cls");
    ShowMenu_1();
    printf("请继续输入指令:");
}
void FindStuIfm_2(int Temp_1, int Key)
{
    Stu *pTemp = Head;
    int Temp_2;
    while(pTemp != End->next)
    {
        if(Key == 3)
            Temp_2 = pTemp->Math;
        else if(Key == 4)
            Temp_2 = pTemp->Chinese;
        else if(Key == 5)
            Temp_2 = pTemp->Engilsh;
        else if(Key == 6)
            Temp_2 = pTemp-> Total;
        if(Temp_1 == Temp_2)
        {
            printf("|学号     |姓名     |性别     |年龄     |语文     |数学     |英语     |总成绩   |\n");
            printf("*********************************************************************************\n");
            printf("|%-9s|%-9s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|\n", pTemp->Number, pTemp->Name, pTemp->Gender, pTemp->Age, pTemp->Chinese, pTemp->Math, pTemp->Engilsh, pTemp->Total);
            printf("---------------------------------------------------------------------------------\n");
        }
            pTemp = pTemp->next;
    }
    system("pause");
    system("cls");
    ShowMenu_1();
    printf("请继续输入指令:");
}
void DelStuIfm(char Number[10])
{
    Stu *pTemp_1=Head;
    Stu *pTemp_2=Head;
    int i=0;
    int j=0;
    if(NULL == Head)    printf("链表为空\n");
    else
    {
            while(strcmpi(pTemp_1->Number, Number) != 0)
        {
            pTemp_1 = pTemp_1->next;
            i++;
        }
        if(i == 0)  Head = Head->next;
        for(j=0; j<i-1; j++)
        {
            pTemp_2=pTemp_2->next;
        }
        pTemp_2->next = pTemp_1->next;
        if(pTemp_1 == End)
            End = pTemp_2;
        free(pTemp_1);
        system("cls");
        ShowMenu_1();
        printf("***********************删除数据成功！***********************\n");
        printf("请继续输入指令:");
    }
}
void AllShowIfm()
{
    system("cls");
    Stu *pTemp = Head;
    printf("|学号     |姓名     |性别     |年龄     |语文     |数学     |英语     |总成绩   |\n");
    printf("*********************************************************************************\n");
    while(pTemp != End->next)
    {
       printf("|%-9s|%-9s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|\n", pTemp->Number, pTemp->Name, pTemp->Gender, pTemp->Age, pTemp->Chinese, pTemp->Math, pTemp->Engilsh, pTemp->Total);
       printf("---------------------------------------------------------------------------------\n");
       pTemp = pTemp->next;
    }
    system("pause");
    system("cls");
    ShowMenu_1();
    printf("请继续输入指令:");
}
void RevStuIfm(char Number[10])
{
    char Rev[10] = {0};
    Stu *pTemp = Head;
    system("cls");
    while(strcmp(pTemp->Number, Number) != 0)
    {
        pTemp = pTemp->next;
    }
    if(strcmp(pTemp->Number, Number) == 0)
    {
        printf("|学号     |姓名     |性别     |年龄     |语文     |数学     |英语     |总成绩   |\n");
        printf("*********************************************************************************\n");
        printf("|%-9s|%-9s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|\n", pTemp->Number, pTemp->Name, pTemp->Gender, pTemp->Age, pTemp->Chinese, pTemp->Math, pTemp->Engilsh, pTemp->Total);
        printf("---------------------------------------------------------------------------------\n");
    }
    printf("请输入要修改的内容:");
    scanf("%s", Rev);
    if(strcmp(Rev, "学号") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%s", pTemp->Number);
    }
    else if(strcmp(Rev, "姓名") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%s", pTemp->Name);
    }
    else if(strcmp(Rev, "性别") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%s", pTemp->Gender);
    }
    else if(strcmp(Rev, "年龄") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%d", &pTemp->Age);
    }
    else if(strcmp(Rev, "语文") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%d", &pTemp->Chinese);
    }
    else if(strcmp(Rev, "数学") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%d", &pTemp->Math);
    }else if(strcmp(Rev, "英语") == 0)
    {
        printf("请输入要修改的值:");
        scanf("%d", &pTemp->Engilsh);
    }
    pTemp->Total = pTemp->Chinese+pTemp->Engilsh+pTemp->Math;
    system("cls");
    printf("|学号     |姓名     |性别     |年龄     |语文     |数学     |英语     |总成绩   |\n");
    printf("*********************************************************************************\n");
    printf("|%-9s|%-9s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|\n", pTemp->Number, pTemp->Name, pTemp->Gender, pTemp->Age, pTemp->Chinese, pTemp->Math, pTemp->Engilsh, pTemp->Total);
    printf("---------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    ShowMenu_1();
    printf("***********************修改信息成功！***********************\n");
    printf("请继续输入指令:");
}
