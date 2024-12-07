//Németh János
//neptun kód: E4D8ZM

const int buzzerPin =  26;      // tűk (pin) inicializálása (mozgásérzékelő és piezo hangjelző (buzzer) részére
const int motionSensor = 27;


unsigned long previousMillis = 0;        // tárolja a buzzer legutóbbi bekapcsolását
unsigned long currentMillis;
const long interval = 3000;           // interval beállítsáa (milliseconds)

void setup() {
   Serial.begin(115200);            
  // set the digital pin as output:
  pinMode(buzzerPin, OUTPUT);
  pinMode(motionSensor, INPUT);
}

void loop() 
{
  // futó kód
  int reading = digitalRead(motionSensor);
  if (reading == HIGH)
  {digitalWrite(buzzerPin,HIGH);
   Serial.println("Mozgás érzékelve! Buzzer bekapcsolása!");
   previousMillis = millis();
  }
  else{
  currentMillis = millis();
   if (currentMillis - previousMillis >= interval) 
   {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Buzzer kikapcsolása!");
    }
  }
}
