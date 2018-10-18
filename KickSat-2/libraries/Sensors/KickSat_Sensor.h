//**********************************************************
// KickSat_Sensor.h
//**********************************************************
//TODO:

#include <Arduino.h>
#ifndef KICKSAT_SENSOR_H_
#define KICKSAT_SENSOR_H_

#define SENSOR1_BUF_LEN 5 //9 - 3
#define SENSOR3_BUF_LEN 9
#define SENSOR1_START 0
#define SENSOR3_START SENSOR1_BUF_LEN
#define SENSOR3_OLD_START (SENSOR3_START + SENSOR3_BUF_LEN)
#define SENSOR_LEN_FLOAT (SENSOR1_BUF_LEN + 2*(SENSOR3_BUF_LEN))
#define SENSOR_LEN_BYTE 4*(SENSOR_LEN_FLOAT)

class KickSat_Sensor
{
  public:
    KickSat_Sensor(uint8_t adc_rst);
    void operate(String board, float* dataBuffer, uint8_t SenMode);
    void burstWriteRegs(byte start, uint8_t len, byte* data);
    void startADC();
    void stopADC();
    void resetADC();
    void shutdownADC();
    void wakeADC();
    void regReadout();
    void GPIO(byte pins, byte state);
    void writeReg(byte start, byte value);
    void initialize();
    float getFloat(byte packet[], uint8_t i);
    float readTemp();
    float readPins(byte pinNums, byte idacPin, byte vbPin, int wait, int bufflen, byte idacMag);    
    float hallGen(uint8_t inp, uint8_t inn, byte idacMag, uint8_t idacMux, uint8_t vb, int delayT);    
    float dataConvert( byte a, byte b, byte c);   
    float voltageApplied;
    String board;
    uint32_t sensor1_count = 0;
    uint32_t sensor2_count = 0;
    uint32_t sensor3_count = 0;
    uint8_t pauseTime = 50;
    uint8_t SenMode = 0;

  private:
    uint8_t _ADCchipSelect;
    uint8_t _ADCreset;
    uint8_t _SDchipSelect;
    byte readOut[17];
    const float refV = 2.5;
    const float pgaGain = 1;
    const float FSR = (refV*2)/pgaGain;
    const float LSBsize = FSR/pow(2,24);
    
};
#endif /* KICKSAT_SENSOR_H_ */
