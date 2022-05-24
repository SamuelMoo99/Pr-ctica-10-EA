
//Asignacion de pines
int pot=0;
int velocidad;
int pwmmotor=3;

int botonderecha=4;
int botonparo=5;
int botonizquierda=6;
int marchaderecha=7;
int marchaizquierda=8;

//configuracion de pines
void setup() {
  // put your setup code here, to run once:

pinMode (botonparo, INPUT);
pinMode (botonizquierda, INPUT);
pinMode (botonderecha, INPUT);

pinMode (marchaderecha, OUTPUT);
pinMode (marchaizquierda, OUTPUT);
pinMode (pwmmotor,OUTPUT);
  //Las entradas analogicas no necesitan aignacion
 Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
 
  if (digitalRead(botonderecha)==HIGH)
  {
    derecha();
     }
    else if (digitalRead(botonizquierda)==HIGH)
      {
      izquierda();
      }
  }

  
 void derecha() {
      while (digitalRead(botonparo)==LOW)
      {
        digitalWrite(marchaderecha,HIGH);
         PWM();
      }
        digitalWrite(marchaderecha,LOW);
        delay(1000);
     }

     
   void izquierda() {
      while(digitalRead(botonparo)==0)
      {
        digitalWrite(marchaizquierda,1);
          PWM();        
        }        
        digitalWrite(marchaizquierda,0);
        delay(1000);
      }

    void PWM(){
      velocidad=analogRead(pot)/4;
      analogWrite(pwmmotor,velocidad);
      
      
      }

 
