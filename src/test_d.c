#include <stdlib.h>
//#include <math.h>
#include "datafile.h"
#include "force.h"
#include "velverlet.h"
#include "helpers.h"
#include "output.h"
#include "input.h"


/* main */
int main(int argc, char **argv)
{
    int nprint, i;
    char restfile[BLEN], trajfile[BLEN], ergfile[BLEN], line[BLEN];
    FILE *fp,*traj,*erg;
    mdsys_t sys;

    read_input( &sys, &nprint,  restfile,  trajfile, ergfile,line);

    int test=0;

    if (sys.natoms==1) printf("atoms number..OK \n");
    else printf("atoms number..FAIL\n");
    if (sys.mass==2) printf("atoms mass..OK\n");
    else printf("atoms mass..FAIL\n");
    if (sys.epsilon==3) printf("epsilon..OK\n");
    else printf("epsilon..FAIL\n");
    if (sys.sigma==4) printf("sigma..OK\n");
    else printf("sigma..FAIL\n");
    if (sys.rcut==5) printf("rcut..OK\n");
    else printf("rcut..FAIL\n");
    if (sys.box==6) printf("box..OK\n");
    else printf("box..FAIL\n");

    if(strcmp(restfile, "rest") == 0) )printf("rest file..OK\n");
    else printf("rest file..FAIL\n");
    if(strcmp(trajfile, "traj") == 0) )printf("trajectory file..OK\n");
    else printf("trajectory file..FAIL\n");
    if(strcmp(ergfile, "erg") == 0) )printf("trajectory file..OK\n");
    else printf("trajectory file..FAIL\n");
    if(strcmp(line, "line") == 0) )printf("line..OK\n");
    else printf("line..FAIL\n");

    if (sys.nsteps==7) printf("nsteps..OK\n");
    else printf("nsteps..FAIL\n");
    if (sys.dt==8) printf("time step value..OK\n");
    else printf("time step value..FAIL\n");
    if (nprint==9) printf("output frequency..OK\n");
    else printf("output frequency..FAIL\n");

  }
