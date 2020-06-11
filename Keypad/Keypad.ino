#include <Keypad.h>

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
byte rowPins[ROWS] = {9, 8, 7, 6}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {5, 4, 3, 2}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
Serial.begin(9600);
}

void loop()
{
  char key=customKeypad.getKey();  
  
  if (key == '*' || key == '#')
  {
    position = 0;
    Serial.println("Locked");
  }


  if(key)
  {
    attempt[i++]=key;
    Serial.println(key);
  }

  if(i==3)
  {
    if(!(strncmp(attempt,password,3)))
    {
     Serial.println("Correct Password");
    }

    else
    {
      Serial.println("Incorrect Password");
    }
    i=0;
  }

  
  /*if (key == password[position])
  {
    position++;
  }
  
  if (position == 3)
  {
      Serial.println("Correct Password");
  }

  else
  {
    Serial.println("Incorrect Password");
  }

  delay(100);*/
}
