// Simple date conversions and calculations

#include "MKL_RTClib.h"

void showDate(const char* txt, const MKL_DateTime& dt) {
    Serial.print(txt);
    Serial.print(' ');
    Serial.print(dt.year(), DEC);
    Serial.print('/');
    Serial.print(dt.month(), DEC);
    Serial.print('/');
    Serial.print(dt.day(), DEC);
    Serial.print(' ');
    Serial.print(dt.hour(), DEC);
    Serial.print(':');
    Serial.print(dt.minute(), DEC);
    Serial.print(':');
    Serial.print(dt.second(), DEC);

    Serial.print(" = ");
    Serial.print(dt.unixtime());
    Serial.print("s / ");
    Serial.print(dt.unixtime() / 86400L);
    Serial.print("d since 1970");

    Serial.println();
}

void showTimeSpan(const char* txt, const MKL_TimeSpan& ts) {
    Serial.print(txt);
    Serial.print(" ");
    Serial.print(ts.days(), DEC);
    Serial.print(" days ");
    Serial.print(ts.hours(), DEC);
    Serial.print(" hours ");
    Serial.print(ts.minutes(), DEC);
    Serial.print(" minutes ");
    Serial.print(ts.seconds(), DEC);
    Serial.print(" seconds (");
    Serial.print(ts.totalseconds(), DEC);
    Serial.print(" total seconds)");
    Serial.println();
}

void setup () {
    Serial.begin(57600);

#ifndef ESP8266
    while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

    MKL_DateTime dt0 (0, 1, 1, 0, 0, 0);
    showDate("dt0", dt0);

    MKL_DateTime dt1 (1, 1, 1, 0, 0, 0);
    showDate("dt1", dt1);

    MKL_DateTime dt2 (2009, 1, 1, 0, 0, 0);
    showDate("dt2", dt2);

    MKL_DateTime dt3 (2009, 1, 2, 0, 0, 0);
    showDate("dt3", dt3);

    MKL_DateTime dt4 (2009, 1, 27, 0, 0, 0);
    showDate("dt4", dt4);

    MKL_DateTime dt5 (2009, 2, 27, 0, 0, 0);
    showDate("dt5", dt5);

    MKL_DateTime dt6 (2009, 12, 27, 0, 0, 0);
    showDate("dt6", dt6);

    MKL_DateTime dt7 (dt6.unixtime() + 3600); // One hour later.
    showDate("dt7", dt7);

    MKL_DateTime dt75 = dt6 + MKL_TimeSpan(0, 1, 0, 0); // One hour later with MKL_TimeSpan addition.
    showDate("dt7.5", dt75);

    MKL_DateTime dt8 (dt6.unixtime() + 86400L); // One day later.
    showDate("dt8", dt8);

    MKL_DateTime dt85 = dt6 + MKL_TimeSpan(1, 0, 0, 0); // One day later with MKL_TimeSpan addition.
    showDate("dt8.5", dt85);

    MKL_DateTime dt9 (dt6.unixtime() + 7 * 86400L); // One week later.
    showDate("dt9", dt9);

    MKL_DateTime dt95 = dt6 + MKL_TimeSpan(7, 0, 0, 0); // One week later with MKL_TimeSpan addition.
    showDate("dt9.5", dt95);

    MKL_DateTime dt10 = dt6 + MKL_TimeSpan(0, 0, 42, 42); // Fourty two minutes and fourty two seconds later.
    showDate("dt10", dt10);

    MKL_DateTime dt11 = dt6 - MKL_TimeSpan(7, 0, 0, 0);  // One week ago.
    showDate("dt11", dt11);

    MKL_TimeSpan ts1 = dt6 - dt5;
    showTimeSpan("dt6-dt5", ts1);

    MKL_TimeSpan ts2 = dt10 - dt6;
    showTimeSpan("dt10-dt6", ts2);
}

void loop () {
}
