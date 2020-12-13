#include <iostream>
#include <math.h>
#include"caniondefensivo.h"
#include"canionofensivo.h"
#define G 9.81
#define pi 3.141617
using namespace std;

void DisparoOfensivoEfectivo ( canionOfensivo disparoO, canionDefensivo disparoD, int Voo){

    Impacto impactoEfectivo=disparoO.DisparoOfensivo(disparoD, Voo, false);
    cout <<"disparo ofensivo efectivo"<< endl;
    impactoEfectivo.ImprimirResultados1();
    Impacto impactoDefensivo=disparoD.DisparoDefensivo2(disparoO,Voo,impactoEfectivo.getangle(),impactoEfectivo.getV0o(),false);
    cout <<"disparo defensivo que compromete la efectividad del ataque ofensivo"<< endl;
    impactoDefensivo.ImprimirResultados1();
    cout <<"disparos que neutralizan el ataque defensivo" <<endl;
   disparoO.DisparoOfensivo2(disparoO,disparoD, Voo,impactoDefensivo.getangle(),impactoDefensivo.getV0o());

}

int main()
{
    int Voo;
    cout <<"Ingrese Vo desde la cual quiere probar: "<<endl;
    cin >> Voo;
    canionDefensivo disparoDefensivo=canionDefensivo();
    canionOfensivo disparoOfensivo=canionOfensivo();
    disparoOfensivo.DisparoOfensivo(disparoDefensivo, Voo);
//    disparoDefensivo.DisparoDefensivo(disparoOfensivo, Voo);
//    disparoDefensivo.DisparoDefensivo2(disparoOfensivo,Voo,31,85,true);
//    disparoOfensivo.DisparoOfensivo2(disparoDefensivo, Voo, 93,85);
//    DisparoOfensivoEfectivo( disparoOfensivo, disparoDefensivo,Voo);
    return 0;
}
