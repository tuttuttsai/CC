#include <stdio.h>
#define maxn 10000

struct Command{
	char c[5];
	int a,x[20];
	int r1,c1,r2,c2;
}cmd[maxn];

int r,c,n;
int kase = 0;

int simulate(int* r0,int* c0){
	for(int i = 0;i < n;i++){
		if(cmd[i].c[0] == 'E'){
			if(*r0 == cmd[i].r1 && *c0 == cmd[i].c1){
				*r0 = cmd[i].r2;
				*c0 = cmd[i].c2;
			}
			else if(*r0 == cmd[i].r2 && *c0 == cmd[i].c2){
				*r0 = cmd[i].r1;
				*c0 = cmd[i].c1;
			}
		}
		else{
			int ar = 0,ac = 0;
			for(int j = 0;j < cmd[i].a;j++){
				if(cmd[i].c[0] == 'I'){
					if(cmd[i].c[1] == 'R' && *r0 >= cmd[i].x[j]) ar++;
					if(cmd[i].c[1] == 'C' && *c0 >= cmd[i].x[j]) ac++;
				}
				else{
					if(cmd[i].c[1] == 'R' && *r0 == cmd[i].x[j]) return 0;
					if(cmd[i].c[1] == 'C' && *c0 == cmd[i].x[j]) return 0;
					if(cmd[i].c[1] == 'R' && *r0 > cmd[i].x[j]) ar--;
					if(cmd[i].c[1] == 'C' && *c0 > cmd[i].x[j]) ac--;
				}
			}
			*r0 += ar;
			*c0 += ac;
		}
	}
	return 1;
}

int main(){
	while(scanf("%d%d",&r,&c) == 2 && r){
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%s",cmd[i].c);
			if(cmd[i].c[0] == 'E'){
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			}
			else{
				scanf("%d",&cmd[i].a);
				for(int j = 0;j < cmd[i].a;j++) scanf("%d",&cmd[i].x[j]);
			}
		}
		if(kase > 0) printf("\n");
		printf("Spreadsheet #%d\n",++kase);
		int q,r0,c0;
		scanf("%d",&q);
		for(int i = 0;i < q;i++){
			scanf("%d%d",&r0,&c0);
			printf("Cell data in (%d,%d) ",r0,c0);
			if(!simulate(&r0,&c0)) printf("GONE\n");
			else printf("moved to (%d,%d)\n",r0,c0);
		}
	}
	return 0;
}