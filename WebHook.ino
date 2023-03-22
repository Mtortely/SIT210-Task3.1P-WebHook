// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>

//labeling in-built LED as led
int led = D7; 
int analogvalue = 0;



void setup()
{
    Particle.variable("analogvalue", analogvalue);
 
    pinMode(A0, INPUT);
    pinMode(led, OUTPUT);
}


void loop()
{
    
    analogvalue = analogRead(A0) -3800 ; //-3800 to normalise as my sensor was working, but it was giving values up at that value.
    Particle.publish("Motion", String(analogvalue), ALL_DEVICES);
    //10second delay between reads, turns off led quickly to indicate next loop is about to start.
    digitalWrite(led, HIGH);
    delay(9900);
    digitalWrite(led, LOW);
    delay(100);
}
