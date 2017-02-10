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
    int nprint;
    char restfile[BLEN], trajfile[BLEN], ergfile[BLEN], line[BLEN];

    mdsys_t sys;

    read_input( &sys, &nprint,  restfile,  trajfile, ergfile,line);



    if (sys.natoms==1) printf("\e[32matoms number..OK \e[30m\n");
    else printf("\e[31matoms number..FAIL\e[30m\n");
    if (sys.mass==2) printf("\e[32matoms mass..OK\e[30m\n");
    else printf("\e[31matoms mass..FAIL\e[30m\n");
    if (sys.epsilon==3) printf("\e[32mepsilon..OK\e[30m\n");
    else printf("\e[31mepsilon..FAIL\e[30m\n");
    if (sys.sigma==4) printf("\e[32msigma..OK\e[30m\n");
    else printf("\e[31msigma..FAIL\e[30m\n");
    if (sys.rcut==5) printf("\e[32mrcut..OK\e[30m\n");
    else printf("\e[31mrcut..FAIL\e[30m\n");
    if (sys.box==6) printf("\e[32mbox..OK\e[30m\n");
    else printf("\e[31mbox..FAIL\e[30m\n");

    if(strcmp(restfile, "rest") == 0) printf("\e[32mrest file..OK\e[30m\n");
    else printf("\e[31mrest file..FAIL\e[30m\n");
    if(strcmp(trajfile, "traj") == 0) printf("\e[32mtrajectory file..OK\e[30m\n");
    else printf("\e[31mtrajectory file..FAIL\e[30m\n");
    if(strcmp(ergfile, "erg") == 0) printf("\e[32menergy file..OK\e[30m\n");
    else printf("\e[31menergy file..FAIL\e[30m\n");


    if (sys.nsteps==7) printf("\e[32mnsteps..OK\e[30m\n");
    else printf("\e[31mnsteps..FAIL\e[30m\n");
    if (sys.dt==8) printf("\e[32mtime step value..OK\e[30m\n");
    else printf("\e[31mtime step value..FAIL\e[30m\n");
    if (nprint==9) printf("\e[32moutput frequency..OK\e[30m\n");
    else printf("\e[31moutput frequency..FAIL\e[30m\n");

  }
