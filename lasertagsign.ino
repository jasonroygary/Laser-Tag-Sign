int ledPin = 4;                // LED connected to digital pin
int redPin1 = 9;
int greenPin1 = 10;
int bluePin1 = 11;
int iColor = 0;
int redPin2 = 3;
int greenPin2 = 5;
int bluePin2 = 6;
int iColor2 = 0;
int circlePins[] = {2, 7, 8, 12, 13, 14, 15, 16};
int cirLEDPin = 0;


int value = LOW;                // previous value of the LED
long previousMillis = 0;        // will store last time LED was updated
long previousMillis2 = 0;  
long previousMillisColor = 0;
long interval = 350;  
long interval2 = 40; 
long colorInterval = 5000;
int blinks = 0;                //number of blinks until change to new color

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  int i;
  for (i = 0; i < 8; i = i + 1) {
    pinMode(circlePins[i],OUTPUT);
    digitalWrite(circlePins[i],HIGH);
  }
  blue2();
  
  //Serial.begin(9600);
}
void loop()
{
  
  //Flashing Circle
  //  int i;
   //for (i = 0; i < 8; i = i + 1) {
    // digitalWrite(circlePins[i],LOW);
 // }
  int i;
   if (millis() - previousMillis2 > interval2) {
    previousMillis2 = millis(); 
      for (i = 0; i < 8; i = i + 1) {
    pinMode(circlePins[i],OUTPUT);
    digitalWrite(circlePins[i],HIGH);
  }
    digitalWrite(circlePins[cirLEDPin],LOW);
    cirLEDPin = cirLEDPin + 1;
    if (cirLEDPin > 8) 
    {
      cirLEDPin = 0;
      iColor2 = iColor2 + 1;
       if (iColor2 == 0) 
       {
       red2();
       }
       else if (iColor2 == 1)
       {
       green2();  
       }  
       else if (iColor2 == 2)
       {
       blue2();
       }  
       else
       {
       white2();
       } 
  }
    } 
    if (iColor2==4) {
   iColor2 = 0; 
    }
  
  if (millis() - previousMillis > interval) {
    previousMillis = millis();   // remember the last time we blinked the LED

    // if the LED is off turn it on and vice-versa.
    if (value == LOW)
      value = HIGH;
    else
      value = LOW;

    digitalWrite(ledPin, value);
    blinks = blinks + 1;
  }
  //Color Interval
  if (blinks == 4) {
       if (iColor == 0) 
       {
       red();
       }
       else if (iColor == 1)
       {
       green();  
       }  
       else if (iColor == 2)
       {
       blue();
       }  
       else
       {
       white();
       } 
       iColor = iColor + 1;
       blinks = 0;
  }
  if (iColor==4) {
   iColor = 0; 
  }
}
//COLOR FUNCTIONS
void white() {
    analogWrite(redPin1,255);
    analogWrite(greenPin1,0);
    analogWrite(bluePin1,255); 
}
void red() {
    analogWrite(redPin1,255);
    analogWrite(greenPin1,0);
    analogWrite(bluePin1,0);
}
void blue() {
    analogWrite(redPin1,0);
    analogWrite(greenPin1,0);
    analogWrite(bluePin1,255);
}
void green() {
    analogWrite(redPin1,0);
    analogWrite(greenPin1,255);
    analogWrite(bluePin1,0);
}
//COLOR FUNCTIONS
void white2() {
    analogWrite(redPin2,255);
    analogWrite(greenPin2,0);
    analogWrite(bluePin2,255); 
}
void red2() {
    analogWrite(redPin2,255);
    analogWrite(greenPin2,0);
    analogWrite(bluePin2,0);
}
void blue2() {
    analogWrite(redPin2,0);
    analogWrite(greenPin2,0);
    analogWrite(bluePin2,255);
}
void green2() {
    analogWrite(redPin2,0);
    analogWrite(greenPin2,255);
    analogWrite(bluePin2,0);
}
