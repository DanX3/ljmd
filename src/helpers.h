#ifndef HELPERS_H
#define HELPERS_H

#include "datafile.h"
#include <string.h>
#include <math.h>
#include <ctype.h>

/* generic file- or pathname buffer length */
#define BLEN 200

/* helper function: read a line and then return
   the first string with whitespace stripped off */
static int get_a_line(FILE *fp, char *buf);


/* helper function: zero out an array */
static void azzero(double *d, const int n);

/* helper function: apply minimum image convention */
static double pbc(double x, const double boxby2);


/* compute kinetic energy */
static void ekin(mdsys_t *sys);


#endif
