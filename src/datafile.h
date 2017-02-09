



#ifndef DATAFILE__
#define DATAFILE__

extern const double kboltz;     /* boltzman constant in kcal/mol/K */
extern const double mvsq2e; /* m*v^2 in kcal/mol */
/* a few physical constants */

/* structure to hold the complete information
 * about the MD system */

 struct _mdsys {
     int natoms,nfi,nsteps;
     double dt, mass, epsilon, sigma, box, rcut;
     double ekin, epot, temp;
     double *rx, *ry, *rz;
     double *vx, *vy, *vz;
     double *fx, *fy, *fz;
 };
typedef struct _mdsys mdsys_t;

#endif
