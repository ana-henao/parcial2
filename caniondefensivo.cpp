#include "caniondefensivo.h"

using namespace std;

canionDefensivo::canionDefensivo()
{

}

canionDefensivo::canionDefensivo(float d, float Hd, float ad)
{
    this->d=d;
    this->Hd=Hd;
    this->ad=ad;
}

void canionDefensivo::DisparoDefensivo(canionOfensivo disparoO, int Voo)
{
    int flag=0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 180; angle > 90; angle--){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = this->getYd() + Vy0*t -(0.5*G*t*t);

                if(sqrt(pow((disparoO.getXo() - x),2)+pow((disparoO.getYo() - y),2)) < disparoO.getd0()){
                    if(y<0) y=0;
                     Impacto impacto2=Impacto(angle, V0o, -x, y, t);
                     impacto2.ImprimirResultados1();
                    //ImprimirResultados1(angle, V0o, -x, y, t);
                    flag += 1;
                    V0o+=25;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag==3) break;

        }
        if(flag==3) break;
    }

}

Impacto canionDefensivo::DisparoDefensivo2(canionOfensivo disparoO, int Voo, int angleoo, int Vooo, bool mostrar)
{
    int flag=0;
    float x,y, x2, y2;
    float Vxo,Vy0, Vxoo, Vyoo;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;//no se coloca angulo especifico por que no se sabe a que angulo dispara para que le diera

    Vxoo=Vooo*cos((90-(angleoo-90))*pi/180);
    Vyoo = Vooo*sin((90-(angleoo-90))*pi/180);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t+1);
                y2 = this->getYd() + Vyoo*(t+1) -(0.5*G*t*t);
                x = this->getXd()+Vxo*t;
                y = this->getYd() + Vy0*t -(0.5*G*t*t);
                //cout << y<< endl;
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoO.getd0()){
                    if(y<0) y=0;
                   Impacto impacto=Impacto(angleoo, Vooo, x2, y2, t+1);
                   cout << "------------------ Normal: ---------------------------------"<< endl;
                    impacto.ImprimirResultados1();
                    cout<< "------------------ Retraso: 1 s ----------------------------"<< endl;
                    //ImprimirResultados1(angle, V0o, x, y, t);
                    Impacto impacto2=Impacto(angle, V0o, x, y, t);
                    impacto2.ImprimirResultados1();
                    cout <<"-------------------------------------------------------------"<< endl;
                    flag += 1;
                    V0o+=50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag==3) break;

        }
        if(flag==3) break;
    }
    if(flag!=3){
        cout << "No impacto en los disparos esperados"<< endl;

    }
}


