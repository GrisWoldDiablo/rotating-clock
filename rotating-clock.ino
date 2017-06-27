/*
  DEMO: rotating clock

  TEAM a.r.g.: http://www.team-arg.com/demos.html

  2015 - JO3RI

  Demo License: MIT : https://opensource.org/licenses/MIT

*/

#include <Tinyfont.h>
#include <Arduino.h>
#include <Arduboy2.h>
#include "bitmaps.h"
#include <math.h>

Arduboy2 arduboy;
Tinyfont ArdTiny = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());


int a = 0;
int b = 0;
int c = 0;
float d = 0;
int m = 0;
unsigned long milliSecond = 100;
unsigned long lastMilliSecond = 100;
unsigned long lastSecond = 1000;
unsigned long secondInterval = 1000;
unsigned long lastMinute = 60000;
unsigned long minuteInterval = 60000;
unsigned long lastHour = 3600000;
unsigned long hourInterval = 3600000;


bool pressed = false;
String text;
String ab;

void setup() {
  //arduboy.begin();
	arduboy.boot();
  arduboy.clear();
  arduboy.display();
  //arduboy.drawBitmap(34, 4,  T_arg, 60, 56, WHITE);
  arduboy.display();
  arduboy.setFrameRate(15);
  //delay(3000);
}

