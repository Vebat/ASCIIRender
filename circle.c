#include <stdio.h>
#include <math.h>

#define R2 2
#define R1 1

float calculateX(float theta, float phi)
{
    return R2+R1*cos(theta);
}

float calculateY(float theta, float phi)
{
    return R1*sin(theta)*cos(phi);
}

float calculateZ(float theta, float phi)
{
  return 3-1*R1*sin(theta)*sin(phi);
}

void renderFrame(float phi)
{
    char output[64][24];

    for (size_t i = 0; i < 64; i++)
    {
      for (size_t j = 0; j < 24; j++)
      {
        output[i][j]=' ';
      } 
    }

    float x,y,z;
    int xp,yp;
    float angle;
    int i = 0;
    for(angle = 0; angle < 6.28; angle=angle+0.07)
    {
        x=calculateX(angle,phi);
        y=calculateY(angle,phi);
        z=calculateZ(angle,phi);
        float z1=1/z;
        xp=(int)(64/2-10+15*2*z1*x);
        yp=(int)(24/2+15*z1*y);

        output[xp][yp]='@';
    }    
         printf("\x1b[H");
     for (int j = 0; j < 24; j++) {
    for (int i = 0; i < 64; i++) {
      putchar(output[i][j]);
    }
    putchar('\n');
  }

}

int main()
{
  for (size_t i = 0; i < 10; i++)
  {
   for(float phi; phi < 6.28 ; phi+=0.07)
    {
        renderFrame(phi);
        usleep(100);
    }
  }
  
    
    return 0;
}