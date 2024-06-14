// Thêm bộ thư viện DS1307.
// Add the DS1307 library.
#include "MKL_RTClib.h"

// Khởi tạo "RTC_DS1307".
// Initialize "RTC_DS1307".
MKL_RTC_DS1307 rtc;

// Lưu tên gọi của Thứ trong Tuần.
// Save the name of the Day of the Week.
char daysOfTheWeek[7][12] = {
    "Sun", // Chủ Nhật.
    "Mon", // Thứ 2.
    "Tue", // Thứ 3.
    "Wed", // Thứ 4.
    "Thu", // Thứ 5.
    "Fri", // Thứ 6.
    "Sat"  // Thứ 7.
};

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Khởi động thư viện.
  // Start up the library.
  rtc.begin();
}

void loop()
{
  // Lấy toàn bộ dữ liệu thời gian hiện tại.
  // Get all current time data.
  MKL_DateTime now = rtc.now();

  // Truyền giá trị lên máy tính.
  // Transmit the value to the computer.
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(", ");
  //
  Serial.print(now.day(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.year(), DEC);
  Serial.print(" - ");
  //
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
  Serial.println();

  // Đợi 1s để cập nhập tiếp.
  // Wait 1s to update again.
  delay(1000);
}