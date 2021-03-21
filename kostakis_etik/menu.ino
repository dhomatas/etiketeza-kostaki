byte setup_menu(){
  lcd.clear();
  byte i = 0;
lcd.setCursor (0,0);
lcd.print("SETUP");
mark1: 
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-");
lcd.setCursor (6,1);
lcd.print (m[i]);
lcd.setCursor (14,1);
lcd.print("->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ) { 
      if( i>0)i=i-1;
      else i=menu_items;
      }
    else {
      if (i<menu_items)i=i+1;
      else i = 0;
    }
    lcd.setCursor (0,1);lcd.print("                ");
    goto mark1;
  }
}delay(bounce_time);
return i;
}









void menu_auto(){
  lcd.clear();
lcd.setCursor (0,0);
lcd.print("MODE");
lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-auto  manual->");

while ( digitalRead(rotary_switch)== HIGH){

   unsigned char result = r.process();
  if (result) {
    if (result == DIR_CCW ){
      mode_auto=true;
      lcd.setCursor (0,1);
//         0123456789012345
lcd.print("<-auto          ");
    }
    else { mode_auto=false;
          lcd.setCursor (0,1);
//         0123456789012345
lcd.print("        manual->");}
  }
}delay(bounce_time);
}