void loop() {

	if (!arduboy.nextFrame())
	{
		return;
	}
  arduboy.clear();
  /*for (byte i = 1; i <= 12; i++) {
    arduboy.drawLine(63 + (30 * sin(d))*sin(-0 + 3.12 + ((6.28 / 12))*i), 31 + 30 * sin(0 + 4.72 + ((6.28 / 12))*i), 63 + (27 * sin(d))*sin(-0 + 3.12 + ((6.28 / 12))*i), 31 + 27 * sin(0 + 4.72 + ((6.28 / 12))*i), 1);
  }*/
  //arduboy.drawLine(63, 31, 63 + (20 * sin(d))*sin(-a + 3), 31 + 20 * sin(a + 4.7), 1);
  //arduboy.drawLine(64, 31, 64 + 16 * cosf((d-90)*PI / 180), 31 + 16 * sinf((d-90)*PI / 180), 1);

  arduboy.drawLine(64 + 16 * cosf((a * 6 - 90)*PI / 180), 31 + 16 * sinf((a * 6 - 90)*PI / 180), 64 + 19 * cosf((a * 6 - 90)*PI / 180), 31 + 19 * sinf((a * 6 - 90)*PI / 180), 1);
  arduboy.drawCircle(64 + 15 * cosf((a * 6 - 90)*PI / 180), 31 + 15 * sinf((a * 6 - 90)*PI / 180), 1);
  arduboy.drawLine(64, 31, 64 + 16 * cosf((b * 6 - 90)*PI / 180), 31 + 16 * sinf((b * 6 - 90)*PI / 180), 1);
  if (a % 2 == 0)
  {
	  arduboy.drawCircle(101, 31, 2);
  }
  else
  {
	  arduboy.drawCircle(101, 31, 3);
  }

  //arduboy.drawCircle(101, 31, 2);
  arduboy.drawCircle(101, 31, 7);
  arduboy.drawLine(101 + 0 * cosf((m * 36 - 90)*PI / 180), 31 + 0 * sinf((m * 36 - 90)*PI / 180), 101 + 7 * cosf((m * 36 - 90)*PI / 180), 31 + 7 * sinf((m * 36 - 90)*PI / 180), 1);


  //arduboy.drawCircle(64 + 12 * cosf((b * 6 - 90)*PI / 180), 31 + 12 * sinf((b * 6 - 90)*PI / 180), 1);
  //arduboy.drawTriangle(64 + 16 * cosf((b * 6 - 90)*PI / 180), 31 + 16 * sinf((b * 6 - 90)*PI / 180),
		//				64 + 13 * cosf((b * 6 - 98)*PI / 180), 31 + 13 * sinf((b * 6 - 98)*PI / 180),
		//				64 + 13 * cosf((b * 6 - 82)*PI / 180), 31 + 13 * sinf((b * 6 - 82)*PI / 180));
  arduboy.drawLine(64, 31, 64 + 10 * cosf((c * 30 - 90)*PI / 180), 31 + 10 * sinf((c * 30 - 90)*PI / 180), 1);
 // arduboy.drawCircle(64 + 8 * cosf((c * 30 - 90)*PI / 180), 31 + 8 * sinf((c * 30 - 90)*PI / 180), 1);
  //arduboy.drawTriangle(64 + 10 * cosf((c * 30 - 90)*PI / 180), 31 + 10 * sinf((c * 30 - 90)*PI / 180),
		//				64 + 7 * cosf((c * 30 - 105)*PI / 180), 31 + 7 * sinf((c * 30 - 105)*PI / 180),
		//				64 + 7 * cosf((c * 30 - 75)*PI / 180), 31 + 7 * sinf((c * 30 - 75)*PI / 180));
  
  for (int i = 1; i < 13; i++)
  {
	//arduboy.drawCircle(64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);
	//arduboy.drawLine(64 + 17 * cosf((i * 30 - 90)*PI / 180), 31 + 17 * sinf((i * 30 - 90)*PI / 180), 64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);
	
	ArdTiny.setCursor(64-2 + 18 * cosf((i * 30 - 90)*PI / 180), 31-2 + 18 * sinf((i * 30 - 90)*PI / 180));
	if (i == 10 || i == 12)
	{
		ArdTiny.setCursor(64 - 5 + 18 * cosf((i * 30 - 90)*PI / 180), 31 - 2 + 18 * sinf((i * 30 - 90)*PI / 180));
	}
	if (i == 3 || i == 6 || i == 9 || i == 12/* || i == 10 || i == 12*/)
	{
		ArdTiny.print(i);
	}
	else
	{
		arduboy.drawLine(64 + 17 * cosf((i * 30 - 90)*PI / 180), 31 + 17 * sinf((i * 30 - 90)*PI / 180), 64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);
	}

	  /*if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12)
	  {
		  arduboy.drawLine(64 + 16 * cosf((i * 30 - 90)*PI / 180), 31 + 16 * sinf((i * 30 - 90)*PI / 180), 64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);

	  }
	  else
	  {
		  //arduboy.drawPixel(64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);
		  arduboy.drawLine(64 + 18 * cosf((i * 30 - 90)*PI / 180), 31 + 18 * sinf((i * 30 - 90)*PI / 180), 64 + 19 * cosf((i * 30 - 90)*PI / 180), 31 + 19 * sinf((i * 30 - 90)*PI / 180), 1);

	  }*/
	//ArdTiny.print(i);
  }
  /*for (int i = 1; i < 61; i++)
  {
	  arduboy.drawPixel(64 + 23 * cosf((i * 6 - 90)*PI / 180), 31 + 23 * sinf((i * 6 - 90)*PI / 180));
  }*/
 

  //arduboy.drawLine(64, 31, 64 + (16 * sinf(d*PI / 120))*sinf(d*PI / 30), 31 + sinf(d*PI / 30), 1);
  //arduboy.drawLine(63, 31, 63 + (15 * sin(d))*sin(-b + 3), 31 + 15 * sin(b + 4.7), 1);
  //arduboy.drawLine(63, 31, 63 + (10 * sin(d))*sin(-c + 3), 31 + 10 * sin(c + 4.7), 1);

  if (millis() >= lastSecond) {
    a += 1;
    lastSecond += secondInterval;
	if (a >= 60)
	{
		a = 0;
		b++;
	}
	if (b >= 60)
	{
		b = 0;
		c++;
	}
	if (c >= 12)
	{
		c = 0;
	}
  }
  if (millis() >= lastMinute) {
    b += 1;
    lastMinute += minuteInterval;
  }
  if (millis() >= lastHour) {
    c += 1;
    lastHour += hourInterval;
  }

  if (arduboy.pressed(UP_BUTTON) && !pressed)
  {
	  //a += 0.105;
	  //b += 0.105;
	  c += 0.525;
	  d += 1;
	  a++;
	  //pressed = true;
	  if (a >= 60) 
	  {
		  a = 0;
		  b++;
		  //c++;
	  }
	  if (b >= 60)
	  {
		  b = 0;
		  c++;
	  }
	  if (c >= 12)
	  {
		  c = 0;
	  }
  }
  else if (arduboy.pressed(DOWN_BUTTON) && !pressed)
  {
	  d -= 1;
	  a--;
	  //pressed = true;
	  if (a <= 0)
	  {
		  a = 59;
		  b--;
		  //c--;
	  }
	  if (b <= 0)
	  {
		  b = 59;
		  c--;
	  }
	  if (c <= 0)
	  {
		  c = 12;
	  }
  }
  else if (arduboy.notPressed(UP_BUTTON) && arduboy.notPressed(DOWN_BUTTON))
  {
	pressed = false;
  }

  if (arduboy.pressed(UP_BUTTON) && arduboy.pressed(A_BUTTON))
  {
	  c++;
  }
  if (arduboy.pressed(UP_BUTTON) && arduboy.pressed(B_BUTTON))
  {
	  b++;
  }
  if (millis() >= lastMilliSecond) 
  {
	  m += 1;
	  lastMilliSecond += milliSecond;
  }
  if (m == 10)
  {
	  m = 0;
  }

  ab = sinf(d*PI / 60);
  text = c + String(":") + b + ":" + a;
  arduboy.setCursor(0, 0);
  arduboy.print(text);

  arduboy.display();
}
