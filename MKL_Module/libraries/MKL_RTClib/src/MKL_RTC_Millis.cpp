#include "MKL_RTClib.h"

/**************************************************************************/
/*!
    @brief  Set the current date/time of the MKL_RTC_Millis clock.
    @param dt MKL_DateTime object with the desired date and time
*/
/**************************************************************************/
void MKL_RTC_Millis::adjust(const MKL_DateTime &dt) {
  lastMillis = millis();
  lastUnix = dt.unixtime();
}

/**************************************************************************/
/*!
    @brief  Return a MKL_DateTime object containing the current date/time.
            Note that computing (millis() - lastMillis) is rollover-safe as long
            as this method is called at least once every 49.7 days.
    @return MKL_DateTime object containing current time
*/
/**************************************************************************/
MKL_DateTime MKL_RTC_Millis::now() {
  uint32_t elapsedSeconds = (millis() - lastMillis) / 1000;
  lastMillis += elapsedSeconds * 1000;
  lastUnix += elapsedSeconds;
  return lastUnix;
}
