#include <Adafruit_INA219.h>

Adafruit_INA219 ina219_3V3(0x40);
Adafruit_INA219 ina219_5(0x42);
Adafruit_INA219 ina219_9(0x43);
Adafruit_INA219 ina219_12(0x48);

void setup() {
  Serial.begin(115200);
  Serial.println("Olá!");

  ina219_3V3.begin();
  ina219_5.begin();
  ina219_9.begin();
  ina219_12.begin();

  Serial.println("Medindo a tensão de 4 reguladores com os INA219");
}

void loop() {
  float shuntvoltage3V3 = 0;
  float shuntvoltage5 = 0;
  float shuntvoltage9 = 0;
  float shuntvoltage12 = 0;

  shuntvoltage3V3 = ina219_3V3.getShuntVoltage_mV();
  shuntvoltage5 = ina219_5.getShuntVoltage_mV();
  shuntvoltage9 = ina219_9.getShuntVoltage_mV();
  shuntvoltage12 = ina219_12.getShuntVoltage_mV();

  Serial.print("Tensão do módulo 3V3: "); Serial.print(shuntvoltage3V3); Serial.println(" mV");
  Serial.print("Tensão do módulo 5V: "); Serial.print(shuntvoltage5); Serial.println(" mV");
  Serial.print("Tensão do módulo 9V: "); Serial.print(shuntvoltage9); Serial.println(" mV");
  Serial.print("Tensão do módulo 12V: "); Serial.print(shuntvoltage12); Serial.println(" mV");

  delay(3000)
}
