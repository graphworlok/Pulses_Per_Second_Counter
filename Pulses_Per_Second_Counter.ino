volatile int IRQcount;
int pin = 2;
int pin_irq = 0; //IRQ that matches to pin 2
unsigned long previousMicros = 0;        // will store last time LED was updated
long minMicros = 32767;
long maxMicros = 0;
long myMicros = 0;
long oldMicros = 0;
long totalMicros = 0;
int small = 0;
int big = 0;
// constants won't change :
const long interval = 1000000;           // interval at which to blink (microseconds)

void setup() {
  // put your setup code here, to run once:
  Serial.begin (57600);
  attachInterrupt(pin_irq, IRQcounter, RISING);
}

void IRQcounter() {
  IRQcount++;
  //myMicros = (micros() - oldMicros);
  //if ( myMicros > maxMicros ) {
  //    maxMicros = myMicros;
  //}
  //if ( myMicros < minMicros) {
  //  minMicros = myMicros;
  //}
  //if (myMicros < 20000) {
  //  small++;
  //}
  //if (myMicros > 50000) {
  //  big++;
  //}
  //totalMicros = (totalMicros + myMicros);
  //oldMicros = micros();
  
}


void loop() {
    unsigned long currentMicros = micros();
 

  if(currentMicros - previousMicros >= interval) {
    previousMicros = currentMicros;   
  cli();//disable interrupts
  int result = IRQcount;
  
  //Serial.print(F(" Count = "));
  //Serial.print(result);
  //Serial.print(F(" Max = "));
  //Serial.print(maxMicros);
  //Serial.print(F(" Min = "));
  //Serial.print(minMicros);
  //Serial.print(F(" Small = "));
  //Serial.print(small);
  //Serial.print(F(" Big = "));
  //Serial.print(big);
  //Serial.print(F(" Av = "));
  Serial.print("Rise");
  Serial.println((interval/result));
  IRQcount = 0;
  totalMicros = 0;
  //big=0;
  //small=0;
  sei();//enable interrupts

  }
}
