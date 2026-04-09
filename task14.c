// library for the LCD display:
#include <LiquidCrystal.h>

LiquidCrystal lcd (4, 5, 10, 11, 12, 13);

int ledPin = 8;
int pir_sensor = 7;
int pir_reader;
int buzzer = 9;

void setup() 
{  
  pinMode(7,INPUT);               // For set the PIR signal pin as input mode
  pinMode(buzzer,OUTPUT);         // For set the Buzzer pin as OUTPUT mode
  pinMode(ledPin, OUTPUT);        //For set the led sihnal pin as output mode 
  
  lcd.begin(16, 2);                //Start the 16x2 LCD
  lcd.setCursor(2,0);              // Set the LCD Cursor using lcd.setCursor
  lcd.print("FINAL");              //Print the message on LCD
  lcd.setCursor(2,1);              //Again set the LCD cursor
  lcd.print("PROJECT!!");            //Again print the another message on different line
  delay(1000); //Set the delay
     lcd.clear();                  // clear the LCD
  
}

void loop()
{
   pir_reader = digitalRead(pir_sensor);    // Read the pir sensor using digitalRead function
  if (pir_reader ==1){                      //Use the if – else condition to trigger the action when the input is high
   digitalWrite(buzzer,HIGH);              //Set the pin HIGH of Buzze
   digitalWrite(ledPin, HIGH);             // turn LED ON
 
    lcd.setCursor(2,0);        //Set the cursor of LCD
 lcd.print("There is");     //Print the message on LCD
   lcd.clear();               //Clear the LCD
  lcd.setCursor(4,1);       //Set the cursor of LCD
 lcd.print("ERROR");        //Print the message on LCD

}
  else {                     //use the else condition
    digitalWrite(buzzer,LOW); //Set the pin low of Buzzer
    digitalWrite(ledPin,LOW);  // turn LED ON
 
    lcd.clear();                     //Clear the LCD
 lcd.setCursor(4,0);              //Set the cursor of LCD
 lcd.print("There is");          //Print the message on LCD
  lcd.setCursor(4,1);            //Set the cursor of LCD
 lcd.print("No ERROR");         //Print the message on LCD
  delay(500);                //Give a delay
  }

}  
  
