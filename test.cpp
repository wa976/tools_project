#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<stralign.h>
#include <malloc.h>


#define pause system("pause > nul")    //그냥 내가 많이 쓰는 커맨드를 줄여준 것이다.
#define cls system("cls") 

void SetColor(int color);
void mainPtr(void);
void gotoxy(int x, int y);
void CursorView(char show);
void Teacher_close();
void Teacher_open();

int main(void)
{
	int score = 1;
	int POS = 4;
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	mainPtr();
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 3;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 3) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(10, 4); printf("새로  하기");
			SetColor(15);
			gotoxy(35, 4); printf("이어  하기");
			gotoxy(60, 4); printf("랭킹  보기");
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 1:
			gotoxy(10, 4); printf("새로  하기");
			SetColor(11);
			gotoxy(35, 4); printf("이어  하기");
			SetColor(15);
			gotoxy(60, 4); printf("랭킹  보기");
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 2:
			gotoxy(10, 4); printf("새로  하기");
			gotoxy(35, 4); printf("이어  하기");
			SetColor(11);
			gotoxy(60, 4); printf("랭킹  보기");
			SetColor(15);
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 3:
			gotoxy(10, 4); printf("새로  하기");
			gotoxy(35, 4); printf("이어  하기");
			gotoxy(60, 4); printf("랭킹  보기");
			SetColor(11);
			gotoxy(85, 4); printf("게임  종료");
			SetColor(15);
			break;
		default: break;
		}
		Sleep(100);
	}
	cls;
	if (POS == 0) puts("새로 하기를 눌렀습니다.");
	else if (POS == 1) puts("이어 하기를 눌렀습니다.");
	else if (POS == 2) puts("랭킹 보기를 눌렀습니다.");


	while(1)
	{
		Teacher_close();
			if (_kbhit())
			{
				if (_getch() == ' ')
				score = score + 1;
				gotoxy(90, 8); printf("score = %d", score);
			}

		Teacher_open();
		if (_kbhit())
		{
			if (_getch() == ' ')
				break;

		}
		
			
	}
	return 0;
}



void view_score() //스페이스바 한번당 1점 출력하는 함수
{

}

void view_time() //60초 제한시간 출력하는 함수
{

}


void Teacher_close()
{
		//system("cls");
		int a = 0;
		int b = 0;
		a = rand() % 5 + 2; // 난수 생성(2~6초까지)
		b = 600 * a;
		gotoxy(50, 4); printf("ㅡ    ㅡ\n");
		Sleep(b);
}


void Teacher_open()
{
	//system("cls");
	int a = 0;
	int b = 0;
	a = rand() % 5 + 2; // 난수 생성(2~6초까지)
	b = 600 * a;
	gotoxy(50, 4); printf("o      o\n");
	Sleep(b);
}


void mainPtr(void) {
	system("mode con: cols=106 lines=9");   //참고로 cols 2단위가 특수문자 또는 한글 1글자다.
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
	gotoxy(10, 4); printf("새로  하기");
	gotoxy(35, 4); printf("이어  하기");
	gotoxy(60, 4); printf("랭킹  보기");
	gotoxy(85, 4); printf("게임  종료");
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