int ledOneState = 0;
int ledTwoState = 0;
int ledThreeState = 0;
int ledFourState = 0;
char *ledNoToggle[2] = "00";

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  *ledNoToggle = "00";
  Serial.readBytes(ledNoToggle, 2);
  if (*ledNoToggle == "01") {
    if (ledOneState == 1) {      
      ledOneState = 0;
      digitalWrite(2, LOW);
      delay(200);
    }
    else {
      ledOneState = 1;
      digitalWrite(2, HIGH);
      delay(200);
    }
  }
  else if (ledNoToggle == "02") {
    if (ledTwoState == 1) {
      ledTwoState = 0;
      digitalWrite(3, LOW);
      delay(200);
    }
    else {
      ledTwoState = 1;
      digitalWrite(3, HIGH);
      delay(200);
    }
  }
  else if (ledNoToggle == "03") {
    if (ledThreeState == 1) {
      ledThreeState = 0;
      digitalWrite(4, LOW);
      delay(200);
    }
    else {
      ledThreeState = 1;
      digitalWrite(4, HIGH);
      delay(200);
    }
  }
  else if (ledNoToggle == "04") {
    if (ledFourState == 1) {
      ledFourState = 0;
      digitalWrite(5, LOW);
      delay(200);
    }
    else {
      ledFourState = 1;
      digitalWrite(5, HIGH);
      delay(200);
    }
  }
}