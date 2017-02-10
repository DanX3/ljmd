#include "velverlet.h"

/* velocity verlet */
void velverlet(mdsys_t *sys)
{
    int i;

    /* first part: propagate velocities by half and positions by full step */
    double constPart = 0.5 * sys->dt / mvsq2e / sys->mass;
    for (i=0; i<sys->natoms; ++i) {
        sys->vx[i] += sys->fx[i] * constPart;
        sys->vy[i] += sys->fy[i] * constPart;
        sys->vz[i] += sys->fz[i] * constPart;
        sys->rx[i] += sys->dt*sys->vx[i];
        sys->ry[i] += sys->dt*sys->vy[i];
        sys->rz[i] += sys->dt*sys->vz[i];
    }

    /* compute forces and potential energy */
    force(sys);

    /* second part: propagate velocities by another half step */
    for (i=0; i<sys->natoms; ++i) {
        sys->vx[i] += sys->fx[i] * constPart;
        sys->vy[i] += sys->fy[i] * constPart;
        sys->vz[i] += sys->fz[i] * constPart;
    }
}
