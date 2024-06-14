#include <MKL_OneWire.h>
#include <MKL_DallasTemperature.h>

// Chọn chân đọc cảm biến.
// Select the pin to read the sensor.
#define SIG_PIN 10

// Cấu hình chân kết nối tín hiệu cho cảm biến DS18B20.
// Configure the signal connection pins for the DS18B20 sensor.
MKL_OneWire oneWire(SIG_PIN);
MKL_DallasTemperature ds(&oneWire);

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Khởi động thư viện.
  // Start up the library.  
  ds.begin();
}

void loop()
{
  // Transmit the measured distance of the ultrasonic sensor to the computer.
  // Truyền khoảng cách đo được của cảm biến siêu âm lên máy tính.
  ds.requestTemperatures();
  Serial.print("Temperature in °C: ");
  Serial.println(ds.getTempCByIndex(0), 2);

  // Chờ 0,5s mới đo lại.
  // Wait 0,5s to measure again.
  delay(500);
}