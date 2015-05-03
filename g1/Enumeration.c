/*
 *Team name: Yunfan Li, Haichao Zhang, Jingyuan Xu
 *Course: CS325-001
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define len 110

int main(int argc, char** argv)
{
  	freopen("in.txt", "r", stdin);
   	freopen("out.txt", "w", stdout);

   	char s;
	int a[110], res = 0;//, start, end;
   	while ((scanf("%c", &s) == 1) && (s == '[')) {

		int cnt = 0;
		res = 0;
		while (scanf("%d", &a[cnt]) == 1) {
			cnt++;
			scanf("%c", &s);
		}
		//for (int x = 0; x < 10; x++) {
		//	for (int y = 1; y <= len; y++) {
		//	a[y] = rand() % 1000;
		//}
		//	start = clock(); 
		int sum = 0;
		for (int i = 0; i < cnt; i++) {
			for (int j = i+1; j < cnt; j++) {
				for(int k = i; k <= j; k++)
					sum += a[k];
				if (sum > res)
					res = sum;
				sum = 0;
			}
		}
		//end = clock();
		//	printf("len = %d x's time = %d\n", len, end-start);
	   	printf("%d\n", res);
	}
	return 0;
}
