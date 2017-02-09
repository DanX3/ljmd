#ifndef HELPERS_H
#define HELPERS_H

#include "datafile.h"
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>

/* generic file- or pathname buffer length */
#define BLEN 200

/* helper function: read a line and then return
   the first string with whitespace stripped off */
int get_a_line(FILE *fp, char *buf);


/* helper function: zero out an array */
void azzero(double *d, const int n);

/* helper function: apply minimum image convention */
double pbc(double x, const double boxby2);


/* compute kinetic energy */
void ekin(mdsys_t *sys);


#endif
