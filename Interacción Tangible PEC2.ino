
#include <LiquidCrystal.h>//librería para poder enviar mensajes a la LCD

LiquidCrystal lcd(11, 10, 5, 4, 3, 2);// configuramos los pines digitales que van a enviar los mensajes a la LCD
const int motorPin = 9; //definimos y fijamos el PIN que va a mandar la señal al relé en el proyecto definitivo (en el prototipo va a mandar la señal al motor)
const int Pulsador1 = 12; //definimos y fijamos el PIN del pulsador 1
const int Pulsador2 = 13; //definimos y fijamos el PIN del pulsador 2
const int LedRojo = 6; //definimos y fijamos el PIN del LED Rojo
const int LedVerde = 7; //definimos y fijamos el PIN del LED Verde
const int Altavoz = 8; //definimos y fijamos el PIN del Altavoz
int LecturaBoton1 = LOW; //definimos y fijamos el PIN del pulsador 1
int LecturaBoton2 = LOW; //definimos y fijamos el PIN del pulsador 2

void setup()
{
 //configuramos los pines de los LED como SALIDAS y los inicializamos como APAGADOS 
  pinMode(LedRojo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedVerde, LOW);
  
  //configuramos los pines del altavoz y del motor (relé en el proyecto final) como salidas
  pinMode(Altavoz, OUTPUT);
  pinMode(motorPin, OUTPUT);
 
 //configuramos los pulsadores como entradas
  pinMode(Pulsador1, INPUT);
  pinMode(Pulsador2, INPUT);
 
}
//arrancamos el loop de funcionamiento del programa
void loop()
{

  lcd.begin(16,2); // inicializamos pantalla de 16x2, el hacerlo al principio del loop es para refrescar el estado en cada vuelta.


  LecturaBoton1 = digitalRead(Pulsador1); //leemos el pulsador 1. Si no hay actividad vamos al final del loop, alternando el mensaje "dispositivo apagado, pulse rojo para encender"
    
  if (LecturaBoton1 == HIGH) { //detectamos que el pulsador rojo está activo, iniciamos encendido..
    
    
    digitalWrite(LedRojo, HIGH); //encendemos el LED rojo

    //tono de espera de acción por parte del usuario. Dos tonos iguales. He tomado las frecuencias de los tonos de un archivo encontrado en un ejemplo que se llama "pitches.h". 
    tone(Altavoz, 784, 300); //tono(destino, frecuencia, duración de la nota)
    delay(300); //silencio
    tone(Altavoz, 784, 500);
    delay(300);
    noTone(Altavoz); //silenciamos el altavoz

    //lanzamos a la LCD el mensaje de que el pulsador uno está activo. 

    lcd.clear();//antes de lanzar un mensaje a la LCD, "limpiamos la pantalla" del contenido que pudiera tener antes.
    lcd.print("Pulsador 1");
    lcd.setCursor(0, 1); //bajamos a la segunda línea
    lcd.print("Activado");
    lcd.setCursor(0, 0);
    //y esperamos 1 segundo
    delay (1000);

    //volvemos a leer los pulsadores verde y rojo
    LecturaBoton1 = digitalRead(Pulsador1);
    LecturaBoton2 = digitalRead(Pulsador2);
    //si aún no se ha pulsado el verde, alternamos entre los mensajes "Pulsador 1 activado" y "Pulse 1+2 para encender disp." en intervalos de 1 segundo, 
    //comprobando el estado de los pulsadores
      if (LecturaBoton1 == HIGH && LecturaBoton2 == LOW) {
      
      lcd.clear();
      lcd.print("Pulse 1+2 para");
      lcd.setCursor(0, 1);
      lcd.print("encender disp.");
      lcd.setCursor(0, 0);
      delay (1000);
      } //primer if

      LecturaBoton2 = digitalRead(Pulsador2);
      LecturaBoton1 = digitalRead(Pulsador1);
      if (LecturaBoton1 == HIGH && LecturaBoton2 == LOW) {
      
      lcd.clear();
      lcd.print("Pulsador 1");
      lcd.setCursor(0, 1);
      lcd.print("Activado");
      lcd.setCursor(0, 0);
      delay (1000);
      } //cierre de primer else if

      LecturaBoton1 = digitalRead(Pulsador1);
      LecturaBoton2 = digitalRead(Pulsador2);
      if (LecturaBoton1 == HIGH && LecturaBoton2 == LOW) {

      lcd.clear();
      lcd.print("Pulse 1+2 para");
      lcd.setCursor(0, 1);
      lcd.print("encender disp.");
      lcd.setCursor(0, 0);
      delay (1000);
      }//cierre de 2o else if

      LecturaBoton1 = digitalRead(Pulsador1);
      LecturaBoton2 = digitalRead(Pulsador2);
      if (LecturaBoton1 == HIGH && LecturaBoton2 == LOW) {

      lcd.clear();
      lcd.print("Pulsador 1");
      lcd.setCursor(0, 1);
      lcd.print("Activado");
      lcd.setCursor(0, 0);  
      delay (1000);
      }//cierre de 3er else if
      
      LecturaBoton1 = digitalRead(Pulsador1);
      LecturaBoton2 = digitalRead(Pulsador2);

      if (LecturaBoton1 == HIGH && LecturaBoton2 == LOW) {

      //si no hay actividad tras 5 segundos.... apagamos el sistema por inactividad
      
      lcd.clear();
      lcd.print("Time Out");
      lcd.setCursor(0, 1);
      lcd.print("Apagando... ");
      lcd.setCursor(0, 0);
      
      //tono de apagado al altavoz
      tone(Altavoz, 1047, 300);
      delay(200);
      tone(Altavoz, 784, 300);
      delay(200);
      tone(Altavoz, 659, 300);
      delay(200);
      tone(Altavoz, 523, 300);
      delay(200);
      
      delay(5000); // esperamos 5 segundos antes de volver al loop inicial

      }//cierre de 4o else if

 
//volvemos a leer los pulsadores, ya fuera de las primeras condiciones...
    LecturaBoton1 = digitalRead(Pulsador1);
    LecturaBoton2 = digitalRead(Pulsador2);

    //si ambos botones están presionados. 
      if (LecturaBoton1 == HIGH && LecturaBoton2 == HIGH) {
      digitalWrite(LedVerde, HIGH); //encendemos el LED Verde (el rojo ya estaba encendido)
      //reproducimos Sonido de Encendido. Enviamos los tonos por separado, cada uno con un silencio después.
      tone(Altavoz, 262, 250);
      delay(200);
      tone(Altavoz, 523, 250);
      delay(200);
      tone(Altavoz, 392, 250);
      delay(200);
      tone(Altavoz, 440, 250);
      delay(200);
      tone(Altavoz, 392, 250);
      delay(200);
      tone(Altavoz, 494, 250);
      delay(200);
      tone(Altavoz, 523, 250);
      delay(200);
      noTone(Altavoz);

      //y encendemos el motor (en el diseño definitivo, excitaremos el relé)
      digitalWrite(motorPin, HIGH);
      
      //mandamos a la LCD el mensaje de que el dispositivo está funcionando
      do{
        lcd.clear();
        lcd.print("Dispositivo");
        lcd.setCursor(0, 1);
        lcd.print("encendido");
        lcd.setCursor(0, 0);
        delay(5000); // Aunque en el definitivo serán 20 minutos, hacemos un delay de 5 segundos en el prototipo, para no tener que estar tanto tiempo esperando para el siguiente mensaje.

        //tras pasar los 20 minutos, llamamos la atención del ususario con un sonido, para preguntarle si desea continuar.
        tone(Altavoz, 784, 300);
        delay(200);
        tone(Altavoz, 784, 300);
        delay(200);
        noTone(Altavoz);
        tone(Altavoz, 784, 300);
        delay(200);
        tone(Altavoz, 784, 300);
        delay(200);
        noTone(Altavoz);
        //y lanzamos el mensaje a la pantalla de que si desea continuar, se pulse el botón verde.

        lcd.clear();
        lcd.print("Continuar?");
        lcd.setCursor(0, 1);
        lcd.print("Pulse Verde");
        lcd.setCursor(0, 0);
        delay(3000);//damos 3 segundos para que el ususario reaccione
        
        LecturaBoton2 = digitalRead(Pulsador2);//y leemos el pulsador 2


       }while(LecturaBoton2 == HIGH);//en caso de que se haya pulsado el verde, volvemos al inicio del "do", y repetimos el bucle esperando otros 20 minutos.

       //si no hemos confirmado el continuar encendido, pasamos al mensaje de apagado.

       //mensaje en LCD
      lcd.clear();
      lcd.print("Apagando");
      lcd.setCursor(0, 1);
      lcd.print("Dispositivo");
      lcd.setCursor(0, 0);

      //melodía de apagado en altavoz
      tone(Altavoz, 1047, 300);
      delay(200);
      tone(Altavoz, 784, 300);
      delay(200);
      noTone(Altavoz);
      tone(Altavoz, 659, 300);
      delay(200);
      tone(Altavoz, 523, 300);
      delay(200);
      noTone(Altavoz);
      
      //y volvemos a poner tanto los led como el motor (relé) a cero.
      digitalWrite(LedRojo, LOW);
      digitalWrite(LedVerde, LOW);
      digitalWrite(motorPin, LOW);



      delay (2000);//esperamos 2 segundos para volver al loop continuo.


    }
    else{}
  }
    else{


    //en caso de no haber existido actividad tras la primera pulsación del botón rojo, apagamos los leds y el motor, aunque pueda ser redundante.
    digitalWrite(LedRojo, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(motorPin, LOW);
 
    

    }

      // y este es el mensaje que veremos tanto en completa inactividad del sistema como si tras su funcionamiento se ha apagado, son dos mensajes que se alternan cada segundo.

      lcd.clear();
      lcd.print("Dispositivo");
      lcd.setCursor(0, 1);
      lcd.print("Apagado");
      lcd.setCursor(0, 0);
      delay(1000); 

      lcd.clear();
      lcd.print("Pulsador rojo");
      lcd.setCursor(0, 1);
      lcd.print("para encender");
      lcd.setCursor(0, 0);
      delay(1000); 
      
  }
  
