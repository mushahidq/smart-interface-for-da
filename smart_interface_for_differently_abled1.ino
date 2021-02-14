int buttonOneState = 0;
int buttonTwoState = 0;
int buttonThreeState = 0;
int buttonFourState = 0;
char ledNoToggle[2] = "00";

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);

}

void loop()
{
  // read the input pin
  buttonOneState = digitalRead(2);
  buttonTwoState = digitalRead(3);
  buttonThreeState = digitalRead(4);
  buttonFourState = digitalRead(5);
  // print out the state of the button
  if (buttonOneState == 1) {
	Serial.println("Button one pressed");
    ledNoToggle = "1";
    Serial.write(ledNoToggle,1);
    delay(200);
  }
  if (buttonTwoState == 1) {
	Serial.println("Button two pressed");
	ledNoToggle = "2";
    Serial.write(ledNoToggle,1);
    delay(200);
  }
  if (buttonThreeState == 1) {
	Serial.println("Button three pressed");
	ledNoToggle = "3";
    Serial.write(ledNoToggle,1);
    delay(200);
  }
  if (buttonFourState == 1) {
	Serial.println("Button four pressed");
	ledNoToggle = "4";
    Serial.write(ledNoToggle,1);
    delay(200);
  }
  delay(10); // Delay a little bit to improve simulation performance
}