// Thêm bộ thư viện IR1838.
// Add the IR1838 library.
#include <IRremote.h>

// Chọn chân đọc IR1838.
// Select the pin to read the IR1838.
#define IR_PIN 11

// Lưu giá trị "command" của tín hiệu IR.
// Store the "command" value of the IR signal.
long commandIR = 0;

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Khởi động thư viện.
  // Start up the library.
  IrReceiver.begin(IR_PIN);
}

void loop()
{
  // Kiểm tra IR1838 xem có nhận được tín hiệu IR nào không?
  // Check IR1838 to see if an IR signal is received?
  if (IrReceiver.decode())
  {
    IrReceiver.resume();
    if (IrReceiver.decodedIRData.protocol == UNKNOWN)
    {
      commandIR = -1;
    }
    else
    {
      commandIR = IrReceiver.decodedIRData.command;
    }
  }
  else
  {
    commandIR = 0;
  }

  // Nếu phát hiện tín hiệu IR sẽ cho in giá trị lên màn hình máy tính.
  // If IR signal is detected, the value will be printed on the computer screen.
  if (commandIR != 0)
  {
    Serial.print("Command: ");
    Serial.println(commandIR);
  }
}