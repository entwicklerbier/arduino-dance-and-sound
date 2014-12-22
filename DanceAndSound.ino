//original Source: https://gist.github.com/tagliati/1804108

#include <Servo.h>

Servo myServo; 
//use the servo library

int ledPin = 13;
//led for visualization (use 13 for built-in led)

int marchPin = 2;
// startbutton for march connected to port 2
int jingleBellsPin = 7;
// startbutton for jingle bells connected to port 7
int speakerPin = 11;
//speaker connected to one of the PWM ports

int range = 20;
//angle in grad to move the servo
int neutral = 90;
//center position of servo

int left = neutral - range/2;
int right = neutral + range/2;

int is_left = true;
//servo position

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
//frequencies for the tones we're going to use
//used http://home.mit.bme.hu/~bako/tonecalc/tonecalc.htm to get these



void setup() 	 
{ 	 
  myServo.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(marchPin, INPUT); 
  pinMode(jingleBellsPin, INPUT); 	
  
} 	 

void loop() 	// run over and over again
{

  myServo.write(neutral);
  digitalWrite(ledPin, LOW);
  if (digitalRead(marchPin) == HIGH){
    digitalWrite(ledPin, HIGH);
    march();
  }
  else 
  if (digitalRead(jingleBellsPin) == HIGH){
    digitalWrite(ledPin, HIGH);
    jingle_bells();
  }
  delay(100);
} 	 

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
  // swing the servo between right and left
  myServo.write(is_left?left:right);
  is_left = !is_left;

  int x; 	 
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++) 	 
  { 	 
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin,LOW);
    delayMicroseconds(delayAmount);
  } 	 

  delay(20);
  //a little delay to make all notes sound separate
} 	 

void jingle_bells()
{
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 500); 
  
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 500); 
  
  beep(speakerPin, e, 250); 
  beep(speakerPin, g, 250); 
  beep(speakerPin, c, 250); 
  beep(speakerPin, d, 250); 
  beep(speakerPin, e, 1000); 
  delay(250);
  
  
  beep(speakerPin, f, 250); 
  beep(speakerPin, f, 250); 
  beep(speakerPin, f, 250); 
  beep(speakerPin, f, 250); 
  beep(speakerPin, f, 250); 
  
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 250); 
  beep(speakerPin, e, 250);
  
  beep(speakerPin, d, 250); 
  beep(speakerPin, d, 250); 
  beep(speakerPin, e, 250); 
  beep(speakerPin, d, 500); 
  beep(speakerPin, g, 500); 
}

void march()
{ 	 
  //for the sheet music see:
  //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
  //this is just a translation of said sheet music to frequencies / time in ms
  //used 500 ms for a quart note

  beep(speakerPin, a, 500); 
  beep(speakerPin, a, 500); 
  beep(speakerPin, a, 500); 
  beep(speakerPin, f, 350); 
  beep(speakerPin, cH, 150);

  beep(speakerPin, a, 500);
  beep(speakerPin, f, 350);
  beep(speakerPin, cH, 150);
  beep(speakerPin, a, 1000);
  //first bit

  beep(speakerPin, eH, 500);
  beep(speakerPin, eH, 500);
  beep(speakerPin, eH, 500);    
  beep(speakerPin, fH, 350); 
  beep(speakerPin, cH, 150);

  beep(speakerPin, gS, 500);
  beep(speakerPin, f, 350);
  beep(speakerPin, cH, 150);
  beep(speakerPin, a, 1000);
  //second bit...

  beep(speakerPin, aH, 500);
  beep(speakerPin, a, 350); 
  beep(speakerPin, a, 150);
  beep(speakerPin, aH, 500);
  beep(speakerPin, gSH, 250); 
  beep(speakerPin, gH, 250);

  beep(speakerPin, fSH, 125);
  beep(speakerPin, fH, 125);    
  beep(speakerPin, fSH, 250);
  delay(250);
  beep(speakerPin, aS, 250);    
  beep(speakerPin, dSH, 500);  
  beep(speakerPin, dH, 250);  
  beep(speakerPin, cSH, 250);  
  //start of the interesting bit

  beep(speakerPin, cH, 125);  
  beep(speakerPin, b, 125);  
  beep(speakerPin, cH, 250);      
  delay(250);
  beep(speakerPin, f, 125);  
  beep(speakerPin, gS, 500);  
  beep(speakerPin, f, 375);  
  beep(speakerPin, a, 125); 

  beep(speakerPin, cH, 500); 
  beep(speakerPin, a, 375);  
  beep(speakerPin, cH, 125); 
  beep(speakerPin, eH, 1000); 
  //more interesting stuff (this doesn't quite get it right somehow)

  beep(speakerPin, aH, 500);
  beep(speakerPin, a, 350); 
  beep(speakerPin, a, 150);
  beep(speakerPin, aH, 500);
  beep(speakerPin, gSH, 250); 
  beep(speakerPin, gH, 250);

  beep(speakerPin, fSH, 125);
  beep(speakerPin, fH, 125);    
  beep(speakerPin, fSH, 250);
  delay(250);
  beep(speakerPin, aS, 250);    
  beep(speakerPin, dSH, 500);  
  beep(speakerPin, dH, 250);  
  beep(speakerPin, cSH, 250);  
  //repeat... repeat

  beep(speakerPin, cH, 125);  
  beep(speakerPin, b, 125);  
  beep(speakerPin, cH, 250);      
  delay(250);
  beep(speakerPin, f, 250);  
  beep(speakerPin, gS, 500);  
  beep(speakerPin, f, 375);  
  beep(speakerPin, cH, 125); 

  beep(speakerPin, a, 500);            
  beep(speakerPin, f, 375);            
  beep(speakerPin, c, 125);            
  beep(speakerPin, a, 1000);       
  //and we're done \ó/    
}


