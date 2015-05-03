//TEAM: Yunfan Li, Haichao Zhang, Jingyuan Xu
//Course: CS325-001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 600

int index = 1, N = 0, M = 0, T = 0;
int key[MAX] = {0};
int ball[MAX] = {0};
int box[MAX] = {0};
int newKey[MAX] = {0};

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int recursive(int state, int level)
{
	int res = 0;
	if (level != (M+1)) {
		if (state == 1) {
			newKey[index++] = key[level];
			res = recursive(level+1, 1);
			index--;
			res = res < recursive(level+1, 0) ? res : recursive(level+1, 0);
			index--;
			return res;
		}
		else {
			res = recursive(level+1, 1);
			index--;
			res = res < recursive(level+1, 0) ? res : recursive(level+1, 0);
			index--;
			return res;
		}
	}
	else {
		int front = newKey[1] - ball[1] + 1;
		int back = ball[T] - newKey[index-1];

		for (int i = 1; i <= (index-1); i++) {
			int k = 0;
			int openright[MAX], openleft[MAX];
			for (int j = newKey[i-1]+1; j <= newKey[i]; j++) {
				if (box[i] == 1) {
					openright[k] = j - newKey[i-1];
					openleft[k] = newKey[i] - j + 1;
					k++;
				}
			}
			int tmpMin = 100000;
			for (int j = 1; j <= k-2; j++) {
				if (tmpMin > (openright[k]+openleft[k]))
					tmpMin = openright[k]+openleft[k];
			}
			min += tmpMin;
		}
		res = front+min+back;
		return res;
	}
}

int main(int argc, char **argv)
{
	freopen("in.txt", "r", stdin);

	while (scanf("%d %d %d", &N, &M, &T) == 3) {
		
		for (int i = 1; i <= M; i++)
			scanf("%d", &key[i]);

		for (int i = 1; i <= T; i++) {
			int tmpPos = 0;
			scanf("%d", &tmpPos);
			ball[i] = tmpPos;
			box[tmpPos] = 1;
		}

		qsort(key, M+1, sizeof(key[0]), cmp);
		qsort(ball, T+1, sizeof(ball[0]), cmp);

		int d = recursive(1, 1);
		d = d < recursive(0, 1) ? d : recursive(0, 1);
		printf("%d\n", d);
	}
}
