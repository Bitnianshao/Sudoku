#define _CRT_SECURE_NO_WARNINGS
#include<direct.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

void generate(int n);
void absolute(char* path);
void solve(int k1, int k2);
void output(int b[][10]);

int COUNT;
int map[10][10];
int quyu[4][4] = { { 0,0,0,0 },{ 0,1,2,3 },{ 0,4,5,6 },{ 0,7,8,9 } };
int hang[10][10], lie[10][10], grid[10][10], sum;
int p[10][2] = { { 0,0 },{ 1,1 },{ 1,4 },{ 1,7 },{ 4,1 },{ 4,4 },{ 4,7 },{ 7,1 },{ 7,4 },{ 7,7 } };
//p[i][0]和p[i][1]数组记录第i个区域的左上角的横纵坐标

void generate(int n) {
	//int shudu[9] = { 1,2,3,4,5,6,7,8,9 };
	//int shift[8] = { 3,6,1,4,7,2,5,8 };
	//int rows[8] = { 0 };
	int i, j, k;

	ofstream fout;
	fout.open("..\\BIN\\sudoku.txt");
	//fp = fopen("d:\\sudoku.txt", "w");//和ofstream功能一样


	int COUNT = 0;
	int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
	for (i = 0; i < 6 && n&&COUNT<n; i++)//COUNT判断只生成n个终端
	{
		if (i)
		{
			next_permutation(shift + 3, shift + 6);
			shift[6] = 2, shift[7] = 5, shift[8] = 8;
		}
		for (j = 0; j < 6 && n&&COUNT<n; j++)
		{
			if (j)
				next_permutation(shift + 6, shift + 9);
			int row[10] = { 1,2,3,4,5,6,7,8,9 };
			for (k = 0; k < 40320 && n&&COUNT<n; k++)
			{
				if (k)
					next_permutation(row + 1, row + 9);
				for (int r = 0; r < 9; r++)
				{
					for (int c = 0; c < 8; c++)
						//fprintf(fp, "%d ", row[(c + shift[r]) % 9]);
						fout << row[(c + shift[r]) % 9] << " ";
					//printf("%d ", row[(c + shift[r]) % 9]);
					fout << row[(8 + shift[r]) % 9] << endl;
					//printf("%d\n", row[(c + shift[r]) % 9]);
					//fprintf(fp, "%d\n", row[(8 + shift[r]) % 9]);
				}
				COUNT++;
				//fprintf(fp, "\n");
				fout << endl;
				//printf("\n");
			}
		}
	}
	fout.close();
	//fclose(fp);
}

void absolute(char* path) {
	//int ch;
	int i, j, k;

	//FILE *pfile;
	//pfile = fopen(path, "r");
	ifstream input_file;
	input_file.open(path);
	ofstream fout;
	fout.open("..\\BIN\\sudoku.txt");
	//fout.open("d:\\sudoku.txt");

	fout.close();

	/*i = 1; j = 1;
	while (EOF != (ch = fgetc(pfile))) {
	//input_file >> map[i][j];
	if (ch < 48 || ch>57) {
	break;
	}
	else {
	if (j < 9 && i <= 9) {//j+1,j<9
	map[i][j] = ch - 48;
	//printf("%d ", map[i][j]);
	k = map[i][j];
	//a[i][j] = map[i][j];
	if (k)
	{
	hang[i][k] = 1;    //第i行填入k了
	lie[j][k] = 1;       //第j列填入k了
	grid[quyu[(i - 1) / 3 + 1][(j - 1) / 3 + 1]][k] = 1;  //  (i , j)所在区域填入k了
	sum++;
	}
	j++;
	}
	else if (j == 9 && i < 9) {//j=1,j=9
	map[i][j] = ch - 48;
	//printf("%d ", map[i][j]);
	k = map[i][j];
	//a[i][j] = map[i][j];
	if (k)
	{
	hang[i][k] = 1;    //第i行填入k了
	lie[j][k] = 1;       //第j列填入k了
	grid[quyu[(i - 1) / 3 + 1][(j - 1) / 3 + 1]][k] = 1;  //  (i , j)所在区域填入k了
	sum++;
	}
	j = 1;
	i++;
	}
	else if (j == 9 && i == 9) {
	map[i][j] = ch - 48;
	//printf("%d ", map[i][j]);
	k = map[i][j];
	//a[i][j] = map[i][j];
	if (k)
	{
	hang[i][k] = 1;    //第i行填入k了
	lie[j][k] = 1;       //第j列填入k了
	grid[quyu[(i - 1) / 3 + 1][(j - 1) / 3 + 1]][k] = 1;  //  (i , j)所在区域填入k了
	sum++;
	}
	solve(1, 1);
	memset(map, 0, sizeof(map));
	memset(hang, 0, sizeof(hang));
	memset(lie, 0, sizeof(lie));
	memset(grid, 0, sizeof(grid));
	sum = 0;
	i = 1; j = 1;
	}
	}
	}
	//fclose(pfile);*/
	while (!input_file.eof()) {
		sum = 0;
		COUNT = 0;
		for (i = 1; i <= 9; i++)
			for (j = 1; j <= 9; j++) {
				input_file >> map[i][j];
				k = map[i][j];
				if (k)
				{
					hang[i][k] = 1;    //第i行填入k了
					lie[j][k] = 1;       //第j列填入k了
					grid[quyu[(i - 1) / 3 + 1][(j - 1) / 3 + 1]][k] = 1;  //  (i , j)所在区域填入k了
					sum++;
				}
			}
		solve(1, 1);
		//output(map);
		memset(map, 0, sizeof(map));
		memset(hang, 0, sizeof(hang));
		memset(lie, 0, sizeof(lie));
		memset(grid, 0, sizeof(grid));//防止影响下一次操作
	}
	input_file.close();
}

