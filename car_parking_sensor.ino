
//CODE BY LUCKY YADAV FOR CAR PARKING SENSOR USING ARDUINO UNO




#include <NewPing.h> 

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#include <LiquidCrystal.h>
int RS=A5 ,E=A4, D4=A3, D5=A2, D6=A1, D7=A0;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // initialize the library with the numbers of the interface pins
int Buzzer = 13;
int val=0;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// Creating Charaters for Bar Graph and Reverse Mode Icon
byte Level0[8] = {
        0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111
};
byte Level1[8] = {
        0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};
byte Level2[8] = {
        0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};
byte Level3[8] = {
        0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};
byte NoLevel[8] = {
        0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};
byte R [8] = {
        0b11111,
    0b10000,
    0b10111,
    0b10101,
    0b10110,
    0b10101,
    0b10000,
    0b11111
};
byte B [8] = {
  
        0b11000,
    0b01000,
    0b01000,
    0b01000,
    0b01000,
    0b01000,
    0b01000,
    0b11000
};

void setup() 
{
  lcd.createChar(0, Level0);
  lcd.createChar(1, Level1);
  lcd.createChar(2, Level2);
  lcd.createChar(3, Level3);
  lcd.createChar(4, NoLevel);
  lcd.createChar(5, R);
  lcd.createChar(6, B);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows: 
  pinMode(Buzzer,OUTPUT); //Setup Buzzer pin as output pin
}

void loop() 
{
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  val=sonar.ping_cm();
  lcd.print(val);
  lcd.print("cm    ");
  lcd.setCursor(8, 1);
  lcd.write(byte(5));
  lcd.setCursor(9, 1);
  lcd.write(byte(6));
  lcd.setCursor(10, 1);
  lcd.print("Mode    ");
  
  
  if(val<=10&&val>0)
  {
    lcd.setCursor(0,0);
    digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
    lcd.print("******Stop******");
    lcd.setCursor(0,1);
    lcd.print("****************");
  
    
  }
  else if(val<=25&&val>10)
  {
  digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer off by making the voltage LOW
  delay(50);
  lcd.setCursor(0, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(1, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(2, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(3, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(5, 1);
  lcd.write(byte(2));
    lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));


  
  }
  else if(val<=50&&val>25)
  {
  digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
  delay(75);               // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer off by making the voltage LOW
  delay(75);               // wait for a second
  lcd.setCursor(0, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(1, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(2, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(3, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(5, 1);
  lcd.write(byte(2));
    lcd.setCursor(6, 1);
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));


  }
    else if(val<=75&&val>50)
  {
  digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer off by making the voltage LOW
  delay(100);  
 lcd.setCursor(0, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(1, 1); // bottom left
  lcd.write(byte(0));
  lcd.setCursor(2, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(3, 1); // bottom left
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(4));
  lcd.setCursor(5, 1);
  lcd.write(byte(4));
    lcd.setCursor(6, 1);
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));



  }
    else if(val<=100&&val>75)
  {
  digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer off by making the voltage LOW
  delay(200);  
lcd.setCursor(0, 1); // bottom leftlcd.setCursor(0, 1); // bottom left
  lcd.write(byte(0));lcd.write(byte(0));
  lcd.setCursor(1, 1); // bottom leftlcd.setCursor(1, 1); // bottom left
  lcd.write(byte(0));lcd.write(byte(0));
  lcd.setCursor(2, 1); // bottom left
  lcd.write(byte(4));
  lcd.setCursor(3, 1); // bottom left
  lcd.write(byte(4));
  lcd.setCursor(4, 1);
  lcd.write(byte(4));
  lcd.setCursor(5, 1);
  lcd.write(byte(4));
    lcd.setCursor(6, 1);
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));
  
  
  
  }
  
      else if(val<MAX_DISTANCE)
  {
            // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer off by making the voltage LOW
  lcd.setCursor(0, 1); // bottom leftlcd.setCursor(0, 1); // bottom left
  lcd.write(byte(4));lcd.write(byte(0));
  lcd.setCursor(1, 1); // bottom leftlcd.setCursor(1, 1); // bottom left
  lcd.write(byte(4));lcd.write(byte(0));
  lcd.setCursor(2, 1); 
  lcd.write(byte(4));
  lcd.setCursor(3, 1); 
  lcd.write(byte(4));
  lcd.setCursor(4, 1);
  lcd.write(byte(4));
  lcd.setCursor(5, 1);
  lcd.write(byte(4));
    lcd.setCursor(6, 1);
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));

  
  }
  
}

// End of Program
