#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include"canionofensivo.h"


class caniondefensivo
{
private:
    float d = 800;
    float Hd = 20;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d;
    float ad = 0;

public:
    caniondefensivo();
    caniondefensivo(float d, float Hd, float ad);
    void DisparoDefensivo(canionOfensivo disparoO, int Voo);
    Impacto DisparoDefensivo2(Do disparoO,Dd disparoD, int Voo, int angleoo, int Vooo, bool mostrar)
    float getd(){return d;};
    float getHd(){return Hd;};
    float getXd(){return Xd;};
    float getYd(){return Yd;}
    float getd0(){return d0;};
    float getad(){return ad;};
};

#endif // CANIONDEFENSIVO_H
