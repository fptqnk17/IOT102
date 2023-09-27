// IOT102
// Members:
// - QE170148 - Lê Minh Vương
// - QE170033 - Nguyễn Thị Thúy
// - QE170097 - Đinh Quốc Chương
// - QE170173 - Hồ Trọng Nghĩa
// - QE170056 - Trịnh Minh Dương

#include <LiquidCrystal.h>

#define TMP_ANALOG A0
#define F_ALARM_DIGITAL 13

float celsius = 0.f;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    pinMode(F_ALARM_DIGITAL, OUTPUT);
    digitalWrite(F_ALARM_DIGITAL, LOW);
    lcd.begin(16, 2);
}

void loop()
{
    // LM35 - for real
    // celsius = ((analogRead(TMP_ANALOG) * 5.0) / 1024.0) * 100.f;

    // TMP36 - for Tinkercad
    celsius = ((analogRead(TMP_ANALOG) * 5000.0 / 1024.0) - 495.0) / 10.0;

    lcd.clear();
    lcd.print("Nhiet do (do C)");
    lcd.setCursor(0, 1);
    lcd.print(int(celsius));

    if (celsius >= 60.0)
    {
        digitalWrite(F_ALARM_DIGITAL, HIGH);
    }
    else
    {
        digitalWrite(F_ALARM_DIGITAL, LOW);
    }

    delay(1000);
}