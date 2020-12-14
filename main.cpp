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
    int Voo,opcion;
    cout<<"Simulador de disparos. "<<endl;
    cout <<"Ingrese Vo desde la cual quiere probar: "<<endl;
    cin >> Voo;
    cout <<"Seleccione una opcion: "<<endl;
    cout <<"1.disparos ofensivos que comprometen la integridad del canion defensivo. "<<endl;
    cout <<"2.disparos defensivos que comprometen la integridad del canion ofensivo. "<<endl;
    cout <<"3.disparos defensivos que impidan que el canion defensivo sea destruido "<<endl;
    cout <<"4.disparos defensivos que impidan que los caniones defensivo y ofensivo puedan ser destruidos."<<endl;
    cout <<"5.disparos que neutralicen el ataque defensivo y permitan que el ataque ofensivo sea efectivo."<<endl;
    cin>>opcion;
    canionDefensivo disparoDefensivo=canionDefensivo();
    canionOfensivo disparoOfensivo=canionOfensivo();
    canionDefensivo disparoDefensivo1=canionDefensivo();
    canionOfensivo disparoOfensivo1=canionOfensivo();
    while(opcion <=5){
        if (opcion==1){
            batalla_.DisparoOfensivo(disparoDefensivo, disparoOfensivo, Voo, true);
            break;
        }
        else if (opcion==2){
            batalla_.DisparoDefensivo(disparoDefensivo, disparoOfensivo, Voo);
            break;
        }
        else if(opcion==3){
            batalla_.DisparoDefensivo2(disparoDefensivo, disparoOfensivo,Voo,31,85,true);
            break;
        }
        else if(opcion==4){
            batalla_.DisparoOfensivo2(disparoDefensivo,disparoOfensivo, Voo, 150,109);
            //break;
        }
        else if(opcion==5){
             DisparoOfensivoEfectivo(Voo);
             break;
        }
        else{
            cout <<"La opcion ingresada no existe."<< endl;
        }
    }
    return 0;

}
