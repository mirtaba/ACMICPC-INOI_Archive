/*
ID: ghoolha1
PROG: holstein
LANG: C
*/

#include <stdio.h>
#include <assert.h>
#define MAXV 25
#define MAXF 15

int req[MAXV]; /* the vitamin requirements */
int numv; /* number of vitamins */

int feeds[MAXF][MAXV]; /* the vitamin within each feed */
int numf; /* number of feeds */

int best; /* the minimum number of feeds to use found thus far */
int bestf[MAXF]; /* the set */

int curf[MAXF]; /* the current set of feeds being considered */

void find_feed(int fcnt, int fid)
 { /* fcnt is the number of feeds in the current mixture,
      fid is the identifier of the first feed to try adding (last feed + 1) */
  int lv;

  /* check if the requirement has been met */
  for (lv = 0; lv < numv; lv++)
    if (req[lv] > 0) break;
  if (lv >= numv)
   {
       /* all the requirements are met */
        /*
        we know this is better, since we wouldn't have checked it otherwise
        (see below)
        */
    best = fcnt;
    for (lv = 0; lv < best; lv++)
      bestf[lv] = curf[lv];
    return;
   }
  while (fid < numf && fcnt+1 < best)
   { /* try adding each feed to the mixture */
     /* the fcnt+1 < best ensures that we stop if there's no hope
	in finding a better solution than one found already */
    /* add the vitamins from this feed */
    for (lv = 0; lv < numv; lv++)
      req[lv] -= feeds[fid][lv];
    curf[fcnt] = fid; /* put it in the list */
    find_feed(fcnt+1, fid+1);
    /* undo adding the vitamins */
    for (lv = 0; lv < numv; lv++)
      req[lv] += feeds[fid][lv];
    /* next feed */
    fid++;
   }
 }

int main(void)
 {
  FILE *fin, *fout;
  int lv, lv2;

  fin = fopen("holstein.in", "r");
  fout = fopen("holstein.out", "w");
  assert(fin);
  assert(fout);

  fscanf (fin, "%d", &numv);
  for (lv = 0; lv < numv; lv++)
    fscanf (fin, "%d", &req[lv]);
  fscanf (fin, "%d", &numf);
  for (lv = 0; lv < numf; lv++)
    for (lv2 = 0; lv2 < numv; lv2++)
      fscanf (fin, "%d", &feeds[lv][lv2]);

  best = numf+1;
  find_feed(0, 0);

  fprintf (fout, "%i", best);
  for (lv = 0; lv < best; lv++)
    fprintf (fout, " %i", bestf[lv]+1);
  fprintf (fout, "\n");
  return 0;
 }
