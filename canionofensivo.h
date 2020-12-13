#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include"impacto.h"
#include"caniondefensivo.h"


class canionOfensivo
{
private:
    float d = 800;
    float Ho = 100;
    float Xo = 0;
    float Yo = Ho;
    float d0 = 0.05*d;
    float ao = 0;

public:
    canionOfensivo();
    canionOfensivo(float d, float Hd, float ad);
    float getd(){return d;};
    float getHo(){return Ho;};
    float getXo(){return Xo;};
    float getYo(){return Yo;};
    float getd0(){return d0;};
    float getao(){return ao;};
    Impacto DisparoOfensivo(caniondefensivo disparoD, int Voo, bool mostrar);
    void DisparoOfensivo2(caniondefensivo disparoD, int Voo, int angleoo, int Vooo);

};

#endif // CANIONOFENSIVO_H
