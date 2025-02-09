# esp32BluetoothSpeaker

In diesem Tutorial beschreibe ich, den Bau eines Bluetooth-Lautsprechers mit einem ESP32 Mikrocontroller, einem MAX98357 I2S Digital-Analog-Wandler und einem 4 Ohm Lautsprecher.

![image](https://github.com/user-attachments/assets/cd3ed899-b31d-4198-953e-2e9f812815ea)

und auch einmal mit OLED Display:

Bei der I2S-Musikübertragung werden die Audiodaten in einem festen Datenformat übertragen.
Die I2S-Schnittstelle selbst überträgt jedoch keine Metadaten wie Interpret und Songtitel.
Diese Informationen werden über separate Protokolle wie Bluetooth AVRCP (Audio/Video Remote Control Profile) übertragen.
Titel, Artist und Album sind somit möglich, während der Wiedergabe zu sehen.

![image](https://github.com/user-attachments/assets/8fefc82d-e431-4956-bbf2-fb66b8d33457)

Weitere Details auf meiner Webseite:

https://prilchen.de/esp32-projekt-selbst-ein-bluetooth-lautsprecher-erstellen/
