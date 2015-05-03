/*
 *Team name: Yunfan Li, Haichao Zhang, Jingyuan Xu
 *Course: CS325-001
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
		//a[y] = rand() % 1000;
		//start = clock();
		int sum = 0;
		int b[110];
		for (int i = 0; i < cnt; i++) {
			b[i] = a[i];
			for (int j = i+1; j < cnt; j++) {
				b[j] = b[j-1] + a[j];
			}
			for (int k = i; k < cnt; k++)
				if (res < b[k])
					res = b[k];
		}
		//end = clock();
		//printf("len = %d, %d's time = %d\n", len, x, end-start);
	   	printf("%d\n", res);
    }
	return 0;
}
