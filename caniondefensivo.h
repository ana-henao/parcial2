#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include"canionofensivo.h"
#define G 9.81
#define pi 3.141617
#include<math.h>
#include <iostream>

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
    void DisparoDefensivo(canionOfensivo disparoO, int Voo);
    Impacto DisparoDefensivo2(canionOfensivo disparoO, int Voo, int angleoo, int Vooo, bool mostrar);
    float getd();;
    float getHd(){return Hd;};
    float getXd(){return Xd;};
    float getYd(){return Yd;}
    float getd0(){return d0;};
    float getad(){return ad;};
};

#endif // CANIONDEFENSIVO_H
