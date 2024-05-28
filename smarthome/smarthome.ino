

#include <OneSheeld.h>

const char on[] = "all on";
const char off[] = "all of";
const char bedon[]="bed lights on";
const char bedoff[]="bed lights off";
const char hallon[]="hall lights on";
const char halloff[]="hall lights off";
const char kitchenon[]="kitchen lights on";
const char kitchenoff[]="kitchen lights off";
const char alarmon[]="alaram on";
const char alarmoff[]="alaram off";
int green = 2; //Connect green LED  To Pin #2
int yellow = 3; //Connect yellow To Pin #3
int red = 4; //Connect red To Pin #4
int alarm = 5; //Connect servo To Pin #5

void allon(){
     digitalWrite(green, HIGH);
     digitalWrite(yellow, HIGH);
     digitalWrite(red, HIGH);
     digitalWrite(alarm, HIGH);
     
}
void alloff(){
     digitalWrite(green, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(red, LOW);
     digitalWrite(alarm, LOW);
     
}
void setup()
{
  OneSheeld.begin();
  VoiceRecognition.setOnError(error);
  VoiceRecognition.start();
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(alarm, OUTPUT);
  digitalWrite(green, HIGH);  // Active Low
  digitalWrite(yellow, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(alarm, HIGH);
}

void loop () 
{
  if(VoiceRecognition.isNewCommandReceived())
  {
    if (!strcmp(off,VoiceRecognition.getLastCommand()))
    {
      alloff();
    }
    else if(!strcmp(on,VoiceRecognition.getLastCommand()))
    {
      allon();
    }
     else if(!strcmp(alarmon,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(alarm, HIGH);
    }
    else if(!strcmp(alarmoff,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(alarm, LOW);
    }
     else if(!strcmp(bedon,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(green, HIGH);
    }
    else if(!strcmp(bedoff,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(green, LOW);
    }
  else if(!strcmp(hallon,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(yellow, HIGH);
    }
    else if(!strcmp(halloff,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(yellow, LOW);
    }
      else if(!strcmp(kitchenon,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(red, HIGH);
    }
    else if(!strcmp(kitchenoff,VoiceRecognition.getLastCommand()))
    {
     digitalWrite(red, LOW);
    }
  }
}

void error(byte errorData)
{
  switch(errorData)
  {
  case NETWORK_TIMEOUT_ERROR: 
    Terminal.println("Network timeout");
    break;
  case NETWORK_ERROR: 
    Terminal.println("Network Error");
    break;
  case AUDIO_ERROR: 
    Terminal.println("Audio error");
    break;
  case SERVER_ERROR: 
    Terminal.println("No Server");
    break;
  case SPEECH_TIMEOUT_ERROR: 
    Terminal.println("Speech timeout");
    break;
  case NO_MATCH_ERROR: 
    Terminal.println("No match");
    break;
  case RECOGNIZER_BUSY_ERROR: 
    Terminal.println("Busy");
    break;
  }
}

