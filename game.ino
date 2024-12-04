static int game_update_state()
{
  const int btnC = digitalRead(BUTTON_C);
  const int btnD = digitalRead(BUTTON_D);
  game.ballX += game.ballXSpeed;
  game.ballY += game.ballYSpeed;

  if (!btnC && game.paddleX -2 > 0) {
    game.paddleX -= 4;
  }
  else if (!btnD && game.paddleX +2 < SCREEN_WIDTH - game.paddleWidth) {
    game.paddleX += 4;
  }

  if (game.level < sizeof(scoreLevels) / sizeof(scoreLevels[0]) && game.score == scoreLevels[game.level]){

    game.ballXSpeed--;
    game.ballYSpeed--;
    game.level++;
  }

  if (game.ballX <= 0 || game.ballX >= SCREEN_WIDTH - game.ballSize) {
    game.ballXSpeed = -game.ballXSpeed;
  }

  if (game.ballY <= 10) {
    game.ballYSpeed = -game.ballYSpeed;
  }

  if (game.ballY >= game.paddleY - game.ballSize && game.ballX >= game.paddleX && game.ballX <= game.paddleX + game.paddleWidth) 
  {
    game.ballYSpeed = -game.ballYSpeed;
    game.ballXSpeed += (rand() %3 + 1);
    game.score++;
  }
  return game.ballY >= SCREEN_HEIGHT - 4;// Завершение игры
}

static void game_draw()
{
  
  oled.clear();

  // Рисуем ракетку
  oled.roundRect(game.paddleX, game.paddleY, game.paddleX + game.paddleWidth, game.paddleY + game.paddleHeight, OLED_STROKE);
 
  // Рисуем мяч
  oled.circle(game.ballX, game.ballY, game.ballSize, OLED_FILL);
 
  // Отображаем счёт
  oled.setScale(1);
  oled.setCursor(0, 0);
  oled.print("Счёт:");
  oled.print(game.score);
  oled.setCursor(70, 0);
  oled.print("Уровень:");
  oled.print(game.level);
  oled.update();
}

static int game_over_screen()
{

  tama.game = tama.game + game.score;
  if(tama.game > 99) tama.game = 99;

  for (int i = 0; i < 3; i++) {
	uint32_t tmr = millis();
	oled.clear();
	oled.setScale(3);
	oled.setCursor(30, 0);
	oled.print("GAME");
	oled.setScale(3);
	oled.setCursor(30, 4);
	oled.print("OVER");
	oled.update();
	while (millis() - tmr < 500);
	oled.clear();
	oled.update();
	while (millis() - tmr < 1000);
  }
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

  uint16_t btnA = 0, btnB = 0;
  while(true) {
    if (digitalRead(BUTTON_A))
	btnA++;
    else
	btnA = 0;

    if (digitalRead(BUTTON_B))
	btnB++;
    else
	btnB = 0;

    if (btnA > 100) {
	return 0;
    } else if (btnB > 100) {
	return 1;
    }
}
}

static void game_init()
{
	game.paddleX = SCREEN_WIDTH / 2 - game.paddleWidth / 2;    // Начальная позиция ракетки
	game.paddleY = SCREEN_HEIGHT - game.paddleHeight - 2;      // Позиция ракетки
	game.ballX = SCREEN_WIDTH / 2;                      // Х координата мяча
	game.ballY = SCREEN_HEIGHT / 2;                     // Y координата мяча
	game.ballXSpeed = -1;                               // Скорость мяча по X
	game.ballYSpeed = -1;                               // Скорость мяча по Y
	game.level = 0;
	game.score = 0;
}

void game_loop()
{
	do {
		game_init();
		while (!game_update_state())
			game_draw();
	} while (game_over_screen());
}
