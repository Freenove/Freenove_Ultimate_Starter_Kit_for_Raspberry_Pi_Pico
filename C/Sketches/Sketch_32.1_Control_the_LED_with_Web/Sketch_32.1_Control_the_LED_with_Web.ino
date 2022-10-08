/**********************************************************************
* Filename    : Control the LED with Web
* Description : Make an led blinking.
* Auther      : www.freenove.com
* Modification: 2022/09/27
**********************************************************************/
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "********";
const char* password = "********";

// Set web server port number to 80
WiFiServer server(80);
// Variable to store the HTTP request
String header;
// Auxiliar variables to store the current output state
String PIN_LEDState = "OFF";

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients
  if (client) {                            // If a new client connects,
    Serial.println("New Client.");         // print a message out in the serial port
    String currentLine = "";               // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {  // if there's bytes to read from the client,
        char c = client.read();  // read a byte, then
        Serial.write(c);         // print it out the serial monitor
        header += c;
        if (c == '\n') {  // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // turns the GPIOs on and off
            if (header.indexOf("GET /LED_BUILTIN/ON") >= 0) {
              Serial.println("LED_BUILTIN ON");
              PIN_LEDState = "ON";
              digitalWrite(LED_BUILTIN, HIGH);
            } else if (header.indexOf("GET /LED_BUILTIN/OFF") >= 0) {
              Serial.println("LED_BUILTIN OFF");
              PIN_LEDState = "OFF";
              digitalWrite(LED_BUILTIN, LOW);
            }
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head> <title>Pico W Web Server</title> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html {font-family: Helvetica; display:inline-block; margin: 0px auto; text-align: center;}");
            client.println(" h1{color: #0F3376; padding: 2vh;} p{font-size: 1.5rem;}");
            client.println(".button{background-color: #4286f4; display: inline-block; border: none; border-radius: 4px; color: white; padding: 16px 40px;text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2{background-color: #4286f4;display: inline-block; border: none; border-radius: 4px; color: white; padding: 16px 40px;text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
            // Web Page Heading
            client.println("<body><h1>Pico W Web Server</h1>");
            client.println("<p>GPIO state: " + PIN_LEDState + "</p>");
            client.println("<p><a href=\"/LED_BUILTIN/ON\"><button class=\"button button2\">ON</button></a></p>");
            client.println("<p><a href=\"/LED_BUILTIN/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else {  // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
