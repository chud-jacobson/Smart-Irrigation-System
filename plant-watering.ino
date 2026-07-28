const int SOIL_PIN = 1;
const int PUMP_PIN = 4;

void setup() {
  Serial.begin(115200);mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  
  pinMode(PUMP_PIN, OUTPUT);
  
  analogReadResolution(12);
}

void loop() {
  int rawValue = analogRead(SOIL_PIN);
  
  // Dry threshold: Turn pump ON
  Serial.print(rawValue);
  if(rawValue >= 2000){
    Serial.println(" Pump ON");
    digitalWrite(PUMP_PIN, HIGH);  // Active-LOW relay turns ON
  } 
  // Wet threshold: Turn pump OFF
  else {
    Serial.println(" Pump OFF");
    digitalWrite(PUMP_PIN, LOW); // Active-LOW relay turns OFF
  }

  // MUST have a delay to prevent crashing the loop
  delay(1000); 
}