/*ISR(PCINT2_vect) {
  unsigned char result = r_int.process();
  if (result == DIR_NONE) {
    // do nothing
   }
 else if (result == DIR_CW) {
    l = l+1;
  }
  else if (result == DIR_CCW) {
    l = l-1;
  }
  Serial.println(l);
}*/

void flag() {
   l = l+1;
  //  Serial.println(l);
}
