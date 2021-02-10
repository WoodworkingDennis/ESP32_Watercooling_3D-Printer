// Wasserkuehlung 3D-Drucker by @woodworking.dennis
// Feb. 2021


#define DOOR          2
#define LIGHT         32

#define SW            4
#define A             5
#define B             13

#define TOUCH         14
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

int pwm1speed   =     0;
int pwm2speed   =     0;
int pwm3speed   =     0;


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

}

void loop() {
  // put your main code here, to run repeatedly:

}
