#define BLYNK_USE_DIRECT_CONNECT
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(19, 18); // RX, TX
#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleSerialBLE.h>
char auth[] = "sBVEAogcssGh0CdZfLV2rPOQmaNsqzcP";
void setup()
{
  DebugSerial.begin(9600);
  DebugSerial.println("Waiting for connections...");
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}
void loop()
{
  Blynk.run();
}
