//TEAM: Yunfan Li, Haichao Zhang, Jingyuan Xu
//Course: CS325-001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 600

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char **argv)
{
	freopen("in.txt", "r", stdin);

	int N, M, T;

	while (scanf("%d %d %d", &N, &M, &T) == 3) {
		
		int key[MAX] = {0};
		int ball[MAX] = {0};
		int box[MAX] = {0};
		int d[MAX][2] = {0};
		
		for (int i = 1; i <= M; i++)
			scanf("%d", &key[i]);

		for (int i = 1; i <= T; i++) {
			int tmp = 0;
			scanf("%d", &tmp);
			ball[i] = tmp;
			box[tmp] = 1;
		}
		
		qsort(key, M+1, sizeof(key[0]), cmp);
		qsort(ball, T+1, sizeof(ball[0]), cmp);

		if (ball[1] <= key[1]) {
			d[1][1] = key[1] - ball[1] + 1;
			d[1][0] = 100000;
		}
		else {
			d[1][1] = 1;
			d[1][0] = 0;
		}
		
		for (int i = 2; i <= M; i++) {
			int ballPos = 0;
			
			for (int j = key[i]; j > key[i-1]; j--)
				if (box[j] == 1) {
					ballPos = j;
					break;
				}

			if (ballPos == 0) {
				d[i][0] = d[i-1][0] < d[i-1][1] ? d[i-1][0] : d[i-1][1];
				d[i][1] = d[i-1][0] < d[i-1][1] ? (d[i-1][0]+1) : (d[i-1][1]+1);
			}
			else {
				int sum_lnot = 100000, sum_lopen = 100000;
				
				d[i][0] = (d[i-1][0]+ballPos-key[i-1]+1) < (d[i-1][1]+ballPos-key[i-1]) ? (d[i-1][0]+ballPos-key[i-1]+1): (d[i-1][1]+ballPos-key[i-1]);
								
				for (int j = key[i-1]+1; j <= key[i]; j++) {
					int k = 0, lopen = 0, r = 0, lnot = 0;
					
					for (k = j-1; k > key[i-1]; k--)
						if (box[k] == 1)
							break;
					if (k == key[i-1]) {
						lnot = 0;
						lopen = 0;
					}
					else {
						lnot = k - key[i-1] + 1;
						lopen = k - key[i-1];
					}
										
					for (k = j; k <= key[i]; k++)
						if (box[k] == 1)
							break;
					if (k == (key[i]+1))
						r = 1;
					else
						r = key[i] - k + 1;

					sum_lnot = sum_lnot < (r+lnot) ? sum_lnot : (r+lnot);
					sum_lopen = sum_lopen < (r+lopen) ? sum_lopen : (r+lopen);
				}//for key[i-1]+1 -> key[i]
				d[i][1] = (d[i-1][0]+sum_lnot) < (d[i-1][1]+sum_lopen) ? (d[i-1][0]+sum_lnot) : (d[i-1][1]+sum_lopen);
			}//else have balls			
		}//for key 2->M

		int res = 0;
		if (ball[T] > key[M]) 
			res = (d[M][0]+ball[T]-key[M]+1) < (d[M][1]+ball[T]-key[M]) ? (d[M][0]+ball[T]-key[M]+1) : (d[M][1]+ball[T]-key[M]);
		else
			res = d[M][0] < d[M][1] ? d[M][0] : d[M][1];

		printf("%d\n", res);
		
	}//while input loop
	return 0;
}
