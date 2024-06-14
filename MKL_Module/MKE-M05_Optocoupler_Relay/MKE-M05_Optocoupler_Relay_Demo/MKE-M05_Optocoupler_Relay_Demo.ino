// Thêm bộ thư viện Nút nhấn.
// Add the Button library.
#include <MKL_OneButton.h>

// Chọn chân Digital cho Nút nhấn.
// Select the Digital pin for Button.
#define BUTTON_PIN 11

// Khởi tạo "OneButton" cho Nút nhấn với cấu hình sau.
// Initialize "OneButton" for the Button with the following config.
MKL_OneButton btn = MKL_OneButton(
    BUTTON_PIN, // Cấu hình đây là chân Digital Input.
    true,       // Nút nhấn kích hoạt LOW.
    false       // Kích hoạt điện trở nội "Pull-Up".
);

// Chọn chân Digital điều khiển Relay.
// Select the Digital pin to control Relay.
#define RELAY_PIN 10

// Lưu trạng thái hiện tại của Relay (true = OFF Relay).
// Save the current state of the Relay (true = OFF Relay).
bool stateRelay = true;

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Liên kết hàm "controlRelay" được gọi trên một sự kiện 1 Click.
  // Link the "controlRelay" function to be called on a single click event.
  btn.attachClick(controlRelay);

  // Cấu hình đây là chân Digital Output.
  // Config this is Digital Output.
  pinMode(RELAY_PIN, OUTPUT);

  // Đảm bảo tắt Relay khi mới khởi động.
  // Make sure to turn off the Relay when starting.
  digitalWrite(RELAY_PIN, stateRelay);
}

void loop()
{
  // Tiếp tục theo dõi Nút nhấn.
  // Keep watching the Button.
  btn.tick();
}

void controlRelay()
{
  // Đảo trạng thái Relay.
  // Invert the Relay state.
  stateRelay = !stateRelay;
  digitalWrite(RELAY_PIN, stateRelay);

  // Truyền giá trị lên máy tính.
  // Transmit the value to the computer.
  if (stateRelay)
  {
    Serial.println("Relay: OFF");
  }
  else
  {
    Serial.println("Relay: ON");
  }
}