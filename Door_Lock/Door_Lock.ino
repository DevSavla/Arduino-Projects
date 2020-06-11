#include <Keypad.h>
#include "U8glib.h"

U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);  // D0=13, D1=11, CS=10, DC=9, Reset=8

char password[3]= "123";  // change the password here, just pick any 3 numbers
int position = 0;
char attempt[3];
int i=0;

const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {14, 15, 16,17}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {18, 19, 20, 21}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup(){
Serial.begin(9600);
}

/*void draw()
{

}*/

void loop()
{
u8g.setFont(u8g_font_unifont);  // select font

  u8g.firstPage();  
  do {
      u8g.drawStr(20, 10, "Dev's Den");  // put string of display at position X, Y
  u8g.drawStr(0, 20, "Enter password !");
  } while( u8g.nextPage() );

  char key=customKeypad.getKey();  
  
  if (key == '*' || key == '#')
  {
    position = 0;
    u8g.firstPage();  
    do 
    {
      u8g.drawStr(30, 40, "Locked");
      u8g_Delay(400);
    }while( u8g.nextPage() );
    
  }

  if(key)
  {
    attempt[i++]=key;
    
    u8g.firstPage();  
    do 
    {
      u8g.setPrintPos(0, 40);
      u8g.print(key, 0);  // display humidity from DHT11
      u8g_Delay(100);
    }while( u8g.nextPage() );
  }

  if(i==3)
  {
    if(!(strncmp(attempt,password,3)))
    {
      u8g.firstPage();  
      do 
      {
        u8g.drawStr(0,40,"Correct Password");
        u8g_Delay(200);
      }while( u8g.nextPage() );
    }

    else
    {
      u8g.firstPage();  
      do 
      {
        u8g.drawStr(0,40,"Incorrect Password");
        u8g_Delay(200);
      }while( u8g.nextPage() );
    }
    i=0;
  } 
}
