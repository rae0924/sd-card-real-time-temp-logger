# sd-card-real-time-temp-logger
STM32 project that logs temperature and time into an SD card. Created to record the temperature of my room during power outages caused by snowstorms in Texas. Used an I2C serial 
RTC [(DS3231)](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf), I2C temperature sensor [(TMP75B)](https://www.ti.com/lit/ds/symlink/tmp75b.pdf?ts=1613699957431&ref_url=https%253A%252F%252Fwww.google.com%252F), and an SD card with SPI.
