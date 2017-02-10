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

    sys.natoms=3;

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

    //setting particles position
    //I don't care about position
    for (int i=0; i<sys.natoms; i++) {
        sys.rx[i]=0;
        sys.ry[i]=0;
        sys.rz[i]=0;
    }

    //setting particles speed
    sys.vx[0]=1;
    sys.vy[0]=0;
    sys.vz[0]=0;

    sys.vx[1]=0;
    sys.vy[1]=2;
    sys.vz[1]=0;

    sys.vx[2]=0;
    sys.vy[2]=0;
    sys.vz[2]=3;

    azzero(sys.fx, sys.natoms);
    azzero(sys.fy, sys.natoms);
    azzero(sys.fz, sys.natoms);


    /* initialize forces and energies.*/
    /*force(&sys);*/
    ekin(&sys);

    double correctResult = 668346.080349779;
    printf("Correct result = %f\n", correctResult);
    printf("Ekin result = %f\n", sys.ekin);
    double absolute = abs(sys.ekin - correctResult);
    printf("Absolute error = %f\n", absolute);
    printf("Relative error = %6.3f%\n", absolute / correctResult);
    if (absolute / correctResult < 1.0f) {
        printf("\e[32m - Test 3 OK - \e[30m\n");
    } else {
        printf("\e[31m - Test 3 Failed - \e[30m\n");
    }
    //erg=fopen(ergfile,"w");
    //traj=fopen(trajfile,"w");

    /* clean up: close files, free memory */
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
