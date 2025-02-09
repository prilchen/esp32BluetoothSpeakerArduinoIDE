#include <Wire.h>  //für I2C-Kommunikation
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <DFRobot_MAX98357A.h>

#define SCREEN_WIDTH 128  // OLED display width
#define SCREEN_HEIGHT 64  // OLED display height
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DFRobot_MAX98357A amplifier;  // instantiate an object to control the amplifier

void setup(void) {
  Serial.begin(115200);

 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialisiere I2C mit Addr 0x3C
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  delay(2000);

  while (!amplifier.begin(/*btName=*/"PrilchensBTBox", /*bclk=*/GPIO_NUM_25, /*lrclk=*/GPIO_NUM_26, /*din=*/GPIO_NUM_27)) {
    Serial.println("Initialize failed !");
    delay(3000);
  }
  Serial.println("Initialize succeed!");
}

void loop(void) {
  String Title, Artist, Album;
  /**
   * @brief Get "metadata" through AVRC command
   * @param type - The type of metadata to be obtained, and the parameters currently supported:
   * @n     ESP_AVRC_MD_ATTR_TITLE   ESP_AVRC_MD_ATTR_ARTIST   ESP_AVRC_MD_ATTR_ALBUM
   * @return The corresponding type of "metadata"
   * @note Return "NULL" if timeout occurs when requesting metadata
   */
  Title = amplifier.getMetadata(ESP_AVRC_MD_ATTR_TITLE);
  if (0 != Title.length()) {
    Serial.print("Music title: ");
    Serial.println(Title);
  }
  Artist = amplifier.getMetadata(ESP_AVRC_MD_ATTR_ARTIST);
  if (0 != Artist.length()) {
    Serial.print("Music artist: ");
    Serial.println(Artist);
  }
  Album = amplifier.getMetadata(ESP_AVRC_MD_ATTR_ALBUM);
  if (0 != Album.length()) {
    Serial.print("Music album: ");
    Serial.println(Album);
  }

display.clearDisplay();
  display.setCursor(0, 5);
  display.print("Prilchens BL Box");
  display.setCursor(0, 18);
  display.print("Musik Title: ");
  display.setCursor(0, 27);
  display.print(Title);
  display.setCursor(0, 36);
  display.println("Musik Artist: ");
  display.setCursor(0, 45);
  display.println(Artist);
  display.display();

  delay(3000);
}