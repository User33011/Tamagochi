void tama_draw() {
  while(true){
  const int btnA = digitalRead(BUTTON_A);
  oled.clear();
  displayPetIcons();
  if(lifetimer >= 10000){
    lifetimer = 0;
    tama_loop();
  } 
	switch (tama.state) {
	case ST_HAPPY:
  oled.drawBitmap(0, 16, happy, 48, 48, BITMAP_NORMAL, BUF_ADD);
		break;
	case ST_OK:
  oled.drawBitmap(0, 16, mem, 48, 48, BITMAP_NORMAL, BUF_ADD);
		break;
	case ST_SAD:
  oled.drawBitmap(0, 16, sad, 48, 48, BITMAP_NORMAL, BUF_ADD);
		break;
	case ST_SLEEPING:
  oled.drawBitmap(0, 16, sleep, 48, 48, BITMAP_NORMAL, BUF_ADD);
		break;
	}
  oled.setCursorXY(1, 1); 
  oled.drawByte(0b00111000); 
  oled.drawByte(0b00111000); 
  oled.drawByte(0b11111110);                                                
    for (uint8_t i = 0; i < 10; i++) {                   
      if (i < 10 - sensor.voltage*2.0-0.1)
      oled.drawByte(0b10000010);   
      else 
      oled.drawByte(0b11111110);
    }
  oled.drawByte(0b11111110);

  oled.fastLineV(50, 0, 64);
  oled.fastLineH(10, 0, 50);

  oled.fastLineV(127, 0, 64);
  oled.fastLineH(50, 50, 127);

  oled.rect(0, 0, 127, 63, OLED_STROKE);
  
  oled.update();
  if (!btnA) break;
  }
}

