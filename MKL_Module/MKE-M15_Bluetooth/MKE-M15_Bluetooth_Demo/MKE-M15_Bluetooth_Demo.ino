// Thêm bộ thư viện GamePad Dabble.
// Add the GamePad Dabble library.
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Chọn chân cấu hình cho mô-đun Bluetooth.
// Select the configuration pin for the Bluetooth module.
#define TX_PIN 12
#define RX_PIN 13

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Khởi động thư viện và cấu hình các chân kết nối.
  // Start the library and configure the pins.
  Dabble.begin(115200, RX_PIN, TX_PIN);
}

void loop()
{
  /**
   * Hàm này được sử dụng để làm mới dữ liệu thu được từ điện thoại thông minh.
   * Do đó, việc gọi hàm này là bắt buộc để nhận dữ liệu chính xác từ điện thoại di động của bạn.
   */
  Dabble.processInput();

  // Truyền tên nút bấm từ điện thoại lên máy tính.
  // Transfer button names from phone to computer.
  if (GamePad.isUpPressed())
  {
    Serial.println("UP");
  }
  if (GamePad.isDownPressed())
  {
    Serial.println("DOWN");
  }
  if (GamePad.isLeftPressed())
  {
    Serial.println("LEFT");
  }
  if (GamePad.isRightPressed())
  {
    Serial.println("RIGHT");
  }

  // Chờ 0,05s mới kiểm tra lại.
  // Wait 0,05s to check again.
  delay(50);
}