void solve(int k1, int k2)  //将数字k1填入区域k2
{
	if (COUNT == 1) {
		return;
	}
	int x, y, i, j;
	if (sum == 81) {
		/*for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
		a[i][j] = map[i][j];
		}
		}*/
		if (COUNT == 0) {
			output(map);
			COUNT = 1;//只生成一个可行解
		}
		return;
	}  //数独全填好了就输出
	if (grid[k2][k1])   //区域k2中已有数字k1了
	{
		if (k2<9)
			solve(k1, k2 + 1); //填下一个区域
		else
			solve(k1 + 1, 1); //填下一个数字
	}

	x = p[k2][0];
	y = p[k2][1];

	for (i = x; i <= x + 2; i++)
		for (j = y; j <= y + 2; j++)
			if (map[i][j] == 0 && hang[i][k1] == 0 && lie[j][k1] == 0) //第(i,j)格为空，且可填入k1
			{
				map[i][j] = k1;
				sum++;
				hang[i][k1] = lie[j][k1] = 1;

				if (k2<9)
					solve(k1, k2 + 1); //填下一个区域
				else
					solve(k1 + 1, 1); //填下一个数字

				map[i][j] = 0;
				sum--;
				hang[i][k1] = lie[j][k1] = 0;
			}
}

void output(int b[][10]) {
	int a;
	ofstream fout;
	fout.open("..\\BIN\\sudoku.txt", ios::app);
	//fout.open("d:\\sudoku.txt", ios::app);

	//FILE *fp;
	//fp = fopen("../BIN/suduku.txt", "a+");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 8; j++) {
			a = map[i][j];
			fout << map[i][j] << " ";
			//fprintf(fp, "%d ", a);
			//printf("%d ", map[i][j]);
		}
		a = map[i][9];
		fout << map[i][9] << endl;
		//fprintf(fp, "%d\n", a);
		//printf("%d\n", map[i][9]);
	}
	fout << endl;
	//fout.close();
	//fprintf(fp, "\n");
	//printf("\n");
	//fclose(fp);
}

int main(int argc, char* argv[])//参考输入判断
{
	int n;
	char s[5], path[200];
	if (argc>2)
	{
		strcpy(s, argv[1]);
		if (s[1] == 'c')
		{//检测命令行参数-c，若为从，生成终端
			n = atoi(argv[2]);//生成终局数
			if (n)
			{
				generate(n);
			}
			else
				cout << "wrong input" << endl;
		}
		else if (s[1] == 's')
		{//检测命令行参数-s,若为s，解数独
			strcpy(path, argv[2]);
			absolute(path);
			//solve(1, 1);
			//output(a);
		}
		else
			cout << "wrong input" << endl;
	}
	else

		cout << "wrong input" << endl;
	//system("pause")
	return 0;
}