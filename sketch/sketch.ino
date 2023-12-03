//Librerias
#include<LiquidCrystal.h>

//LCD
#define COLS 16
#define ROWS 2

//Activar DEBUG
const boolean DebugMode = true;

//Sensor Luz y motor
const int PinMotor = 10;
const int PinEntradaLDR = A0;
const int ValorLDR = 100;
int ValorSensor = 0;
int VelocidadMotor = 70;

// LCD
const int PosicionText = 3;
const int PosicionTextCero = 0;
const String LCDTexto = "STARS WARS";

//Serial
const int SerialBegin = 9600;
const String strVacio = "";
const String strEspacioVacio = " ";
const String StrEncendido = "Encendido";
const String StrApagado = "Apagado";
const String StrLDR = "Valor de LDR: ";
const String StrDegubActivado = "Debub ACTIVADO";
const String StrDegubDesactivado = "Debub DESACTIVADO";

//Componentes
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin (SerialBegin);
  pinMode(PinMotor, OUTPUT);
  pintarLCD(LCDTexto, PosicionText, PosicionTextCero, COLS, ROWS);

  if (DebugMode) {
    Serial.println(StrDegubActivado);
  } else {
    Serial.println(StrDegubDesactivado);
  }
}

void loop() {
  ValorSensor = analogRead(PinEntradaLDR);

  if (ValorSensor > ValorLDR) {
    digitalWrite(PinMotor, HIGH);
    analogWrite(PinMotor,VelocidadMotor);
    if (DebugMode) {
      String strVacio = StrLDR + ValorSensor + strEspacioVacio + StrEncendido;
      Serial.println(strVacio);
    }
  } else {
    digitalWrite(PinMotor, LOW);
    if (DebugMode) {
      String strVacio = StrLDR + ValorSensor + strEspacioVacio + StrApagado;
      Serial.println(strVacio);
    }
  }
}

void pintarLCD (String texto, int posicionColumna, int posicionFila, int columnas, int filas) {
  lcd.begin(columnas, filas);
  lcd.setCursor(posicionColumna, posicionFila);
  lcd.print(texto);
}
