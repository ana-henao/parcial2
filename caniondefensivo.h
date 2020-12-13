#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H

#define G 9.81
#define pi 3.141617
#include<math.h>
#include <iostream>
#include"impacto.h"

using namespace std;


class canionDefensivo
{
private:
    float d = 800;
    float Hd = 20;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d;
    float ad = 0;

public:
    canionDefensivo();
    canionDefensivo(float d, float Hd, float ad);
    float getd(){return d;};
    float getHd(){return Hd;};
    float getXd(){return Xd;};
    float getYd(){return Yd;}
    float getd0(){return d0;};
    float getad(){return ad;};
    Impacto *impactos[3];
};

#endif // CANIONDEFENSIVO_H
