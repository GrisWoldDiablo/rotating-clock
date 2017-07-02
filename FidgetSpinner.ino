/*
  DEMO: rotating clock

  TEAM a.r.g.: http://www.team-arg.com/demos.html

  2015 - JO3RI

  Demo License: MIT : https://opensource.org/licenses/MIT

*/


#include <Arduboy2.h>
Arduboy2 arduboy;
int a = 0;

unsigned long lastSecond = 1000;
unsigned long secondInterval = 1000;



void setup() 
{
	arduboy.begin();
	arduboy.flashlight();
	arduboy.setFrameRate(60);
}

void loop() 
{

	if (!arduboy.nextFrame())
	{
		return;
	}
	arduboy.clear();

	for (size_t i = 1; i < 4; i++)
	{
		arduboy.drawCircle(64 + 22 * cosf((i * 120 - (a * 6))*PI / 180), 31 + 22 * sinf((i * 120 - (a * 6))*PI / 180), 8);
		arduboy.drawCircle(64 + 22 * cosf((i * 120 - (a * 6))*PI / 180), 31 + 22 * sinf((i * 120 - (a * 6))*PI / 180), 3);
		arduboy.drawCircle(64 + 11 * cosf((i * 120 - (a * 6))*PI / 180), 31 + 11 * sinf((i * 120 - (a * 6))*PI / 180), 3);
	}
	arduboy.drawCircle(64, 31, 7);
	arduboy.drawCircle(64, 31, 3);

	 if (millis() >= lastSecond) 
	 {
		a += 1;
		lastSecond += secondInterval;
		if (a >= 60)
		{
			a = 0;
		}
	}

	if (arduboy.pressed(UP_BUTTON))
	{
		a++;
		if (arduboy.pressed(A_BUTTON))
		{
			a += 1;
		}
		if (arduboy.pressed(B_BUTTON))
		{
			a += 2;
		}
		if (a >= 60) 
		{
			a = 0;
		}
		if (a <= 30)
		{
			arduboy.setRGBled(0, 1, 0);
		}
		else
		{
			arduboy.setRGBled(0, 0, 0);
		}

	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		a--;
		if (arduboy.pressed(A_BUTTON))
		{
			a -= 1;
		}
		if (arduboy.pressed(B_BUTTON))
		{
			a -= 2;
		}
		if (a <= 0)
		{
			a = 59;
		}
		if (a <= 30)
		{
			arduboy.setRGBled(1, 0, 0);
		}
		else
		{
			arduboy.setRGBled(0, 0, 0);
		}
	}
	else
	{
		arduboy.setRGBled(0, 0, 0);
	}
	

	arduboy.display();
}
