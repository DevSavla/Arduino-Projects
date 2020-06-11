int temp=A1;
int LED=5;
float value,mv,cel,farh;

void setup()
{
  Serial.begin(9600);
  pinMode(temp,INPUT);
  pinMode(temp,INPUT);
}

void loop()
{ 
  value=analogRead(temp);
  mv=(value/1024.0)*5000;
  cel=mv/10;
  farh=(cel*9)/5+32;
  
  Serial.print("\nTemperate is ");
  Serial.print(cel);
  Serial.print(" *C");

  if(cel>=26.00)
  {
    digitalWrite(LED,HIGH);
  }

  else
  {
    digitalWrite(LED,LOW);
  }

  delay(1000);
}
