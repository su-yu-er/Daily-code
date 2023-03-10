
#include"game1.h"
void menu()
{
	printf("**********************\n");
	printf("*****1.#子棋PLAY******\n");
	printf("**********************\n");
	printf("****2.#子棋玩家pk*****\n");
	printf("**********************\n");
	printf("****3.五子棋玩家pk****\n");
	printf("**********************\n");
	printf("****0.退出游戏EXIT****\n");
	printf("**********************\n");
}
//游戏1--三子棋人机
void game1()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//初始化(数组)棋盘
	InitBoard3(board, ROW, COL);
	printf("\n");
	//打印棋盘
	DisplayBoard3(board, ROW, COL);
	printf("\n");
	//下棋的实现
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
        printf("\n");
		//判断输赢
		ret = Iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！！\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢！！\n");
	}
	else
	{
		printf("   —平局—\n");
	}
}

//游戏2--三子棋玩家pk
void game2()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化(数组)棋盘
	InitBoard3(board, ROW, COL);
	printf("\n");
	//打印棋盘
	DisplayBoard3(board, ROW, COL);
	printf("\n");
	//下棋的实现
	while (1)
	{
		//玩家1下棋
		PlayerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}

		//玩家2下棋
		Player2Move(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家1赢！！\n");
	}
	else if (ret == '#')
	{
		printf("玩家2赢！！\n");
	}
	else
	{
		printf("   —平局—\n");
	}
}

//游戏3--五子棋玩家pk
void game3()
{
	char ret = 0;
	char board[FIVE_X][FIVE_Y] = { 0 };
	//初始化(数组)棋盘
	InitBoard5(board, FIVE_X, FIVE_Y);
	printf("\n");
	//打印棋盘
	DisplayBoard5(board, FIVE_X, FIVE_Y);
	printf("\n");
	//下棋的实现
	while (1)
	{
		//玩家1下棋
		PlayerMove5(board, FIVE_X, FIVE_Y);
		printf("\n");
		DisplayBoard5(board, FIVE_X, FIVE_Y);
		printf("\n");
		//判断输赢
		ret = Iswin(board, FIVE_X, FIVE_Y);
		if (ret != 'c')
		{
			break;
		}

		//玩家2下棋
		Player2Move5(board, FIVE_X, FIVE_Y);
		printf("\n");
		DisplayBoard5(board, FIVE_X, FIVE_Y);
		printf("\n");
		//判断输赢
		ret = Iswin(board, FIVE_X, FIVE_Y);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！！\n");
	}
	else
	{
		printf("   —平局—\n");
	}
}

void test()
{
	int input = 0;
	//时间计数随机变量
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		int a = 3;
		int b = 4;
		int c = 5;
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		
		//三子棋
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 0:
			printf("退出游戏\n");
			break;

		//五子棋
		case 3:
			game3();
			break;
		/*case 4:
			game();
			break;
		case 5:
			printf("退出游戏\n");
			break;
		default:*/
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}