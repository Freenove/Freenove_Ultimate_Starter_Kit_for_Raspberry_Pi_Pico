#include <Arduino.h>
#include <WiFi.h>
#include "AudioFileSourceLittleFS.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

AudioGeneratorMP3 *mp3;
AudioFileSourceLittleFS *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

// Called when a metadata event occurs (i.e. an ID3 tag, an ICY block, etc.)
void MDCallback(void *cbData, const char *type, bool isUnicode, const char *string)
{
  (void)cbData;
  Serial.printf("ID3 callback for: %s = '", type);

  if (isUnicode) {
    string += 2;
  }
  
  while (*string) {
    char a = *(string++);
    if (isUnicode) {
      string++;
    }
    Serial.printf("%c", a);
  }
  Serial.printf("'\n");
  Serial.flush();
}

void setup()
{
  WiFi.mode(WIFI_OFF);
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Sample MP3 playback begins...\r\n");

  audioLogger = &Serial;
  out = new AudioOutputI2S();
  out->SetPinout(6,7,8);//Set the pins for IIS(BCK,LCK,DIN)
  out->SetGain(0.5);//Volume range: 0-3.9
  file = new AudioFileSourceLittleFS("1.mp3");
  id3 = new AudioFileSourceID3(file);
  id3->RegisterMetadataCB(MDCallback, (void*)"ID3TAG");
  mp3 = new AudioGeneratorMP3();
  mp3->begin(id3, out);
}

void loop()
{
  if (mp3->isRunning()) {
    if (!mp3->loop()) mp3->stop();
  } else {
    Serial.printf("MP3 done\r\n");
    delay(1000);
  }
}
