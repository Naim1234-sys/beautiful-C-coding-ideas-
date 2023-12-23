#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double surface_tria(int a,int b,int c){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
       
int compare(const void*a,const void*b){
    triangle* tr1=(triangle*)a;
    triangle* tr2=(triangle*)b;
    double s1=surface_tria(tr1->a,tr1->b,tr1->c);
    double s2=surface_tria(tr2->a,tr2->b,tr2->c);
    return (s1>s2)-(s2>s1);
}
void sort_by_area(triangle*tr,int n){
    qsort(tr,n,sizeof(triangle),compare);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
