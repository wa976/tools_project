#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<stralign.h>
#include <malloc.h>
#include <process.h>

#define pause system("pause > nul")    
#define cls system("cls") 




int isEnd = 0;
int score = 0;
int state = 0;
int heart = 3;

void SetColor(int color);
void mainPtr(void);
void gotoxy(int x, int y);
void CursorView(char show);





unsigned __stdcall Thread_A(void* arg)
{
    while (1) {

        if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && state == 1) {
            isEnd = 1;
            break;
        }
        else if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) { 
            gotoxy(90, 8); printf("score = %d ", score);
            score++;
            Sleep(200);
        }
        
    }
    return 0;
}


unsigned __stdcall Thread_B(void* arg)
{
    while (1) {
        int a = 0;
        int b = 0;
        a = rand() % 5 + 2; // 난수 생성(2~6초까지)
        b = 600 * a;
        gotoxy(50, 4); printf("ㅡ    ㅡ\n");
        state = 0;
        Sleep(b);


        int c = 0;
        int d = 0;
        c = rand() % 5 + 2; // 난수 생성(2~6초까지)
        d = 600 * a;
        gotoxy(50, 4); printf("o      o\n");
        Sleep(100);
        state = 1;
        Sleep(d);
    }
    return 0;
}





int main(void)
{

    int POS = 0;
    int cnt = 0;
    CursorView(0);    //커서의 깜빡임을 숨겨준다.
    system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
    mainPtr();
    while (true) {
        if (GetAsyncKeyState(VK_LEFT))
            if (POS == 0) POS = 1;
            else POS -= 1;
        else if (GetAsyncKeyState(VK_RIGHT))
            if (POS == 1) POS = 0;
            else POS += 1;
        else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
            break;
        switch (POS) {
        case 0:
            SetColor(11);
            gotoxy(25, 4); printf("새로  하기");
            SetColor(15);
            gotoxy(70, 4); printf("게임  종료");
            break;
        case 1:
            gotoxy(25, 4); printf("새로  하기");
            SetColor(11);
            gotoxy(70, 4); printf("게임  종료");
            SetColor(15);
            break;
        default: break;
        }
        Sleep(100);
    }
    cls;
    if (POS == 0) puts("새로 하기를 눌렀습니다.");
    cls;

    HANDLE th1 = (HANDLE)_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);
    HANDLE th2 = (HANDLE)_beginthreadex(NULL, 0, Thread_B, 0, 0, NULL);
    


    int count = 60;
    while (1) {

        //gotoxy(15, 8); printf("%d", heart);

        if (count >= 10) {
            gotoxy(10, 8); printf("%d", count);
            count = count - 1;
            Sleep(1000);
        }
        if (count == 9) {
            cls;
            gotoxy(11, 8); printf("%d", count);
            count = count - 1;
            Sleep(1000);
        }
        if (count < 9) {
            gotoxy(11, 8); printf("%d", count);
            count = count - 1;
            Sleep(1000);
        }
        if (count == 0)
        {
            break;
        }
        if (isEnd) {
            break;
        }
    }

    printf("\n최종스코어는 : %d", score);

    return 0;
}






void mainPtr(void) {
    system("mode con: cols=106 lines=9");  
    system("title 선생님 몰래 춤추기");
    puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    puts("■                                                                                                      ■");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    gotoxy(25, 4); printf("새로  하기");
    gotoxy(70, 4); printf("게임  종료");
    return;
}

void gotoxy(int x, int y) {

    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}