void tama_loop() {
    // Считываем сенсоры
    sensor_read();  
    
    // Уменьшаем каждый из показателей
    tama.sleep--;
    tama.food--;
    tama.water--;
    tama.game--;
    tama.shit--;
    tama.day++;
    // Возраст
    if (tama.day >= 365) tama.age++;
    // Защита от отрицательных значений
    if (tama.sleep <= 0) tama.sleep = 0; 
    if (tama.food <= 0) tama.food = 0; 
    if (tama.water <= 0) tama.water = 0; 
    if (tama.health <= 0) tama.health = 0; 
    if (tama.game <= 0) tama.game = 0; 
    if (tama.shit <= 0) tama.shit = 0;
    // Защита от превышения
    if (tama.sleep >= 99) tama.sleep = 99; 
    if (tama.food >= 99) tama.food = 99; 
    if (tama.water >= 99) tama.water = 99; 
    if (tama.health >= 100) tama.health = 100; 
    if (tama.game >= 99) tama.game = 99; 
    if (tama.shit >= 99) tama.shit = 99;

    // Рассчитываем коэффициент счастья
    // Уменьшение счастья из-за нехватки еды, воды и сна
    tama.happiness -= (20 - tama.food) > 0 ? (20 - tama.food) * 2 : 0; // Уменьшение из-за еды
    tama.happiness -= (20 - tama.shit) > 0 ? (20 - tama.shit) * 3 : 0; // Уменьшение из-за туалета
    tama.happiness -= (20 - tama.water) > 0 ? (20 - tama.water) * 2 : 0; // Уменьшение из-за воды
    tama.happiness -= (20 - tama.sleep) > 0 ? (20 - tama.sleep) * 3 : 0; // Уменьшение из-за сна
    tama.happiness -= (20 - tama.game) > 0 ? (20 - tama.game) : 0; // Уменьшение из-за игры
    tama.happiness -= (40 - tama.health) > 0 ? (40 - tama.health) : 0; // Уменьшение из-за здоровья

    // Проверка состояния питомца
    if (tama.sleep == 0) {
        tama.state = ST_SLEEPING; // Если нет очков сна
    } else if (tama.happiness >= 80) {
        tama.state = ST_HAPPY;    // Питомец счастлив
    } else if (tama.happiness < 50 || tama.health < 50) {
        tama.state = ST_SAD;      // Питомец грустит
    } else {
        tama.state = ST_OK;       // Питомец в норме
    }

    // Логика изменения здоровья
    if (tama.food < 30 || tama.water < 30 || tama.sleep < 30 || tama.shit < 40 || tama.game < 5) {
        tama.health -= 1; // Ухудшение здоровья
    }
    if (ST_SLEEPING) {
        tama.sleep ++;    // Добавление очков сна
    }
    if (tama.shit < 40 && !tama.ShitFlag){ 
      updateActiveStates(SHIT);
      tama.ShitFlag = true;
    } 
    if (tama.shit >= 95 && tama.ShitFlag){
      resetSpecificState(SHIT);
    }

    if (tama.food < 40){ 
      updateActiveStates(HUNGRY);
    } else {
      resetSpecificState(HUNGRY);
    }
  
    if (tama.water < 40){ 
      updateActiveStates(THIRSTY);
    } else {
      resetSpecificState(THIRSTY);
    }

    if (tama.sleep < 20){ 
      updateActiveStates(SLEEPY);
    } else {
      resetSpecificState(SLEEPY);
    }

    if (tama.health < 40){ 
      updateActiveStates(HEALTH);
    } else {
      resetSpecificState(HEALTH);
    }

    if (tama.game < 20){ 
      updateActiveStates(PLAY);
    } else {
      resetSpecificState(PLAY);
    }
}
