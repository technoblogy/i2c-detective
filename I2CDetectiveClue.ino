/* I2C Detective - Clue version - see http://www.technoblogy.com/show?3FFW

   David Johnson-Davies - www.technoblogy.com - 19th January 2021
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

// Uncomment this for AVR platforms like the Arduino Uno
//#define AVR_DATA

#include <Wire.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

Adafruit_ST7789 tft = Adafruit_ST7789(&SPI1, 31, 32, 33);

typedef struct {
  const char *device;
  const char *category;
  uint8_t from;
  uint8_t to;
  uint8_t test;
  uint8_t value;
} device_t;

const char UnknownDevice[]                        PROGMEM = "Unknown Device";

// Categories
const char Accelerometer[]                        PROGMEM = "Accelerometer";
const char AccelerometerGyroscope[]               PROGMEM = "Accelerometer/Gyroscope";
const char AccelerometerGyroscopeMagnetometer[]   PROGMEM = "Accelerometer/Gyroscope/Magnetometer";
const char AccelerometerMagnetometer[]            PROGMEM = "Accelerometer/Magnetometer";
const char AirQualitySensor[]                     PROGMEM = "Air Quality Sensor";
const char Amplifier[]                            PROGMEM = "Amplifier";
const char AnaloguetoDigitalConverter[]           PROGMEM = "Analogue to Digital Converter";
const char ADCDAC[]                               PROGMEM = "ADC/DAC";
const char CapacitiveTouchSensor[]                PROGMEM = "Capacitive Touch Sensor";
const char ClockGenerator[]                       PROGMEM = "Clock Generator";
const char CO2Sensor[]                            PROGMEM = "CO2 Sensor";
const char ColourSensor[]                         PROGMEM = "Colour Sensor";
const char CryptographicDevice[]                  PROGMEM = "Cryptographic Device";
const char CurrentVoltageSensor[]                 PROGMEM = "Current/Voltage Sensor";
const char CurrentPowerSensor[]                   PROGMEM = "Current/Power Sensor";
const char DigitaltoAnalogueConverter[]           PROGMEM = "Digital to Analogue Converter";
const char DigitalCapacitor[]                     PROGMEM = "Digital Capacitor";
const char DigitalPotentiometer[]                 PROGMEM = "Digital Potentiometer";
const char DSPRadio[]                             PROGMEM = "DSP Radio";
const char FanController[]                        PROGMEM = "Fan Controller";
const char FerroelectricRAM[]                     PROGMEM = "Ferroelectric RAM";
const char FMTransmitter[]                        PROGMEM = "FM Transmitter";
const char FuelGauge[]                            PROGMEM = "Fuel Gauge";
const char GasSensor[]                            PROGMEM = "Gas Sensor";
const char GPIOExpander[]                         PROGMEM = "GPIO Expander";
const char GPSGNSSReceiver[]                      PROGMEM = "GPS GNSS Receiver";
const char Gyroscope[]                            PROGMEM = "Gyroscope";
const char HumidityTemperatureSensor[]            PROGMEM = "Humidity/Temperature Sensor";
const char IRTemperatureSensor[]                  PROGMEM = "IR Temperature Sensor";
const char IRThermalCamera[]                      PROGMEM = "IR Thermal Camera";
const char LEDCharlieplexDriver[]                 PROGMEM = "LED Charlieplex Driver";
const char LEDMatrixDriver[]                      PROGMEM = "LED Matrix Driver";
const char LightColourSensor[]                    PROGMEM = "Light/Colour Sensor";
const char LightSensor[]                          PROGMEM = "Light Sensor";
const char LoadCellScale[]                        PROGMEM = "Load Cell Scale";
const char Magnetometer[]                         PROGMEM = "Magnetometer";
const char MotorDriver[]                          PROGMEM = "Motor Driver";
const char MP3Player[]                            PROGMEM = "MP3 Player";
const char Multiplexer[]                          PROGMEM = "Multiplexer";
const char NFCRFIDReader[]                        PROGMEM = "NFC/RFID Reader";
const char NunchuckController[]                   PROGMEM = "Nunchuck Controller";
const char OLEDDisplay[]                          PROGMEM = "OLED Display";
const char PowerManagementIC[]                    PROGMEM = "Power Management IC";
const char PressureSensor[]                       PROGMEM = "Pressure Sensor";
const char ProximitySensor[]                      PROGMEM = "Proximity Sensor";
const char ProximityLightSensor[]                 PROGMEM = "Proximity/Light Sensor";
const char PulseOximetrySensor[]                  PROGMEM = "Pulse & Oximetry Sensor";
const char PWMDriver[]                            PROGMEM = "PWM Driver";
const char RadioReceiver[]                        PROGMEM = "Radio Receiver";
const char RealTimeClock[]                        PROGMEM = "Real-Time Clock";
const char ResistiveTouchController[]             PROGMEM = "Resistive Touch Controller";
const char RFIDTag[]                              PROGMEM = "RFID Tag";
const char TemperatureSensor[]                    PROGMEM = "Temperature Sensor";
const char TemperatureHumiditySensor[]            PROGMEM = "Temperature/Humidity Sensor";
const char TemperaturePressureSensor[]            PROGMEM = "Temperature/Pressure Sensor";
const char TemperaturePressureHumiditySensor[]    PROGMEM = "Temperature/Pressure/Humidity Sensor";
const char TemperaturePressureHumidityGasSensor[] PROGMEM = "Temperature/Pressure/Humidity/Gas Sensor";
const char ThermocoupleAmplifier[]                PROGMEM = "Thermocouple Amplifier";
const char TimeofFlightSensor[]                   PROGMEM = "Time of Flight Sensor";
const char TriadSpectroscopySensor[]              PROGMEM = "Triad Spectroscopy Sensor";
const char UVLightSensor[]                        PROGMEM = "UV Light Sensor";
const char VOCSensor[]                            PROGMEM = "VOC Sensor";
const char WaterSensor[]                          PROGMEM = "Water Sensor";

// Devices
const device_t Device[] PROGMEM = {
//  Device        Category                              From  To    Reg   ID
  { "ADC122C04",  ThermocoupleAmplifier,                0x40, 0x4F, 0x00, 0x00 },
  { "ADS1015",    AnaloguetoDigitalConverter,           0x48, 0x4B, 0x00, 0x00 },
  { "ADS1113",    AnaloguetoDigitalConverter,           0x48, 0x4B, 0x00, 0x00 },
  { "ADS1114",    AnaloguetoDigitalConverter,           0x48, 0x4B, 0x00, 0x00 },
  { "ADS1115",    AnaloguetoDigitalConverter,           0x48, 0x4B, 0x00, 0x00 },
  { "ADT7410",    TemperatureSensor,                    0x48, 0x4B, 0x0B, 0xCB },
  { "ADXL343",    Accelerometer,                        0x53, 0x1D, 0x00, 0xE5 },
  { "ADXL345",    Accelerometer,                        0x53, 0x1D, 0x00, 0xE5 },
  { "AHT20",      TemperatureHumiditySensor,            0x38, 0x38, 0x00, 0x00 },
  { "AM2315",     HumidityTemperatureSensor,            0x5C, 0x5C, 0x00, 0x00 },
  { "AM2320",     HumidityTemperatureSensor,            0x5C, 0x5C, 0x00, 0x00 },
  { "AMG8831",    IRThermalCamera,                      0x68, 0x69, 0x00, 0x00 },
  { "AMG8833",    IRThermalCamera,                      0x68, 0x69, 0x00, 0x00 },
  { "APDS-9660",  ProximityLightSensor,                 0x39, 0x39, 0x92, 0xAB },
  { "AS7265x",    TriadSpectroscopySensor,              0x49, 0x49, 0x00, 0x00 },
  { "AS7341",     LightColourSensor,                    0x39, 0x39, 0x92, 0x24 },
  { "ATECC608",   CryptographicDevice,                  0x60, 0x60, 0x00, 0x00 },
  { "BH1750",     LightSensor,                          0x5C, 0x23, 0x00, 0x00 },
  { "BMA180",     Accelerometer,                        0x77, 0x77, 0x00, 0x03 },
  { "BME280",     TemperaturePressureHumiditySensor,    0x76, 0x77, 0xD0, 0x60 },
  { "BME680",     TemperaturePressureHumidityGasSensor, 0x76, 0x77, 0xD0, 0x61 },
  { "BMI270",     AccelerometerGyroscope,               0x68, 0x69, 0x00, 0x24 },
  { "BMP085",     TemperaturePressureSensor,            0x77, 0x77, 0x00, 0x00 },
  { "BMP180",     TemperaturePressureSensor,            0x77, 0x77, 0xD0, 0x55 },
  { "BMP280",     TemperaturePressureSensor,            0x76, 0x77, 0xD0, 0x58 },
  { "BMP388",     PressureSensor,                       0x76, 0x77, 0x00, 0x50 },
  { "BMP390",     PressureSensor,                       0x76, 0x77, 0x00, 0x60 },
  { "BNO055",     AccelerometerGyroscopeMagnetometer,   0x28, 0x29, 0x00, 0xA0 },
  { "CAP1188",    CapacitiveTouchSensor,                0x28, 0x2D, 0xFD, 0x50 },
  { "CCS811",     VOCSensor,                            0x5A, 0x5B, 0x20, 0x81 },
  { "Chirp!",     WaterSensor,                          0x20, 0x20, 0x00, 0x00 },
  { "DHT12",      HumidityTemperatureSensor,            0x5C, 0x5C, 0x00, 0x00 },
  { "DPS310",     PressureSensor,                       0x76, 0x77, 0x0D, 0x10 },
  { "DRV2605",    MotorDriver,                          0x5A, 0x5A, 0x00, 0x60 },
  { "DS1307",     RealTimeClock,                        0x68, 0x68, 0x00, 0x00 },
  { "DS1841",     DigitalPotentiometer,                 0x28, 0x2B, 0x03, 0x03 },
  { "DS3231",     RealTimeClock,                        0x68, 0x68, 0x00, 0x00 },
  { "DS3502",     DigitalPotentiometer,                 0x28, 0x2B, 0x00, 0x40 },
  { "EMC2101",    FanController,                        0x4C, 0x4C, 0x00, 0x00 },
  { "FT6x06",     CapacitiveTouchSensor,                0x38, 0x38, 0x00, 0x00 },
  { "FXAS21001",  Gyroscope,                            0x20, 0x21, 0x00, 0x00 },
  { "FXOS8700",   AccelerometerMagnetometer,            0x1C, 0x1F, 0x0D, 0xC7 },
  { "H3LIS331DL", Accelerometer,                        0x18, 0x19, 0x0F, 0x32 },
  { "HDC1008",    TemperatureHumiditySensor,            0x40, 0x43, 0x02, 0x10 },
  { "HDC1008",    HumidityTemperatureSensor,            0x40, 0x43, 0x00, 0x00 },
  { "HMC5883",    Magnetometer,                         0x1E, 0x1E, 0x0A, 0x48 },
  { "HT16K33",    LEDMatrixDriver,                      0x70, 0x77, 0x00, 0x00 },
  { "HTS221",     TemperatureHumiditySensor,            0x5F, 0x5F, 0x0F, 0xBC },
  { "HTU21D-F",   HumidityTemperatureSensor,            0x40, 0x40, 0x00, 0x00 },
  { "ICM-20649",  AccelerometerGyroscope,               0x68, 0x69, 0x00, 0xE1 },
  { "ICM-20948",  AccelerometerGyroscopeMagnetometer,   0x68, 0x69, 0x00, 0xEA },
  { "INA219",     CurrentVoltageSensor,                 0x40, 0x4F, 0x00, 0x39 },
  { "INA260",     CurrentPowerSensor,                   0x40, 0x4F, 0x00, 0x61 },
  { "IS31FL3731", LEDCharlieplexDriver,                 0x74, 0x77, 0x00, 0x00 },
  { "ISL29125",   ColourSensor,                         0x44, 0x44, 0x00, 0x7D },
  { "ISM330DHCX", AccelerometerGyroscope,               0x6A, 0x6B, 0x0F, 0x6B },
  { "ITG3200",    Gyroscope,                            0x68, 0x69, 0x00, 0x00 },
  { "KT0915",     DSPRadio,                             0x35, 0x35, 0x00, 0x00 },
  { "L3GD20H",    Gyroscope,                            0x6A, 0x6B, 0x0F, 0xD7 },
  { "LIS2MDL",    Magnetometer,                         0x1E, 0x1E, 0x4F, 0x40 },
  { "LIS331",     Accelerometer,                        0x18, 0x19, 0x0F, 0x32 },
  { "LIS3DH",     Accelerometer,                        0x18, 0x19, 0x0F, 0x33 },
  { "LIS3MDL",    Magnetometer,                         0x1E, 0x1C, 0x00, 0x00 },
  { "LPS22HB",    PressureSensor,                       0x5C, 0x5D, 0x0F, 0xB1 },
  { "LPS25HB",    PressureSensor,                       0x5C, 0x5D, 0x0F, 0xBD },
  { "LPS33HW",    PressureSensor,                       0x5C, 0x5D, 0x0F, 0xB1 },
  { "LPS35HW",    PressureSensor,                       0x5C, 0x5D, 0x0F, 0xB1 },
  { "LSM303AGR",  AccelerometerMagnetometer,            0x1E, 0x1E, 0x4F, 0x40 },
  { "LSM303AGR",  AccelerometerMagnetometer,            0x19, 0x19, 0x0F, 0x33 },
  { "LSM303D",    AccelerometerMagnetometer,            0x1D, 0x1E, 0x0F, 0x49 },
  { "LSM303DLHC", AccelerometerMagnetometer,            0x1E, 0x1E, 0x0C, 0x33 },
  { "LSM303DLHC", AccelerometerMagnetometer,            0x19, 0x19, 0x20, 0x07 },
  { "LSM6DS33",   AccelerometerGyroscope,               0x6A, 0x6B, 0x0F, 0x69 },
  { "LSM6DSOX",   AccelerometerGyroscope,               0x6A, 0x6B, 0x0F, 0x6C },
  { "LSM9DS0",    AccelerometerGyroscopeMagnetometer,   0x1E, 0x1D, 0x0F, 0x49 },
  { "LSM9DS0",    AccelerometerGyroscopeMagnetometer,   0x6B, 0x6A, 0x0F, 0xD4 },
  { "LSM9DS1",    AccelerometerGyroscopeMagnetometer,   0x1E, 0x1C, 0x0F, 0x3D },
  { "LSM9DS1",    AccelerometerGyroscopeMagnetometer,   0x6B, 0x6A, 0x0F, 0x68 },
  { "LTR-390",    UVLightSensor,                        0x53, 0x53, 0x06, 0xB2 },
  { "MAG3110",    Magnetometer,                         0x0E, 0x0E, 0x00, 0x00 },
  { "MAX17055",   FuelGauge,                            0x36, 0x36, 0x00, 0x00 },
  { "MAX30101",   PulseOximetrySensor,                  0x57, 0x57, 0xFF, 0x15 },
  { "MAX77650",   PowerManagementIC,                    0x48, 0x40, 0x00, 0x00 },
  { "MB85RC",     FerroelectricRAM,                     0x50, 0x57, 0x00, 0x00 },
  { "MB85RC256V", FerroelectricRAM,                     0x50, 0x57, 0x00, 0x00 },
  { "MCP23008",   GPIOExpander,                         0x20, 0x27, 0x00, 0x00 },
  { "MCP23017",   GPIOExpander,                         0x20, 0x27, 0x00, 0x00 },
  { "MCP4725A1",  DigitaltoAnalogueConverter,           0x62, 0x63, 0x00, 0x00 },
  { "MCP4725A2",  DigitaltoAnalogueConverter,           0x64, 0x65, 0x00, 0x00 },
  { "MCP4725A3",  DigitaltoAnalogueConverter,           0x66, 0x67, 0x00, 0x00 },
  { "MCP4728",    DigitaltoAnalogueConverter,           0x60, 0x67, 0x00, 0x00 },
  { "MCP9600",    ThermocoupleAmplifier,                0x60, 0x67, 0x20, 0x40 },
  { "MCP9808",    TemperatureSensor,                    0x18, 0x1F, 0x07, 0x04 },
  { "MLX9061x",   IRTemperatureSensor,                  0x5A, 0x5A, 0x00, 0x00 },
  { "MLX90640",   IRThermalCamera,                      0x33, 0x33, 0x00, 0x00 },
  { "MMA7455L",   Accelerometer,                        0x1C, 0x1D, 0x0F, 0x3D },
  { "MMA8451Q",   Accelerometer,                        0x1C, 0x1D, 0x0D, 0x1A },
  { "MMA8452Q",   Accelerometer,                        0x1C, 0x1D, 0x0D, 0x2A },
  { "MMA8453Q",   Accelerometer,                        0x1C, 0x1D, 0x0D, 0x3A },
  { "MMA8652FC",  Accelerometer,                        0x1D, 0x1D, 0x0D, 0x4A },
  { "MMA8653FC",  Accelerometer,                        0x1D, 0x1D, 0x0D, 0x5A },
  { "MPL115A2",   PressureSensor,                       0x60, 0x60, 0x00, 0x00 },
  { "MPL3115A2",  PressureSensor,                       0x60, 0x60, 0x0C, 0xC4 },
  { "MPR121",     CapacitiveTouchSensor,                0x5A, 0x5D, 0x5C, 0x10 },
  { "MPRLS",      PressureSensor,                       0x18, 0x18, 0x00, 0x00 },
  { "MPU-6000",   AccelerometerGyroscope,               0x68, 0x69, 0x00, 0x00 },
  { "MPU-6050",   AccelerometerGyroscope,               0x68, 0x69, 0x00, 0x00 },
  { "MPU-9250",   AccelerometerGyroscopeMagnetometer,   0x68, 0x69, 0x00, 0x48 },
  { "MS5607",     PressureSensor,                       0x76, 0x77, 0x00, 0x00 },
  { "MS5611",     PressureSensor,                       0x76, 0x77, 0x00, 0x00 },
  { "MSA301",     Accelerometer,                        0x26, 0x26, 0x01, 0x13 },
  { "NAU7802",    LoadCellScale,                        0x2A, 0x2A, 0x00, 0x00 },
  { "NCD2400M",   DigitalCapacitor,                     0x60, 0x60, 0x00, 0x00 },
  { "NCD2400M1",  DigitalCapacitor,                     0x61, 0x61, 0x00, 0x00 },
  { "NEO-M9N",    GPSGNSSReceiver,                      0x42, 0x42, 0x00, 0x00 },
  { "Nintendo",   NunchuckController,                   0x52, 0x52, 0x00, 0x00 },
  { "PA1010D",    GPSGNSSReceiver,                      0x10, 0x10, 0x00, 0x00 },
  { "PCA9685",    PWMDriver,                            0x7F, 0x40, 0x00, 0x00 },
  { "PCF8523",    RealTimeClock,                        0x68, 0x68, 0x00, 0x00 },
  { "PCF8591",    ADCDAC,                               0x48, 0x4F, 0x00, 0x00 },
  { "PMSA003I",   AirQualitySensor,                     0x12, 0x12, 0x00, 0x00 },
  { "PN532",      NFCRFIDReader,                        0x48, 0x48, 0x00, 0x00 },
  { "SCD30",      CO2Sensor,                            0x61, 0x61, 0x00, 0x00 },
  { "SGP30",      GasSensor,                            0x58, 0x58, 0x00, 0x00 },
  { "SGP40",      GasSensor,                            0x59, 0x59, 0x00, 0x00 },
  { "SH1106",     OLEDDisplay,                          0x3C, 0x3D, 0x00, 0x00 },
  { "SHT30",      HumidityTemperatureSensor,            0x44, 0x45, 0x00, 0x00 },
  { "SHT31",      HumidityTemperatureSensor,            0x44, 0x45, 0x00, 0x00 },
  { "SHT35",      HumidityTemperatureSensor,            0x44, 0x45, 0x00, 0x00 },
  { "SHTC3",      TemperatureHumiditySensor,            0x70, 0x70, 0x00, 0x00 },
  { "SSD1305",    OLEDDisplay,                          0x3C, 0x3D, 0x00, 0x00 },
  { "SSD1306",    OLEDDisplay,                          0x3C, 0x3D, 0x00, 0x00 },
  { "SSD1327",    OLEDDisplay,                          0x7A, 0x78, 0x00, 0x00 },
  { "ST25DV16K",  RFIDTag,                              0x57, 0x53, 0x00, 0x00 },
  { "ST25DV16K",  RFIDTag,                              0x2D, 0x2D, 0x00, 0x00 },
  { "STMPE610",   ResistiveTouchController,             0x44, 0x41, 0x00, 0x08 },
  { "STMPE811",   ResistiveTouchController,             0x44, 0x41, 0x00, 0x08 },
  { "Si1145",     LightSensor,                          0x60, 0x60, 0x00, 0x45 },
  { "Si1146",     LightSensor,                          0x60, 0x60, 0x00, 0x46 },
  { "Si1147",     LightSensor,                          0x60, 0x60, 0x00, 0x47 },
  { "Si4712",     FMTransmitter,                        0x63, 0x11, 0x00, 0x00 },
  { "Si4713",     FMTransmitter,                        0x63, 0x11, 0x00, 0x00 },
  { "Si5351A",    ClockGenerator,                       0x60, 0x61, 0x00, 0x00 },
  { "Si7021",     HumidityTemperatureSensor,            0x40, 0x40, 0x00, 0x00 },
  { "TC74A0",     TemperatureSensor,                    0x48, 0x48, 0x00, 0x00 },
  { "TCA9548A",   Multiplexer,                          0x70, 0x77, 0x00, 0x00 },
  { "TCS34721",   ColourSensor,                         0x39, 0x39, 0x92, 0x44 },
  { "TCS34723",   ColourSensor,                         0x39, 0x39, 0x92, 0x4D },
  { "TCS34725",   ColourSensor,                         0x29, 0x29, 0x92, 0x44 },
  { "TCS34727",   ColourSensor,                         0x29, 0x29, 0x92, 0x4D },
  { "TEA5767",    RadioReceiver,                        0x60, 0x60, 0x00, 0x00 },
  { "TLV493D",    Magnetometer,                         0x5E, 0x5E, 0x00, 0x00 },
  { "TMP006",     IRTemperatureSensor,                  0x40, 0x47, 0xFE, 0x54 },
  { "TMP007",     IRTemperatureSensor,                  0x40, 0x47, 0xFE, 0x54 },
  { "TMP102",     TemperatureSensor,                    0x48, 0x4B, 0x00, 0x00 },
  { "TMP117",     TemperatureSensor,                    0x48, 0x49, 0x00, 0x00 },
  { "TPA2016",    Amplifier,                            0x58, 0x58, 0x00, 0x00 },
  { "TSL2561",    LightSensor,                          0x49, 0x49, 0x00, 0x00 },
  { "TSL2561",    LightSensor,                          0x39, 0x29, 0x00, 0x00 },
  { "TSL2591",    LightSensor,                          0x28, 0x29, 0x12, 0x50 },
  { "VCNL4000",   ProximitySensor,                      0x13, 0x13, 0x81, 0x11 },
  { "VCNL4010",   ProximitySensor,                      0x13, 0x13, 0x81, 0x21 },
  { "VCNL4020",   ProximitySensor,                      0x13, 0x13, 0x81, 0x21 },
  { "VCNL4040",   ProximityLightSensor,                 0x60, 0x60, 0x0C, 0x86 },
  { "VEML6070",   UVLightSensor,                        0x38, 0x39, 0x00, 0x00 },
  { "VEML6075",   UVLightSensor,                        0x10, 0x10, 0x0C, 0x26 },
  { "VEML7700",   LightSensor,                          0x10, 0x10, 0x00, 0x00 },
  { "VL53L0X",    TimeofFlightSensor,                   0x29, 0x29, 0xC0, 0xEE },
  { "VL53L1X",    TimeofFlightSensor,                   0x29, 0x29, 0xC0, 0xEE },
  { "VL53L3CX",   TimeofFlightSensor,                   0x29, 0x29, 0x00, 0x00 },
  { "VL6180X",    TimeofFlightSensor,                   0x29, 0x29, 0x00, 0xB4 },
  { "WT2003S",    MP3Player,                            0x37, 0x37, 0x00, 0x00 },
  { "XA1110",     GPSGNSSReceiver,                      0x10, 0x10, 0x00, 0x00 },
  { "ZMOD4450",   GasSensor,                            0x32, 0x32, 0x00, 0x00 },
  { "ZOE-M8Q",    GPSGNSSReceiver,                      0x42, 0x42, 0x00, 0x00 },
};

const device_t Unknown PROGMEM = {"?", UnknownDevice, 0, 0, 0, 0};
const int Devices = sizeof Device / sizeof *Device;

boolean match (uint8_t addr, uint8_t from, uint8_t to) {
  if (from > to) return (addr == from) || (addr == to);
  else return (addr >= from) && (addr <= to);
}

boolean whoami (uint8_t addr, uint8_t reg, uint8_t value) {
  if (reg == 0x00 && value == 0x00) return false;
  Wire.beginTransmission(addr);
  Wire.write(reg);
  if (Wire.endTransmission(false) != 0) return false;
  Wire.requestFrom(addr, 1);
  return value == Wire.read();
}

uint8_t who (uint8_t addr, uint8_t reg) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(addr, 1);
  return Wire.read();
}

const device_t *findtwin (int i) {
  const device_t *me = &Device[i];
  const device_t *other;
  for (int j = i-1; j <= i+1; j=j+2) {
    if (j >= 0 && j < Devices) {
      other = &Device[j];
      if (strcmp(me->device, other->device) == 0) return other;
    }
  }
  return NULL;
}

boolean twindevice (int i) {
  boolean ok;
  // Check whether previous or next one in list is a twin
  const device_t *other = findtwin(i);
  if (other) {
    // Check its whoami
    uint8_t from = other->from;
    uint8_t to = other->to;
    uint8_t test = other->test;
    uint8_t value = other->value;
    if (from > to) {
      ok = whoami(from, test, value) || whoami(to, test, value);
    } else {
      ok = false;
      for (uint8_t addr = from; addr <= to; addr++) {
        ok = whoami(addr, test, value);
        if (ok) break;
      }
    }
    if (ok) return true;
  }
  return false;
}

void list (uint8_t addr, const device_t *me) {
  tft.print("0x"); tft.print(addr/16, HEX);
  tft.print(addr&0xF, HEX); tft.print(' ');
  tft.print(me->category);
  tft.print(": "); tft.print(me->device);
  tft.println(); tft.println();
}

void lookup (uint8_t addr) {
  // Check for devices with a device ID match
  boolean listed = false;
  for (int pass=1; pass<4; pass++) {
    for (int i=0; i<Devices; i++) {
      const device_t *me = &Device[i];
      uint8_t from = me->from;
      uint8_t to = me->to;
      uint8_t test = me->test;
      uint8_t value = me->value;
      if (match(addr, from, to)) {
        boolean ok;
        if (pass == 1) ok = twindevice(i) && whoami(addr, test, value);
        else if (pass == 2) ok = whoami(addr, test, value) && !findtwin(i);
        else if (pass == 3) ok = test == 0x00 && value == 0x00;
        if (ok) {
          list(addr, me);
          listed = true;
        }
      }
    }
    if (listed) return;
  }
  list(addr, &Unknown);
}

void scan () {
  for (uint8_t addr=8; addr<128; addr++) {
    int ok = true;
    Wire.beginTransmission(addr);
    if (Wire.endTransmission(true) == 0) lookup(addr);
  }
}

void setup () {
  Wire.begin();
  tft.init(240, 240);
  tft.setRotation(1);
  tft.fillScreen(0);
  pinMode(34, OUTPUT); // Backlight
  digitalWrite(34, HIGH);
}

void loop () {
  tft.setTextSize(2);
  tft.println("   I2C Detective");
  tft.setTextSize(1);
  tft.println();
  scan();
  for(;;);
}
