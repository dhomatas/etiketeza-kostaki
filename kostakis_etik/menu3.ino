void save_menu(){
  lcd.clear();
lcd.setCursor (0,0);
lcd.print("SAVE");
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-yes       no->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ){
      mode_save=true;
      lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-yes          ");
    }
    else { mode_save=false;
          lcd.setCursor (0,1);
//         0123456789012345
lcd.print("            no->");}
  }
}delay(bounce_time);
if (mode_save==true){
   EEPROM.put(0, length0);
    EEPROM.put(1, pause0);
     EEPROM.put(2, bottles);
}
}
void reset_menu(){
  lcd.clear();
lcd.setCursor (0,0);
lcd.print("RESET");
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-yes       no->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ){
      mode_reset=true;
      lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-yes          ");
    }
    else { mode_reset=false;
          lcd.setCursor (0,1);
//         0123456789012345
lcd.print("            no->");}
  }
}delay(bounce_time);
if (mode_reset==true){
   bottles = 0;
     EEPROM.put(2, bottles);
}
}
