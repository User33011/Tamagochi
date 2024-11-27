void game_setup(){
  button.flag = false;
  srand(time(0));
  int level = 0;
  int score = 0;
  game_loop(level, score);
}

void game_loop(int level, int score) {
  button.A = digitalRead(BUTTON_A);
  button.B = digitalRead(BUTTON_B);
  button.C = digitalRead(BUTTON_C);
  button.D = digitalRead(BUTTON_D);

  game.ballX += game.ballXSpeed;
  game.ballY += game.ballYSpeed;
  
  if (level < sizeof(scoreLevels) / sizeof(scoreLevels[0]) && score == scoreLevels[level]) {
    game.ballXSpeed--;
    game.ballYSpeed--;
    level++;
  }
  
  if (game.ballX <= 0 || game.ballX >= SCREEN_WIDTH - game.ballSize) {
    game.ballXSpeed = -game.ballXSpeed;
  }
  if (game.ballY <= 10) {
    game.ballYSpeed = -game.ballYSpeed;
  }

  if (game.ballY >= game.paddleY - game.ballSize && game.ballX >= game.paddleX && game.ballX <= game.paddleX + game.paddleWidth) {
  //  game.ballYSpeed = -game.ballYSpeed;
    game.ballXSpeed += (rand() %3 + 1);
    score++;

  }
  oled.clear();
 
  // Рисуем ракетку
  oled.roundRect(game.paddleX, game.paddleY, game.paddleX + game.paddleWidth, game.paddleY + game.paddleHeight, OLED_STROKE);
 
  // Рисуем мяч
  oled.circle(game.ballX, game.ballY, game.ballSize, OLED_FILL);
 
  // Отображаем счёт
  oled.setScale(1);
  oled.setCursor(0, 0);
  oled.print("Счёт:");
  oled.print(score);
  oled.setCursor(70, 0);
  oled.print("Уровень:");
  oled.print(level);
  oled.update();

  if (!button.C && game.paddleX -2 > 0) {
    game.paddleX -= 4;
  }
  if (!button.D && game.paddleX +2 < SCREEN_WIDTH - game.paddleWidth) {
    game.paddleX += 4;
  }

  if (game.ballY >= SCREEN_HEIGHT - 4) {
    saveScore(score); // Завершение игры
  }
  else {
  game_loop(level, score);
  }
}


void resetGame() {
  oled.clear();
  game.paddleX = SCREEN_WIDTH / 2 - game.paddleWidth / 2;  // Начальная позиция ракетки
  game.paddleY = SCREEN_HEIGHT - game.paddleHeight - 2;      // Позиция ракетки
  game.ballX = SCREEN_WIDTH / 2;                      // Х координата мяча
  game.ballY = SCREEN_HEIGHT / 2;                     // Y координата мяча
  game.ballXSpeed = -1;                               // Скорость мяча по X
  game.ballYSpeed = -1;                               // Скорость мяча по Y   
  game_loop(0, 0);
}

void saveScore(int score) {
  tama.timer = millis();
  tama.game = tama.game + score;
  score = 0;
  while(millis() - tama.timer < 3000) {
    oled.clear();
    oled.setScale(3);
    oled.setCursor(30, 0);
    oled.print("GAME");
    oled.setScale(3);
    oled.setCursor(30, 4);
    oled.print("OVER");
    oled.update();
  }
  while(true) {
    button.A = digitalRead(BUTTON_A);
    button.B = digitalRead(BUTTON_B);
    oled.clear();
    oled.setScale(1);
    oled.setCursor(0, 0);
    oled.print("Очки:");
    oled.setCursor(29, 0);
    oled.print(tama.game);
    oled.setCursor(0, 1);
    oled.print("A - выход");
    oled.setCursor(0, 2);
    oled.print("В - повторить");

    oled.update();

    if (!button.A && !button.flag && millis() - button.timer > 100) {
      button.flag = true;
      button.timer = millis();
    break;
    }
    else if (!button.B && !button.flag && millis() - button.timer > 100) {
      button.flag = true;
      button.timer = millis();
      resetGame();
    break;
    } else {
      button.flag = false;
      button.timer = millis();
    }
  }
}
