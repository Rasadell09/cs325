/*
Team members Name: Yunfan Li, Haichao Zhang, Jingyuan Xu
Course: CS325-001
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define n 10000

struct ele {
	int pos;
	int val;
}suml[n], sumr[n];

int res = ~(1<<31);
int poi = 0, poj = 0;

int cmp(const void *a, const void *b)
{
	return (*(struct ele *)a).val > (*(struct ele *)b).val ? 1 : -1;
}

void bet(struct ele *sl, int l, struct ele *sr, int r)
{
	qsort(sl, l, sizeof(sl[0]), cmp);
	qsort(sr, r, sizeof(sr[0]), cmp);
	
	for (int i = 0; i < l; i++) {
		int min = ~(1<<31);
		
		for (int j = 0; j < r; j++) {
			if (abs(sl[i].val+sr[j].val) < min) {
   				min = abs(sl[i].val + sr[j].val);

				if (res > min) {
					poi = sl[i].pos;
					poj = sr[j].pos;
					res = min;
				}
			}
			else
				break;
		}
	}
}

void func(int *a, int s, int e)
{
	if (s == e) {
		if (res > abs(a[s])) {
			poi = s;
			poj = e;
			res = abs(a[s]);
		}
		return ;
	}
	else {
		int m = (e-s+1) / 2;
		int mod = (e-s+1) % 2;
		int kl = 0, kr = 0;
		int inl = 0, inr = 0;

		for (int i = 0; i < n; i++) {
			sumr[i].val = 0;
			sumr[i].pos = 0;
			suml[i].val = 0;
			suml[i].pos = 0;
		}
		
		func(a, s, s+m-1);
		if (mod) {
			func(a, e-m, e);
			for (int i = e-m, kr = 0; i <= e; i++, kr++) {
				sumr[kr].pos = i;
				sumr[kr].val = sumr[kr-1].val + a[i];
				inr++;
			}
		}
		else {
			func(a, e-m+1, e);
			for (int i = e-m+1, kr = 0; i <= e; i++, kr++) {
				sumr[kr].pos = i;
				sumr[kr].val = sumr[kr-1].val + a[i];
				inr++;
			}
		}
		for (int i = s+m-1, kl = m-1; i >= s; i--, kl--) {
			suml[kl].pos = i;
			suml[kl].val = suml[kl+1].val + a[i];
			inl++;
		}

		bet(suml, inl, sumr, inr);
	}
}

int len(int *a)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			break;
		else
			cnt++;
	}
	return cnt;
}

int main(int argc, char **argv)
{
	int a[n] = {31, -41, 59, 26, -53, 58, -6, 97, -93, -23, 0};
	int sum = len(a);
	
	func(a, 0, sum-1);

	printf("len=%d\n", sum);
	printf("%d %d %d\n", res, poi, poj);
	
	return 0;
}
