
#define BLYNK_TEMPLATE_ID "Template Id"
#define BLYNK_TEMPLATE_NAME "Smart Door 1"
#define BLYNK_AUTH_TOKEN "Blynk Auth Token"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <DHT.h>

// ========================================
// WIFI SETTINGS
// ========================================

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Your Wifi Name";
char pass[] = "Your Wifi Password";

// ========================================
// PIN DEFINITIONS
// ========================================

#define SERVO_PIN D5
#define DHT_PIN D2
#define WIFI_LED D4

#define DHT_TYPE DHT11

// ========================================
// OBJECTS
// ========================================

Servo myServo;
DHT dht(DHT_PIN, DHT_TYPE);

BlynkTimer timer;

// ========================================
// SERVO SETTINGS
// ========================================

int doorCloseAngle = 0;
int doorOpenAngle = 180;

// ========================================
// BLYNK DOOR CONTROL
// V0 = Door Switch
// ========================================

BLYNK_WRITE(V0)
{
  int state = param.asInt();

  if (state == 1)
  {
    Serial.println("DOOR OPENING - 180 DEGREE");

    myServo.write(doorOpenAngle);
  }
  else
  {
    Serial.println("DOOR CLOSING - 0 DEGREE");

    myServo.write(doorCloseAngle);
  }
}

// ========================================
// DHT11 SENSOR
// V1 = Temperature
// V2 = Humidity
// ========================================

void sendSensor()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("DHT11 SENSOR ERROR!");
    Serial.println("Check sensor connections.");

    return;
  }

  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C");

  Serial.print(" | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

// ========================================
// SETUP
// ========================================

void setup()
{
  Serial.begin(115200);

  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP8266 SMART DOOR SYSTEM");
  Serial.println("SERVO + DHT11 MONITOR");
  Serial.println("==============================");

  // WiFi LED
  pinMode(WIFI_LED, OUTPUT);
  digitalWrite(WIFI_LED, HIGH);

  // Servo setup
  myServo.attach(SERVO_PIN, 500, 2400);

  // Initially close door
  myServo.write(doorCloseAngle);

  Serial.println("Servo initialized.");

  // DHT11 setup
  dht.begin();

  Serial.println("DHT11 initialized.");

  // Allow sensor to stabilize
  delay(2000);

  // Blynk connection
  Serial.println("Connecting to Blynk...");

  Blynk.begin(auth, ssid, pass);

  Serial.println("Blynk Connected!");

  digitalWrite(WIFI_LED, LOW);

  // Initially close door in app
  Blynk.virtualWrite(V0, 0);

  // Read sensor every 2.5 seconds
  timer.setInterval(2500L, sendSensor);
}

// ========================================
// MAIN LOOP
// ========================================

void loop()
{
  Blynk.run();

  timer.run();
}
