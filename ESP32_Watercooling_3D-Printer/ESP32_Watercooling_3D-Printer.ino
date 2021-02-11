// Wasserkuehlung 3D-Drucker by @woodworking.dennis
// Feb. 2021

#include <SPI.h>
#include <Mcp320x.h>

#define RELAY         32

#define SW            4
#define A             5
#define B             13

#define TOUCH         14

#define CSMCP         2
#define CSTOUCH       15
#define CSDISPLAY     16
#define CSSD          17

#define CLK           18
#define MISO          19
#define MOSI          23

#define SDA           21
#define SCL           22

#define PWM1          25
#define PWM1CHAN      0

#define PWM2          26
#define PWM2CHAN      1

#define PWM3          27
#define PWM3CHAN      2

#define PWMFREQ       5000
#define PWMRES        8

#define ADC_VREF      3300
#define ADC_CLK       1600000

int pwm1speed   =     0;
int pwm2speed   =     0;
int pwm3speed   =     0;


MCP3208 mcp3208(ADC_VREF, CSMCP);

void setup() {
  Serial.begin(115200);
  
  Serial.println("ESP32 started");

  ledcSetup(PWM1CHAN, PWMFREQ, PWMRES);
  ledcAttachPin(PWM1, PWM1CHAN);
  ledcWrite(PWM1CHAN, pwm1speed);

  ledcSetup(PWM2CHAN, PWMFREQ, PWMRES);
  ledcAttachPin(PWM2, PWM2CHAN);
  ledcWrite(PWM2CHAN, pwm2speed);

  ledcSetup(PWM3CHAN, PWMFREQ, PWMRES);
  ledcAttachPin(PWM3, PWM3CHAN);
  ledcWrite(PWM3CHAN, pwm3speed);

  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

  pinMode(CSMCP, OUTPUT);
  digitalWrite(CSMCP, HIGH);

  SPISettings settings(ADC_CLK, MSBFIRST, SPI_MODE0);
  SPI.begin();
  SPI.beginTransaction(settings);

}

void loop() {
  uint32_t t1;
  uint32_t t2;
  
  Serial.println("Reading...");

//  t1 = micros();
  uint16_t raw = mcp3208.read(MCP3208::Channel::SINGLE_0);
//  t2 = micros();

  uint16_t val = mcp3208.toAnalog(raw);

  Serial.print("value 1: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");


  raw = mcp3208.read(MCP3208::Channel::SINGLE_1);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 2: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");

  raw = mcp3208.read(MCP3208::Channel::SINGLE_2);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 3: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");

  raw = mcp3208.read(MCP3208::Channel::SINGLE_3);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 4: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");

  raw = mcp3208.read(MCP3208::Channel::SINGLE_4);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 5: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");

  raw = mcp3208.read(MCP3208::Channel::SINGLE_5);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 6: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");

  raw = mcp3208.read(MCP3208::Channel::SINGLE_6);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 7: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");  

  raw = mcp3208.read(MCP3208::Channel::SINGLE_7);
  val = mcp3208.toAnalog(raw);
  Serial.print("value 8: ");
  Serial.print(raw);
  Serial.print(" (");
  Serial.print(val);
  Serial.println(" mV)");      
  
/*  Serial.print("Sampling time: ");
  Serial.print(static_cast<double>(t2 - t1) / 1000, 4);
  Serial.println("ms");
*/
/*  Serial.println(mcp3208.analogRead(0));
  Serial.println("-----");
  Serial.println(mcp3208.analogRead(1));
  Serial.println("-----");  
  Serial.println("-----");  
  Serial.println(mcp3208.analogRead(2));
  Serial.println("-----");
  Serial.println(mcp3208.analogRead(3));
  Serial.println("-----"); 
  Serial.println(mcp3208.analogRead(4));
  Serial.println("-----");
  Serial.println(mcp3208.analogRead(5));
  Serial.println("-----");
  Serial.println(mcp3208.analogRead(6));
  Serial.println("-----");
  Serial.println(mcp3208.analogRead(7));
  Serial.println("-----");
  Serial.println("-----");
  Serial.println("-----");
*/
  delay(2000);

}
