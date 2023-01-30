#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Название Wi-Fi
const char* ssid = "RT-WiFi-0BD7";
// Пароль Wi-Fi
const char* password =  "xA8tVcikUh";
// Открывает порт для веб-сервера
ESP8266WebServer HTTP(80); 

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  // Проверка подключения к сети
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("[ WiFi ] Connecting..");
  }
  
  // Запрос IP адреса
  Serial.print("[ WiFi ] IP: ");
  Serial.print(WiFi.localIP());
  
  // Инициализируем веб-сервер
  HTTP.begin();

  // Настройка светодиода
  pinMode(D4, OUTPUT);

  // Обработка HTTP-запросов
  HTTP.on("/on", [](){
    Serial.println("[ HTTP ] ON");
    pinMode(D4, HIGH);
  });
  HTTP.on("/off", [](){
    Serial.println("[ HTTP ] OFF");
    pinMode(D4, LOW);
  });
}

void loop() {
  HTTP.handleClient(); 
}