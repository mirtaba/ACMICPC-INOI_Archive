/*
ID: ghoolha1
TASK: checker
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 16

int n;
int nsol, nprinted;
char row[MAXN];
FILE *fout;

void
solution() {
    int i;
    for(i=0; i<n; i++) {
	if(i != 0) fprintf(fout, " ");
	fprintf(fout, "%d", row[i]+1);
    }
    fprintf(fout, "\n");
}

/* Keep track of whether there is a checker on each column, and diagonal. */
char col[MAXN];		/* (i, j) -> j */
char updiag[2*MAXN];	/* (i, j) -> i+j */
char downdiag[2*MAXN];	/* (i, j) -> i-j + N */

/*
 * Calculate number of ways to place checkers
 * on each row of the board starting at row i and going to row n.
 */
void
nway(i, lim) {
    int j;

    if(i == n) {
	nsol++;
	if (n > 6 && row[0] < n/2) nsol++;
	if (nprinted++ < 3) solution();
	return;
    }

    for(j=0; j<lim; j++){
	if(!col[j] && !updiag[i+j] && !downdiag[i-j+MAXN]){
	    row[i] = j;

	    col[j]++;
	    updiag[i+j]++;
	    downdiag[i-j+MAXN]++;

	    nway(i+1,n);

	    col[j]--;
	    updiag[i+j]--;
	    downdiag[i-j+MAXN]--;
	}
    }
}

main(void) {
    FILE *fin = fopen("checker.in", "r");
    fout = fopen("checker.out", "w");
    fscanf(fin, "%d", &n);
    nway(0, n>6?(n+1)/2:n);
    fprintf(fout, "%d\n", nsol);
    exit (0);
}
