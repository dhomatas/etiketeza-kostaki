#include <SimpleRotary.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//Rotary r = Rotary(4, 5,6);
SimpleRotary rotary(4, 5,6);
//Rotary r_int = Rotary(2, 3);

#define rotary_switch 6
#define stop_key      7
#define STEP_PIN         8
#define DIR_PIN           9
#define EN_PIN       10


#include <EEPROM.h>

int index = 50
unsigned char result;
boolean mode_auto = true;
boolean mode_save=false;
boolean mode_reset = false;
byte menu_items = 5;
byte menu_index;
byte length0, pause0  ;
byte step_int = 2;
int bottles;
byte bounce_time=500;
volatile int l = 0;

void flag();
String m[]={"mode","length","pause","reset","save","exit"};

void setup()
{
  Serial.begin(9600);
  Serial.println(" Ëtiketeza ");
	lcd.begin();
	lcd.backlight();
  r.begin(true);
 //  r_int.begin();


 pinMode(2,INPUT_PULLUP); 
 pinMode(3,INPUT_PULLUP);   
 pinMode(rotary_switch,INPUT_PULLUP); 
 pinMode(stop_key     ,INPUT_PULLUP); 
 Serial.println(" Pins set ");

 
  EEPROM.get(0, length0); 
  EEPROM.get(1, pause0);
  EEPROM.get(2,bottles);

 attachInterrupt(0, flag, RISING); 
 sei(); 

  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW); //LOW or HIGH
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(STEP_PIN, LOW);

  digitalWrite(EN_PIN, LOW); //activate driver





}

  /*
  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19);
  sei();
  Serial.println(" Interrupt  set ");
  */


void loop(){
  Serial.println(" Program start ");
 mark00: 
lcd.clear();
lcd.setCursor (0,0);
lcd.print("Ready");
lcd.setCursor (0,1);
lcd.print("Press Start");
mark0:
  if ( digitalRead(rotary_switch)== LOW){
delay(bounce_time);
menu_index = setup_menu();
switch (menu_index){
    case 0:
          menu_auto();
          break;
    case 1:
          length_menu();
          break;
    case 2:
          pause_menu();
          break;
    case 3:
          reset_menu();
          break;
    case 4:
         save_menu();
         break;
    case 5:
         break;
  
   } // switch
   delay(bounce_time);
   goto mark00;
  }//if

   byte i;  // 0 = not turning, 1 = CW, 2 = CCW
  i = rotary.rotate();

 switch (i){

  if (i!=0) {
    lcd.clear();
  case 1: 
          digitalWrite(DIR_PIN,  LOW);
            for (int t =0 ; t<3;t++){
          digitalWrite(STEP_PIN, HIGH);
          delay(step_int);
          digitalWrite(STEP_PIN, LOW);
          delay(step_int);
          // index = index+1;
         }
  break;
  case 2: 
          digitalWrite(DIR_PIN,  HIGH);
           for (int t =0 ; t<3;t++){
          digitalWrite(STEP_PIN, HIGH);
          delay(step_int);
          digitalWrite(STEP_PIN, LOW);
          delay(step_int);
            }
   break;
  }
    lcd.setCursor (10,0);lcd.print(l);
    l=0;
    delay(100);
  }
  goto mark0;
}
