
#include <Servo.h>

Servo base;
Servo brazoIzq;
Servo brazoDer;
Servo garra;
int pos = 0;
int cont;

//Posiciones de los Servos
int garraAbierta = 0;
int garraCerrada = 30;

int brazoDerAbajo = 140;
int bazoDerArriba = 90;

int brazoIzqAbajo = 90;
int brazoIzqArriba = 180;

int baseDer = 30;
int baseIzq = 180;


void setup() {
  // put your setup code here, to run once:
  
  base.attach(10);
  garra.attach(11);
  brazoIzq.attach(6);
  brazoDer.attach(9);
  Serial.begin(9600);

  //Posiciones Iniciales
  brazoIzq.write(180);
  brazoDer.write(90);
  base.write(30);
  garra.write(30);
}

void loop() {
  // put your main code here, to run repeatedly:  
  //movimiento();

  if (cont < 3)
  {
    //Toma el objeto
    AbrirGarra();
    
    brazoDerAbajo = 140;
    brazoIzqAbajo = 90;
    
    BajarBrazoIzq();
    BajaBrazoDer();
    
    CerrarGarra();
    
    SubirBrazoDer();
    SubirBrazoIzq();

    //Posiciones para apliar objetos sobre el primero
    if (cont == 1)
    {
      brazoDerAbajo = 120;
      brazoIzqAbajo = 110;
    }
    else if (cont == 2)
    {
      brazoDerAbajo = 110;  
      brazoIzqAbajo = 140;
    }
    
    //Gira a la izquierda
    BaseDerIzq();

    //Baja el brazo y coloca el objeto, si ya puso el primero, los pone encima
    BajarBrazoIzq();
    BajaBrazoDer();
    
    AbrirGarra();

    //Levanta el brazo y cierra la garra para tomar el siguiente objeto
    SubirBrazoDer();
    SubirBrazoIzq();
    
    CerrarGarra();

    //Posiciones de la base para tomar los objetos despues del primero
    if (cont == 0)
    {
      baseDer = 55;
    }
    else if (cont == 1)
    {
      baseDer = 75;
    }

    //Gira a la derecha para tomar el siguiente objeto
    BaseIzqDer();
  }
  //Suma 1 al contador para determinar en que vuelta va
  cont += 1;
}

//Gira de Derecha a Izquierda
void BaseDerIzq()
{
  //Mover Base Der-Izq
  Serial.println("Mover Base Der-Izq");
  for (pos = baseDer; pos <= baseIzq; pos +=1)
  {
    base.write(pos);
    Serial.println(pos);
    delay(15) ; 
  }
}

//Gira de izquierda a Derecha
void BaseIzqDer()
{
  //Mover Base Izq-Der
  Serial.println("Mover Base Izq-Der");
  for (pos = baseIzq; pos >= baseDer; pos -=1)
  {
    base.write(pos);
    Serial.println(pos);
    delay(15) ; 
  }
}

//Baja el Brazo Izquierdo
void BajarBrazoIzq()
{
  //Bajar/Subir brazoizq
  Serial.println("Baja BrazoIzq");
  for (pos = brazoIzqArriba; pos >= brazoIzqAbajo; pos -=1)
  {
    brazoIzq.write(pos);
    Serial.println(pos);
    delay(15);
  }
}

//Sube el brazo izquierdo
void SubirBrazoIzq()
{
  Serial.println("Levanta BrazoIzq");
  for (pos = brazoIzqAbajo; pos <= brazoIzqArriba; pos +=1)
  {
    brazoIzq.write(pos);
    Serial.println(pos);
    delay(15) ; 
  }
}

//Baja el brazo derecho
void BajaBrazoDer()
{
  Serial.println("BrazoDer Baja");
  for (pos = bazoDerArriba; pos <= brazoDerAbajo; pos +=1)
  {
    brazoDer.write(pos);
    Serial.println(pos);
    delay(15);
  }  
}

//Sube el brazo derecho
void SubirBrazoDer()
{
  Serial.println("BrazoDer Sube");
  for (pos = brazoDerAbajo; pos >= bazoDerArriba; pos -=1)
  {
    brazoDer.write(pos);
    Serial.println(pos);
    delay(15);
  }
}

//Abre la Garra
void AbrirGarra()
{
  Serial.println("Abrir Garra");
  for (pos = garraCerrada; pos >= garraAbierta; pos -=1)
  {
    garra.write(pos);
    Serial.println(pos);
    delay(15);
  }  
}

//Cierra la Garra
void CerrarGarra()
{
  Serial.println("Cerrar Garra");
  for (pos = garraAbierta; pos <= garraCerrada; pos +=1)
  {
    garra.write(pos);
    Serial.println(pos);
    delay(15);
  }  
}
