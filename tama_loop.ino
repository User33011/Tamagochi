void tama_loop() { 
  sensor_read();  
  tama.sleep--;
  tama.food--; 

  if (tama.food <= 0) {
    tama.food = 1;
  }

  if(tama.food > 60){
      resetSpecificState(HUNGRY);
  }
  if(ST_SLEEPING && tama.sleep > 60){
      resetSpecificState(SLEEPY);
  }
  if(tama.sleep < 20){
      updateActiveStates(SLEEPY);
  }
  if(tama.food < 20){
      updateActiveStates(HUNGRY);
  }


	switch (tama.state) {
	case ST_HAPPY:
		if (sensor.humidity <= 60 && sensor.temperat > 21 && sensor.light < 170 || tama.sleep <= 20) {
			tama.state = ST_OK;
		}
    if(tama.food < 40){
      tama.state = ST_OK;
    }
		if (sensor.light > 170 && !tama.flag) {
			tama.state = ST_SLEEPING;
		}
		if (sensor.temperat <= 21) {
			tama.state = ST_SAD;
		}
    if (tama.sleep <= 20 && !tama.flag) {
      tama.state = ST_OK;
    }
		break;
	case ST_OK:
		if (sensor.humidity >= 60 && sensor.temperat > 21 && sensor.light < 170 && tama.sleep >= 20) {
			tama.state = ST_HAPPY;
		}
    if(tama.food < 10){
      tama.state = ST_SAD;
    }
		if (sensor.light > 170 && !tama.flag) {
			tama.state = ST_SLEEPING;
		}
		if (sensor.temperat <= 21) {
			tama.state = ST_SAD;
		}
    if (tama.sleep <= 0 && !tama.flag) {
      tama.timer = millis();
      tama.state = ST_SAD;
    }
		break;
	case ST_SAD:
		if (sensor.light > 170 && !tama.flag) {
			tama.state = ST_SLEEPING;
		}
    if (sensor.light < 170 && tama.sleep > 0) {
			tama.state = ST_OK;
		}
    if (millis() - tama.timer > 10000 && tama.sleep <= 0){
      tama.timer = millis();
      tama.flag = true;
      tama.state = ST_SLEEPING;
    }
		break;
	case ST_SLEEPING:
    if (tama.sleep < 99 && tama.flag) {
			tama.sleep++;
    }
    if (tama.sleep < 99 && sensor.light > 170 && !tama.flag) {
			tama.sleep++;
		}
  	if (sensor.light < 170 && tama.sleep > 0 && !tama.flag) {
			tama.state = ST_OK;
		}
    if (tama.sleep >= 99 && tama.flag) {
      tama.flag = false;
			tama.state = ST_OK;
		}
    if (sensor.humidity >= 60 && sensor.temperat > 21 && sensor.light < 170 && tama.sleep >= 20 && !tama.flag) {
			tama.state = ST_HAPPY;
		}
		break;
  }
}