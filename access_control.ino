#include <SD.h>

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <RFID.h>
#include "RTClib.h"
char* nome = "0";
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

#define SS_PIN 10
#define RST_PIN 9

void principal();
RTC_DS1307 rtc;

RFID rfid(SS_PIN, RST_PIN);   // Create RFID instance.

int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

const int chipSelect = 4;

void setup () {

  Serial.begin(9600);
  Serial.print("Inicializando o SD card...");
  // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect)) {
      Serial.println("Nao ha cartao disponivel");
    // don't do anything more:
    return;
  }
  Serial.println("cartao inicializado");
 
  SPI.begin();
  rfid.init();
  lcd.begin (20,4);
  lcd.setBacklight(HIGH);
    
  if (! rtc.begin()) {
    Serial.println("Nao achou o RTC");
    lcd.setCursor(0,0);
    lcd.print("Nao achou o RTC");
    while (1);
    
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC nao esta rodando!");
    lcd.setCursor(0,0);
    lcd.print("RTC nao esta rodando!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop () {

    principal();
    if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
          /* Quando for reconhecido um novo cartao. */
          Serial.println(" ");
          Serial.println("Cartao reconhecido");
          serNum0 = rfid.serNum[0];
          serNum1 = rfid.serNum[1];
          serNum2 = rfid.serNum[2];
          serNum3 = rfid.serNum[3];
          serNum4 = rfid.serNum[4];
   
          Serial.print(rfid.serNum[0],HEX);
          Serial.print(": ");
          Serial.print(rfid.serNum[1],HEX);
          Serial.print(": ");
          Serial.print(rfid.serNum[2],HEX);
          Serial.print(": ");
          Serial.print(rfid.serNum[3],HEX);
          Serial.print(": ");
          Serial.print(rfid.serNum[4],HEX);
          Serial.println(" ");
       } else {
         /* Se o cartao possui o mesmo ID, imprime pontos na tela */
         Serial.print(".");
       }
    }
    rfid.halt(); 

switch (serNum0) {
      case 125:
      if (serNum1 == 254 && serNum2 == 74 && serNum3 == 200 && serNum4 == 1) //UID 1 - Ge
      {
        Serial.println("Ola Gedeane!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Gedeane!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "gedeane";
        escrita_SD();
        delay(1000);
        principal();
      }
        break;
      case 19:
        if(serNum1 == 166 && serNum2 == 226 && serNum3 == 199 && serNum4 == 144) //UID 1 - Chaveiro
       {
        Serial.println("Ola Tag!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola TAG!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "TAG";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 90:
        if(serNum1 == 193 && serNum2 == 176 && serNum3 == 133 && serNum4 == 174) 
       {
        Serial.println("Ola Funcionario1!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario1!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario1";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 146:
         if(serNum1 == 56 && serNum2 == 83 && serNum3 == 117 && serNum4 == 140) 
       {
        Serial.println("Ola Funcionario2!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario2!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario2";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 74:
         if(serNum1 == 245 && serNum2 == 178 && serNum3 == 133 && serNum4 == 136) 
       {
        Serial.println("Ola Funcionario3!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario3!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario3";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 236:
         if(serNum1 == 130 && serNum2 == 18 && serNum3 == 203 && serNum4 == 183) 
       {
        Serial.println("Ola Funcionario4!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario4!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario4";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 167:
         if(serNum1 == 69 && serNum2 == 178 && serNum3 == 133 && serNum4 == 213) 
       {
        Serial.println("Ola Funcionario5!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario5!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario5";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 48:
         if(serNum1 == 146 && serNum2 == 84 && serNum3 == 117 && serNum4 == 131) 
       {
        Serial.println("Ola Funcionario6!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario6!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario6";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 26:
         if(serNum1 == 53 && serNum2 == 180 && serNum3 == 133 && serNum4 == 30) 
       {
        Serial.println("Ola Funcionario7!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario7!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario7";
        escrita_SD();
        serNum0=0;
        nome=0;
        delay(1000);
        principal();
      }
        break;
      case 151:
         if(serNum1 == 141 && serNum2 == 178 && serNum3 == 133 && serNum4 == 45) 
       {
        Serial.println("Ola Funcionario8!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Ola Funcionario8!");
        lcd.setCursor(0,2);
        lcd.print("Acesso liberado!");
        nome = "Funcionario8";
        escrita_SD();
        serNum0=0;
        delay(1000);
        principal();
      }
        break;
      
        break;
      default:
         delay(1);
    }
  }
 void principal(){
    
    DateTime now = rtc.now();
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.print(now.day(), DEC);
    lcd.print(now.day(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.month(), DEC);
    lcd.print(now.month(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.year(), DEC);
    lcd.print(now.year(), DEC);
    Serial.print(" (");
    lcd.print(' ');
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    lcd.setCursor(0,1);
    Serial.print(now.hour(), DEC);
    lcd.print(now.hour(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.minute(), DEC);
    lcd.print(now.minute(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.println(now.second(), DEC);
    lcd.print(now.second(), DEC); 
    
    lcd.setCursor(0,3);
    lcd.print("Aproxime seu cartao ");
    delay(1000);  

  }

  void escrita_SD(){
   
    DateTime now = rtc.now();
    delay(1000);
    File dataFile = SD.open("data.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(nome);
    dataFile.print(' ');
    dataFile.print(now.day(), DEC);
    dataFile.print('/');
    dataFile.print(now.month(), DEC);
    dataFile.print('/');
    dataFile.print(now.year(), DEC);
    dataFile.print(' ');
    dataFile.print(daysOfTheWeek[now.dayOfTheWeek()]);
    dataFile.print(' ');
    dataFile.print(now.hour(), DEC);
    dataFile.print(':');
    dataFile.print(now.minute(), DEC);
    dataFile.print(':');
    dataFile.print(now.second(), DEC);
    dataFile.println(' ');
    dataFile.println(' ');
    dataFile.close();
    // print to the serial port too:
    Serial.println("Dados gravados");
    return;
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("Erro ao abrir data.txt");
  }
 }


