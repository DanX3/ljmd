#include "force.h"



/* compute forces */
void force(mdsys_t *sys) {

    double rsq, rcsq, ffac;
    double rx,ry,rz;
    int i,j;
    double c12, c6;

    /* zero energy and forces */
    sys->epot=0.0;
    azzero(sys->fx,sys->natoms);
    azzero(sys->fy,sys->natoms);
    azzero(sys->fz,sys->natoms);

    c12 = 4.0 * sys->epsilon * pow(sys->sigma, 12);
    c6  = 4.0 * sys->epsilon * pow(sys->sigma, 6 );
    rcsq = sys->rcut * sys->rcut;
    for(i=0; i < (sys->natoms)-1; ++i) {
        for(j=i+1; j < (sys->natoms); ++j) {
            /*printf("[%d, %d]\n", i, j);*/
            /* get distance between particle i and j */
            rx=pbc(sys->rx[i] - sys->rx[j], 0.5*sys->box);
            ry=pbc(sys->ry[i] - sys->ry[j], 0.5*sys->box);
            rz=pbc(sys->rz[i] - sys->rz[j], 0.5*sys->box);
            rsq = rx*rx + ry*ry + rz*rz;

            /* compute force and energy if within cutoff */
            if (rsq < rcsq) {
                double rinv =  1.0/rsq;
                double r6 = rinv * rinv * rinv;
                ffac = (12.0*c12*r6 - 6.0*c6) * r6 * rinv;
                sys->epot += r6 * (c12 * r6 -c6);

                sys->fx[i] += rx*ffac; sys->fx[j] -= rx*ffac;
                sys->fy[i] += ry*ffac; sys->fy[j] -= ry*ffac;
                sys->fz[i] += rz*ffac; sys->fz[j] -= rz*ffac;
            }
        }
    }
}
