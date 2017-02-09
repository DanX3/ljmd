#include "input.h"

/* read input file */
int read_input(mdsys_t *sys,int *nprint, char *restfile, char *trajfile, char *ergfile, char *line){
  if(get_a_line(stdin,line)) return 1;
  sys->natoms=atoi(line);
  if(get_a_line(stdin,line)) return 1;
  sys->mass=atof(line);
  if(get_a_line(stdin,line)) return 1;
  sys->epsilon=atof(line);
  if(get_a_line(stdin,line)) return 1;
  sys->sigma=atof(line);
  if(get_a_line(stdin,line)) return 1;
  sys->rcut=atof(line);
  if(get_a_line(stdin,line)) return 1;
  sys->box=atof(line);
  if(get_a_line(stdin,restfile)) return 1;
  if(get_a_line(stdin,trajfile)) return 1;
  if(get_a_line(stdin,ergfile)) return 1;
  if(get_a_line(stdin,line)) return 1;
  sys->nsteps=atoi(line);
  if(get_a_line(stdin,line)) return 1;
  sys->dt=atof(line);
  if(get_a_line(stdin,line)) return 1;
  *nprint=atoi(line);
  return 0;
}
