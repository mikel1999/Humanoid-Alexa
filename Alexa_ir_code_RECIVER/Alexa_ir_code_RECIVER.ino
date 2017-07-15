/* 
source: www.electroschematics.com
You'll need to change the led pins and the codes 
accordingly to your configuration and IR remote
*/
 
#include <IRremote.h>
 
int RECV_PIN = 7; // the pin where you connect the output pin of TSOP4838
int led1 = 1;
/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */
#define code1  49215 // code received from button Rosu 
#define code2  41055 // code received from Verde
#define code3  24735 // code received from Albastru
#define code4 57375 // code alb 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);

}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
   Serial.println(value);
       if(value==code1)
          {     // if first led is on then
           // and set its state as off
                           // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
                delay(1000);// and set its state as on
                digitalWrite(led1, LOW);
          }
       
            // turn it off when button is pressed
            
        
    
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
