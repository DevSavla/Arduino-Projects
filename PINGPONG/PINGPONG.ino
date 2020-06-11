#include <FastLED.h>
#define LED_PIN 5
#define n 28
const int  buttonPin = 7;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int ch=1;
int i=0;
CRGB leds[n];

void new_colour(int r, int g, int b)
{
  for(i=0; i<=28; i++)
  {
      leds[i] = CRGB (r, g, b);
  } 
   FastLED.show();
}

void setup() 
{
  pinMode(buttonPin, INPUT);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, n);
  for(i=0; i<=28; i++)
  {
    leds[i] = CRGB (0, 0, 0);
  }  
  Serial.begin(9600);
  
}

void loop() 
{
    buttonState = digitalRead(buttonPin);

    // compare the buttonState to its previous state
    if (buttonState != lastButtonState) 
    {
        // if the state has changed, increment the counter
        if (buttonState == HIGH) 
        {
            // if the current state is HIGH then the button went from off to on:
            buttonPushCounter++;
            Serial.println("on");
            Serial.print("number of button pushes: ");
            Serial.println(buttonPushCounter);
         }
         else
         {
             // if the current state is LOW then the button went from on to off:
             Serial.println("off");
         }
          
         // Delay a little bit to avoid bouncing
         delay(50);
      }
      // save the current state as the last state, for next time through the loop
      lastButtonState = buttonState;
    
      if(buttonPushCounter==4)
      {
        for(i=0; i<=28; i++)
        {
           leds[i] = CRGB (100, 255, 255);
        } 
        FastLED.show();
        buttonPushCounter=1;
      }
    
      if(buttonPushCounter==1)
      {
         for(i=0; i<=28; i++)
        {
           leds[i] = CRGB (100, 255, 255);
        } 
        FastLED.show();
        buttonPushCounter=1;
      }

      if(buttonPushCounter==2)
      {
        for(i=0; i<=28; i++)
        {
           leds[i] = CRGB (200, 255, 255);
        } 
        FastLED.show();
        buttonPushCounter=2;
      }

      if(buttonPushCounter==3)
      {
         for(i=0; i<=28; i++)
        {
           leds[i] = CRGB (255, 255, 255);
        } 
        FastLED.show();
        buttonPushCounter=3;
      }
}
