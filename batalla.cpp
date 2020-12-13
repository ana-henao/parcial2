#include "batalla.h"

batalla::batalla()
{

}

void batalla::DisparoDefensivo(canionDefensivo disparoD, canionOfensivo disparoO, int Voo)
{
    int flag=0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    Impacto impacto2=Impacto(angle, V0o, -x, y, t);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 180; angle > 90; angle--){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoD.getYd() + Vy0*t -(0.5*G*t*t);

                if(sqrt(pow((disparoO.getXo() - x),2)+pow((disparoO.getYo() - y),2)) < disparoO.getd0()){
                    if(y<0) y=0;
                     impacto2.update(angle, V0o, -x, y, t);
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

Impacto batalla::DisparoDefensivo2(canionDefensivo disparoD, canionOfensivo disparoO, int Voo, int angleoo, int Vooo, bool mostrar)
{
    int flag=0;
    float x,y, x2, y2;
    float Vxo,Vy0, Vxoo, Vyoo;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;//no se coloca angulo especifico por que no se sabe a que angulo dispara para que le diera
    Impacto impacto=Impacto(angleoo, Vooo, x2, y2, t+1);
    Impacto impacto2=Impacto(angle, V0o, x, y, t);
    bool tomado=false;
    Impacto salida=Impacto(angle, V0o, x, y, t);
    Vxoo=Vooo*cos((angleoo)*pi/180);
    Vyoo = Vooo*sin((angleoo)*pi/180);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 180; angle > 90; angle--){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
               x2 = Vxoo*(t+2);
               y2 = disparoO.getYo() + Vyoo*(t+2) -(0.5*G*t*t);
               x = disparoD.getXd()+Vxo*t;
               y = disparoD.getYd() + Vy0*t -(0.5*G*t*t);	             //cout << y<< endl;
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoO.getd0()){
                    if(y<0) y=0;

                    if(tomado==false && flag==0 && mostrar==false){
                        salida.update(angle, V0o, x, y, t);
                        tomado=true;
                        flag=3;
                        break;
                    }
                    impacto.update(angleoo, Vooo, x2, y2, t+1);
                    impacto2.update(angle, V0o, x, y, t);
                    if(mostrar){

                        cout << "------------------ Normal: ---------------------------------"<< endl;
                         impacto.ImprimirResultados1();
                         cout<< "------------------ Retraso: 1 s ----------------------------"<< endl;
                         //ImprimirResultados1(angle, V0o, x, y, t);

                         impacto2.ImprimirResultados1();
                         cout <<"-------------------------------------------------------------"<< endl;
                        }
                    flag += 1;
                    V0o+=50;
                    //if(tomar1) break;
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
    return salida;
}

Impacto batalla::DisparoOfensivo(canionDefensivo disparoD, canionOfensivo disparoO, int Voo, bool mostrar)
{

    int flag=0;// contador de disparos
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;
    Impacto impacto2=Impacto(0,0,0,0,0);
    bool tomado=false;
    Impacto salida=Impacto(0,0,0,0,0);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoO.getYo() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoD.getXd() - x),2)+pow((disparoD.getYd() - y),2)) < disparoO.getd0()){
                    if(y<0) y=0;
                    impacto2.update(angle, V0o, x, y, t);
                    if(tomado==false && flag==2){
                        salida.update(angle, V0o, x, y, t);
                        tomado=true;
                    }
                    //cout << angle<<endl;
                    //cout << "Impacto angulo: "<<impactos[flag].angle<< endl;

                    if(mostrar){
                         //ImprimirResultados1(angle, V0o, x, y, t);

                         impacto2.ImprimirResultados1();
                    }
                    flag += 1;
                    V0o+=50;
                    //if (tomar1) break;
                    break;
                }
                if(y < 0){// si pasa la posicion de y, no impacta
                    break;
                }
            }
            if(flag==3) break;
             //if (tomar1) break;

        }
        if(flag==3) break;
         //if (tomar1) break;
    }
    if(flag!=3){
        cout << "No impacto en los disparos esperados"<< endl;

    }
    return salida;
}

void batalla::DisparoOfensivo2(canionDefensivo disparoD,canionOfensivo disparoO, int Voo, int angleoo, int Vooo)
{   int flag=0;
    float x=0,y=0, x2=0, y2=0;
    float Vxo,Vy0, Vxoo, Vyoo;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;//no se coloca angulo especifico por que no se sabe a que angulo dispara para que le diera
    Impacto impacto=Impacto(angleoo, Vooo, x2, y2, t+1);
    Impacto impacto2=Impacto(angle, V0o, x, y, t);
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
                y2 = disparoD.getYd() + Vyoo*(t+1) -(0.5*G*t*t);
                x = disparoO.getXo()+Vxo*t;
                y = disparoO.getYo() + Vy0*t -(0.5*G*t*t);
                //cout << y2<< endl;
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.getd0()){
                    if(y<0) y=0;
                    impacto.update(angleoo, Vooo, x2, y2, t+1);
                    cout << "------------------ Normal: ---------------------------------"<< endl;
                    impacto.ImprimirResultados1();
                    cout<< "------------------ Retraso: 1 s ----------------------------"<< endl;
                    //ImprimirResultados1(angle, V0o, x, y, t);
                    impacto2.update(angle, V0o, x, y, t);
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

