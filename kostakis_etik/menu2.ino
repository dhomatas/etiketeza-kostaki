void length_menu(){
  lcd.clear();
lcd.setCursor (0,0);
lcd.print("LENGTH");
mark1: 
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-");
lcd.setCursor (6,1);
lcd.print (length0);
lcd.setCursor (14,1);
lcd.print("->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ) { 
      if( length0>0)length0=length0-1;
      }
    else {
      if (length0<255)length0=length0+1;
     
    }
    lcd.setCursor (0,1);lcd.print("                ");
    goto mark1;
  }
}delay(bounce_time);
}

void pause_menu(){
  lcd.clear();
lcd.setCursor (0,0);
lcd.print("PAUSE");
mark1: 
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-");
lcd.setCursor (6,1);
lcd.print (pause0);
lcd.setCursor (14,1);
lcd.print("->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ) { 
      if( pause0>0)pause0=pause0-1;
      }
    else {
      if (pause0<255)pause0=pause0+1;
     
    }
    lcd.setCursor (0,1);lcd.print("                ");
    goto mark1;
  }
}delay(bounce_time);
}
