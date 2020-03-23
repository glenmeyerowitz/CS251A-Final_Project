#include <stdio.h>

float fmad(float in1, float in2, float in3) {
  float ret = 0.0;
  float src = 99.9;
  float dst = 0.0;

  asm ("fld %1" : "=g" (dst) : "g" (src));
  asm ("fdivr %2, %0" : "=&t" (ret) : "%0" (in1), "u" (in2)); 
  return ret;
}

int main() {
  float a = 3.14;
  float b = 2.71;
  float g = 9.0;
  float c = fmad(a,b,g); 
  printf("%f\n", c); 
  
  float d = -1.2;
  float e = -4.5;
  float h = 7.0;
  float f = fmad(d,e,h); 
  printf("%f\n", f); 
  return 0;
}
