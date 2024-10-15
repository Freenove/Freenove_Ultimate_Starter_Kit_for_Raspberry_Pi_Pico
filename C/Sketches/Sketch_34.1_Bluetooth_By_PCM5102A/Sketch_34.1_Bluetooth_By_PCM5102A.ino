#include <BluetoothAudio.h>
#include <PWMAudio.h>

PWMAudio pwm;
A2DPSink a2dp;

// Define a playback state
volatile A2DPSink::PlaybackStatus status = A2DPSink::STOPPED;

// Volume callback function
void volumeCB(void *param, int pct) {
  (void) param;
  Serial.printf("Speaker volume changed to %d%%\n", pct);
}

// Connect callback function
void connectCB(void *param, bool connected) {
  (void) param;
  if (connected) {
    //Print the address of the connected device
    Serial.printf("A2DP connection started to %s\n", bd_addr_to_str(a2dp.getSourceAddress()));
  } else {
    Serial.printf("A2DP connection stopped\n");
  }
}

// Play status callback function
void playbackCB(void *param, A2DPSink::PlaybackStatus state) {
  (void) param;
  status = state;
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  
  Serial.printf("Starting, connect to the PicoW and start playing music\n");
  Serial.printf("Use BOOTSEL to pause/resume playback\n");

  a2dp.setName("PicoW Boom 00:00:00:00:00:00");
  // Set the audio consumer to PWM audio output
  a2dp.setConsumer(new BluetoothAudioConsumerPWM(pwm));
  a2dp.onVolume(volumeCB);
  a2dp.onConnect(connectCB);
  a2dp.onPlaybackStatus(playbackCB);
  a2dp.begin();
}

char *nowPlaying = nullptr;   //Store the name of the currently playing track

void loop() {
  if (BOOTSEL) {
    if (status == A2DPSink::PAUSED) {         // If the playback status is paused
      a2dp.play();                            // play
      Serial.printf("Resuming\n");
    } else if (status == A2DPSink::PLAYING) { // If the playback status is playing
      a2dp.pause();                           // pause
      Serial.printf("Pausing\n");
    }
    while (BOOTSEL);
  }
  if (!nowPlaying || strcmp(nowPlaying, a2dp.trackTitle())) {
    free(nowPlaying);
    nowPlaying = strdup(a2dp.trackTitle());
    Serial.printf("NOW PLAYING: %s\n", nowPlaying);
  }
}
