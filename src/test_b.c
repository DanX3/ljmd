#include <stdlib.h>
//#include <math.h>
#include "datafile.h"
#include "force.h"
#include "velverlet.h"
#include "helpers.h"
#include "output.h"
#include "input.h"

int main(int argc, char **argv)
{
  int nprint, i,handle_error;

  mdsys_t sys;
  nprint=100;

  sys.natoms=2;

  sys.nsteps=1;
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




        sys.vx[0]=-1;
        sys.vy[0]=0;
        sys.vz[0]=0;

        sys.vx[1]=1;
        sys.vy[1]=0;
        sys.vz[1]=0;


  sys.fx[0]=-5;
  sys.fx[1]=5;
  ekin(&sys);
  /* main MD loop */
  for(sys.nfi=1; sys.nfi <= sys.nsteps; ++sys.nfi) {

      /* write output, if requested */
      if ((sys.nfi % nprint) == 0)
          output(&sys, erg, traj);

      /* propagate system and recompute energies */
      velverlet(&sys);
      ekin(&sys);
  }
  printf("Starting simulation with %d atoms for %d steps.\n",sys.natoms, sys.nsteps);
  printf("     NFI            TEMP            EKIN                 EPOT              ETOT\n");
  output(&sys, erg, traj);

/*
  printf("Test: single integration loop with %d atoms  at given v and f.\n",sys.natoms);
  printf("                Fx                 Fy                 Fz \n");
  for (i=0;i<sys.natoms;i++){
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


/* initialize forces and energies.

force(&sys);
//ekin(&sys);

//erg=fopen(ergfile,"w");
//traj=fopen(trajfile,"w");

printf("Test simulation with %d atoms at (-5,0,0) and (5,0,0) outside the cutoff.\n",sys.natoms);
printf("                Fx                Fy                 Fz \n");
for (i=0;i<sys.natoms;i++){
printf("Particle %d     %f            %f            %f \n",i,sys.fx[i],sys.fy[i],sys.fz[i]);
}
*/
  /* clean up: close files, free memory */
  printf("Simulation Done.\n");
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
