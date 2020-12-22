/* Yasmin Kullab 
 This Code explains a controlled software and hardware component based 
 system to manage a Smart Office, this project includes managing heating and cooling.
 */


#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // numbers of the interface pins
const int REDLED = 8;                  // Heat
const int BLUELED = 13;                	// Cool
float temp= 0;	                       // temperature in degrees
int time; 
const int tPin = 0;
double Voltage;                               
float AC;         
                             

void setup()
{
  Serial.begin(9600);
  pinMode (REDLED,OUTPUT);
  pinMode (BLUELED,OUTPUT);
  lcd.begin(16,2); 
  //lcd.print("24 degrees C");
}


void loop()
{
  lcd.clear();
  
  temp = analogRead(A0);
  
  Voltage = tPin*0.0048828125;
  
  
  lcd.setCursor(0,0); 
  
  Serial.println(temp);
    Serial.println(" Celcius");
  lcd.print(temp); 
  lcd.print(" Celcius");
  lcd.setCursor(8,0);
  
  delay(1000);
  
  if ( temp > 20 )
  {
    digitalWrite(REDLED,HIGH);
    digitalWrite(BLUELED,LOW);
}
   else if ( temp < 28)
  {
    digitalWrite(BLUELED,HIGH);
    digitalWrite(REDLED,LOW);
  }
  else 
  {
    digitalWrite(BLUELED,LOW);
    digitalWrite(REDLED,LOW); 
} 
}
