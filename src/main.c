#include "main.h"

#define TRUE 1
#define FALSE 0;
#define AUDIOMEMEORYLEN 1048576

static int _talk = 0;
static int _lasttalk = 0;
static int _audiomemorypos = 0;
static int _audiomemorymax = 0;
static float audiomemory[AUDIOMEMEORYLEN];

int filtercreate(int fps) 
{
    return TRUE;
}

int filterdestroy() 
{
    return TRUE;
}

int filterstep(unsigned char *buffer, int w, int h, unsigned int color, char *text, int64_t framecount)
{
    return TRUE;
}

    
int filteraudio(float *frame, int64_t framecount, float elapsed)
{
       if(_talk)
       {	
            if(_audiomemorypos > _audiomemorymax - 2048)
            {
                 _audiomemorypos = 0;
            }
            memcpy(frame, &(audiomemory[_audiomemorypos]), sizeof(float)*2048);
            _audiomemorypos += 2048;
       } 
       return 1;
}

int filtermic(float *frame, int64_t framecount, float elapsed)
{
	float maxf;
	int i;
	maxf = 0.0f;

        if(!_talk)
        {
            if(_audiomemorypos < AUDIOMEMEORYLEN)
            {
                  memcpy(&(audiomemory[_audiomemorypos]), frame, sizeof(float)*2048);
                  _audiomemorypos += 2048;
            }
        }
	return 1;
}

int filterkey(int64_t code)
{
    _lasttalk = _talk;
    _talk = !_talk;
    _audiomemorymax = _audiomemorypos;
    _audiomemorypos = 0;
    return 1;
}
