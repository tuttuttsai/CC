#include <stdio.h>
#include <string.h>

int board[12][11];//1~10,1~9

void simulate() {
	for( int i = 1; i < 11; i++ ) {
		for( int j = 1; j < 10; j++ ) {
			if( board[i][j] == 'G' ) {
				int k = i;
				while( board[--k][j] <= 1 && k > 0 ) board[k][j] = 1;
			}
			else if( board[i][j] == 'R' ) {
				int k = i;
				while( board[--k][j] <= 1 && k > 0 ) board[k][j] = 1;
				k = i;
				while( board[++k][j] <= 1 && k < 11 ) board[k][j] = 1;
				k = j;
				while( board[i][--k] <= 1 && k > 0 ) board[i][k] = 1;
				k = j;
				while( board[i][++k] <= 1 && k < 10 ) board[i][k] = 1;
			}
			else if( board[i][j] == 'H' ) {
				if( board[i+1][j] <= 1 && board[i+2][j+1] <= 1 && board[i+2][j-1] <= 1 ) { board[i+2][j+1] = 1; board[i+2][j-1] = 1; }
				if( board[i-1][j] <= 1 && board[i-2][j+1] <= 1 && board[i-2][j-1] <= 1 ) { board[i-2][j+1] = 1; board[i-2][j-1] = 1; }
				if( board[i][j+1] <= 1 && board[i+1][j+2] <= 1 && board[i-1][j+2] <= 1 ) { board[i+1][j+2] = 1; board[i-1][j+2] = 1; }
				if( board[i][j-1] <= 1 && board[i+1][j-2] <= 1 && board[i-1][j-2] <= 1 ) { board[i+1][j-2] = 1; board[i-1][j-2] = 1; }
			}
			else if( board[i][j] == 'C' ) {
				int k = i;
				while( board[--k][j] <= 1 && k > 0);
				while( board[--k][j] <= 1 && k > 0 ) board[k][j] = 1;
				k = i;
				while( board[++k][j] <= 1 && k < 11 );
				while( board[++k][j] <= 1 && k < 11 ) board[k][j] = 1;
				k = j;
				while( board[i][--k] <= 1 && k > 0 );
				while( board[i][--k] <= 1 && k > 0 ) board[i][k] = 1;
				k = j;
				while( board[i][++k] <= 1 && k < 10 );
				while( board[i][++k] <= 1 && k < 10 ) board[i][k] = 1;
			}
		}
	}
}
/*
void pt(){
	for( int i = 0; i < 12; i++ ) {
		for( int j = 0; j < 11; j++ ) {
			printf("%2d ",board[i][j]);
		}
		printf("\n");
	}
}
*/
int fg(int r,int c){
	while(board[++r][c] <= 1 && r < 11);
	if(board[r][c] == 'G') return 1;
	else return 0;
}

int gm(int r,int c){
	if( r < 1 || r > 3 || c < 4 || c > 6 ) return 0;
	if( board[r][c] > 1 ) { board[r][c] = 0; simulate(); } 
	if( board[r][c] == 1) return 0;
	return 1;
}

int main(){
	int n,r0,c0;
	while(scanf("%d%d%d",&n,&r0,&c0) == 3 && n){
		memset(board,0,sizeof(board));
		char ch;
		int r,c;
		for( int i = 0; i < n; i++ ) {
			scanf(" %c%d%d",&ch,&r,&c);
			board[r][c] = ch;
		}
		simulate();
		//pt();
		if ( fg(r0,c0) || gm(r0-1,c0) || gm(r0+1,c0) || gm(r0,c0-1) || gm(r0,c0+1)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}