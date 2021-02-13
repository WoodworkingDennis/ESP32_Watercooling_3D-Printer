// Wasserkuehlung 3D-Drucker by @woodworking.dennis
// Feb. 2021

#include <SPI.h>
#include <Mcp320x.h>

#define RELAY         32

#define SW            4
#define A             5
#define B             13

#define INTTOUCH      14

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

#define DCDISPLAY     33

#define PWMFREQ       5000
#define PWMRES        8

#define ADC_VREF      3300
#define ADC_CLK       1600000

int pwm1speed   =     0;
int pwm2speed   =     0;
int pwm3speed   =     0;

uint16_t raw;     //MCP3208
uint16_t val;     //MCP3208


MCP3208 mcp3208(ADC_VREF, CSMCP);


void checkTemp(){
  Serial.println("Reading...");
  
  raw = mcp3208.read(MCP3208::Channel::SINGLE_0);
  val = mcp3208.toAnalog(raw);
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
}


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

  pinMode(CSTOUCH, OUTPUT);
  digitalWrite(CSTOUCH, HIGH);

  pinMode(CSDISPLAY, OUTPUT);
  digitalWrite(CSDISPLAY, HIGH);

  pinMode(CSSD, OUTPUT);
  digitalWrite(CSSD, HIGH);

  SPISettings settings(ADC_CLK, MSBFIRST, SPI_MODE0);
  SPI.begin();
  SPI.beginTransaction(settings);

}

void loop() {      
  checkTemp();
  delay(2000);
}
