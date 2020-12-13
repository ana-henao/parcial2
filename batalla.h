#ifndef BATALLA_H
#define BATALLA_H
#include"canionofensivo.h"
#include"caniondefensivo.h"

class batalla
{
public:
    batalla();

    void DisparoDefensivo(canionDefensivo disparoD, canionOfensivo disparoO, int Voo);
    Impacto DisparoDefensivo2(canionDefensivo disparoD,canionOfensivo disparoO, int Voo, int angleoo, int Vooo, bool mostrar);
    Impacto DisparoOfensivo(canionDefensivo disparoD, canionOfensivo disparoO, int Voo, bool mostrar);
    void DisparoOfensivo2(canionDefensivo disparoD, canionOfensivo disparoO, int Voo, int angleoo, int Vooo);


};

#endif // BATALLA_H
