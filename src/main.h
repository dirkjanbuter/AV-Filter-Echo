#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

extern int filtercreate(int fps);
extern int filterdestroy();
extern int filterstep(unsigned char *buffer, int w, int h, unsigned int color, char *text, int64_t framecount);
extern int filteraudio(float *frame, int64_t framecount, float elapsed);
extern int filtermic(float *frame, int64_t framecount, float elapsed);
extern int filterkey(int64_t code);
