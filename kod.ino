// Pinler ve değişkeni tanımlama
int kirmizi= 13; 
int yesil = 12; 
int mavi = 11;
int buzzer = 10;
int gaz = A1;
int isik;
int yuzdederece;
const int isikdirenci = A2;

// Outputları ve inputları tanımlama
void setup() {
  pinMode(kirmizi, OUTPUT); 
  pinMode(yesil, OUTPUT); 
  pinMode(mavi, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(gaz, INPUT);
  pinMode(isikdirenci, INPUT);
  Serial.begin(9600); 
} 

// RGB led için basit renk değiştirme fonskiyonu
void renk(int kdeger, int ydeger, int mdeger) { 
  analogWrite(kirmizi, kdeger); 
  analogWrite(yesil, ydeger); 
  analogWrite(mavi, mdeger); 
}

// Ana döngü
void loop() { 
  isik = analogRead(isikdirenci);
  yuzdederece = (analogRead(0) * 100.0) / 1024; // Sıcaklık sensörünün outputunu % cinsine çevirme
  int analogSensor = analogRead(gaz);
  Serial.println("Gaz miktarı: "); 
  Serial.println(analogSensor);
  Serial.println("Sıcaklık: "); 
  Serial.println(yuzdederece); 
  if (isik > 25) {
        renk(0, 0, 0);
    noTone(buzzer); 
    }
    else {
        renk(255, 255, 255);
    if ((analogSensor >= 300 || yuzdederece >= 50) && (analogSensor <= 350 || yuzdederece <= 60)) { 
      renk(0, 0, 255);
      noTone(buzzer); 
    }
    else if ((analogSensor > 350 || yuzdederece > 60) && (analogSensor <= 400 || yuzdederece <= 70)) {
      renk(0, 255, 0);
      noTone(buzzer); 
    }
    else if (analogSensor > 400 || yuzdederece > 70) {
      renk(255, 0, 0);
      tone(buzzer, 1000, 200);
    }
    else {
      renk(0,0,0);
      noTone(buzzer); 
    } 
  }
  delay(100); 
}
