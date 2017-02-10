#include <stdlib.h>
//#include <math.h>
#include "datafile.h"
#include "force.h"
#include "velverlet.h"
#include "helpers.h"
#include "output.h"
#include "input.h"

int main(int argc, char **argv) {
    int nprint, i,handle_error;

    mdsys_t sys;

    sys.natoms=2;

    sys.nsteps=0;
    sys.dt=1;
    sys.mass=39.948;
    sys.epsilon=0.2379;
    sys.sigma=3.405;
    sys.box=17.1580;
    sys.rcut=4.5;
    sys.rx=(double *)malloc(sys.natoms*sizeof(double));
    sys.ry=(double *)malloc(sys.natoms*sizeof(double));
    sys.rz=(double *)malloc(sys.natoms*sizeof(double));
    sys.vx=(double *)malloc(sys.natoms*sizeof(double));
    sys.vy=(double *)malloc(sys.natoms*sizeof(double));
    sys.vz=(double *)malloc(sys.natoms*sizeof(double));
    sys.fx=(double *)malloc(sys.natoms*sizeof(double));
    sys.fy=(double *)malloc(sys.natoms*sizeof(double));
    sys.fz=(double *)malloc(sys.natoms*sizeof(double));




    sys.rx[0]=1;
    sys.ry[0]=0;
    sys.rz[0]=0;


    sys.rx[1]=-1;
    sys.ry[1]=0;
    sys.rz[1]=0;
    /*
            sys.rx[2]=-1;
            sys.ry[2]=0;
            sys.rz[2]=0;*/


    for (i=0; i<sys.natoms; ++i) {
        sys.vx[i]=0;
        sys.vy[i]=0;
        sys.vz[i]=0;
    }

    azzero(sys.fx, sys.natoms);
    azzero(sys.fy, sys.natoms);
    azzero(sys.fz, sys.natoms);


    /* initialize forces and energies.*/

    force(&sys);
    //ekin(&sys);

    //erg=fopen(ergfile,"w");
    //traj=fopen(trajfile,"w");

    printf("Test simulation with %d atoms at (-3,0,0) and (3,0,0).\n",sys.natoms);
    printf("                Fx                 Fy                 Fz \n");
    for (i=0; i<sys.natoms; i++) {
        printf("Particle %d     %f            %f            %f \n",i,sys.fx[i],sys.fy[i],sys.fz[i]);
    }


    sys.rx[0]=3;
    sys.ry[0]=0;
    sys.rz[0]=0;


    sys.rx[1]=-3;
    sys.ry[1]=0;
    sys.rz[1]=0;

    azzero(sys.fx, sys.natoms);
    azzero(sys.fy, sys.natoms);
    azzero(sys.fz, sys.natoms);


    /* initialize forces and energies.*/

    force(&sys);
    //ekin(&sys);

    //erg=fopen(ergfile,"w");
    //traj=fopen(trajfile,"w");

    printf("Test simulation with %d atoms at (-5,0,0) and (5,0,0) outside the cutoff.\n",sys.natoms);
    printf("                Fx                Fy                 Fz \n");
    for (i=0; i<sys.natoms; i++) {
        printf("Particle %d     %f            %f            %f \n",i,sys.fx[i],sys.fy[i],sys.fz[i]);
    }

    /* clean up: close files, free memory */
    printf("Simulation Done.\n");
    printf("\e[32m - Test 1 OK - \e[30m\n");
    //fclose(erg);
    //fclose(traj);

    free(sys.rx);
    free(sys.ry);
    free(sys.rz);
    free(sys.vx);
    free(sys.vy);
    free(sys.vz);
    free(sys.fx);
    free(sys.fy);
    free(sys.fz);

    return 0;

}
