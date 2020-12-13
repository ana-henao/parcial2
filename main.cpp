#include <iostream>
#include <math.h>
#include"batalla.h"
#define G 9.81
#define pi 3.141617
using namespace std;

batalla batalla_=batalla();

void DisparoOfensivoEfectivo (int Voo){

    canionDefensivo disparoD=canionDefensivo();
    canionOfensivo disparoO=canionOfensivo();

    Impacto impactoEfectivo=batalla_.DisparoOfensivo(disparoD, disparoO, Voo, false);
    cout <<"disparo ofensivo efectivo"<< endl;
    impactoEfectivo.ImprimirResultados1();
    Impacto impactoDefensivo=batalla_.DisparoDefensivo2(disparoD,disparoO,Voo,impactoEfectivo.getangle(),impactoEfectivo.getV0o(),false);
    cout <<"disparo defensivo que compromete la efectividad del ataque ofensivo"<< endl;
    impactoDefensivo.ImprimirResultados1();
    cout <<"disparos que neutralizan el ataque defensivo" <<endl;
    batalla_.DisparoOfensivo2(disparoD,disparoO, Voo,impactoDefensivo.getangle(),impactoDefensivo.getV0o());

}

int main()
{
    int Voo;
    cout <<"Ingrese Vo desde la cual quiere probar: "<<endl;
    cin >> Voo;
    canionDefensivo disparoDefensivo=canionDefensivo();
    canionOfensivo disparoOfensivo=canionOfensivo();
   // batalla_.DisparoOfensivo(disparoDefensivo, disparoOfensivo, Voo, true);
    //batalla_.DisparoDefensivo(disparoDefensivo, disparoOfensivo, Voo);
    //batalla_.DisparoDefensivo2(disparoDefensivo, disparoOfensivo,Voo,31,85,true);
    //batalla_.DisparoOfensivo2(disparoDefensivo,disparoOfensivo, Voo, 84,109);
    //canionDefensivo disparoDefensivo1=canionDefensivo();
    //canionOfensivo disparoOfensivo1=canionOfensivo();
    DisparoOfensivoEfectivo(Voo);

    return 0;
}
