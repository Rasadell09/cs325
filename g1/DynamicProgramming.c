/*
 *Team name: Yunfan Li, Haichao Zhang, Jingyuan Xu
 *Course: CS325-001
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a, b) (a > b ? a : b)
//#define len 9010

int main(int argc, char** argv)
{
   	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char s;
	int a[len], res, start, end;
	while ((scanf("%c", &s) == 1) && (s == '[')) {

		int cnt = 0;
		res = 0;
		while (scanf("%d", &a[cnt]) == 1) {
			cnt++;
			scanf("%c", &s);
		}
		//for (int x = 0; x < 10; x++) {
		//for (int y = 1; y <= len; y++)
		//	a[y] = rand() % 1000;
		//start = clock();
		int b[110] = {-100000};
		int e[110] = {-100000};
		b[0] = e[0] = a[0];
		for (int i = 0; i < cnt; i++) {
			e[i] = max(e[i-1]+a[i], a[i]);
			b[i] = max(e[i], b[i-1]);
		}
		//end = clock();
		//printf("len = %d, %d's time = %d\n", len, x, end-start);
	   	printf("%d\n", b[cnt-1]);
    }
	return 0;
}
