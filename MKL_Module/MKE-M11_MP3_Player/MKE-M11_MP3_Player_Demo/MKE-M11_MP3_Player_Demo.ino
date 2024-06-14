// Thêm bộ thư viện MP3 Player.
// Add the MP3 Player library.
#include "SoftwareSerial.h"
#include "MKL_DFRobotDFPlayerMini.h"

// Chọn chân cấu hình cho SoftwareSerial.
// Select the configuration pin for SoftwareSerial.
#define TX_PIN 12
#define RX_PIN 13

// Cấu hình chân kết nối tín hiệu cho MP3 Player.
// Configure the signal connection pins for the MP3 Player.
SoftwareSerial mySoftwareSerial(RX_PIN, TX_PIN);
MKL_DFRobotDFPlayerMini myDFPlayer;

/* ------------------------------------------------------------------------- */

// Đợi cho đến khi phát nhạc xong.
// Wait until the music play is done.
void waitFinishMusic()
{
  byte count = 0;
  bool wrongStack = false;
  bool timeOut = false;
  while (1)
  {
    if (myDFPlayer.available())
    {
      if (myDFPlayer.readType() == DFPlayerPlayFinished)
      {
        count++;
        if (count == 1)
        {
          break;
        }
      }
      else
      {
        if (myDFPlayer.readType() == WrongStack)
        {
          wrongStack = true;
        }
        else if (myDFPlayer.readType() == TimeOut)
        {
          timeOut = true;
        }
        //
        if (wrongStack && timeOut)
        {
          break;
        }
      }
    }
  }
}

/* ------------------------------------------------------------------------- */

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 9600 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 9600 to transfer data to the computer.
  Serial.begin(9600);

  // Khởi động thư viện.
  // Start up the library.
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);

  // Cài đặt MP3 Player.
  // Install MP3 Player.
  myDFPlayer.volume(30);
  myDFPlayer.EQ(DFPLAYER_EQ_JAZZ);

  // Cho phát file số 1 đến hết bài.
  // Play file number 1 to the end.
  Serial.println("Play file 1 until done");
  myDFPlayer.playMp3Folder(1);
  waitFinishMusic();
}

void loop()
{
  // Cho phát bài nhạc kế tiếp đến hết bài.
  // Play the next song until the end of the song.
  Serial.print("Play next - ");
  myDFPlayer.next();
  waitFinishMusic();
  Serial.println("Done");
}