
// Base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code.
// Enable or disable GxEPD2_GFX base class:
#define ENABLE_GxEPD2_GFX 0


// Include libraries:
//#include <GxEPD2_BW.h>  // Include GxEPD2 library for black and white displays
#include <GxEPD2_3C.h>  // Include GxEPD2 library for 3 color displays
#include <Adafruit_GFX.h>  // Include Adafruit_GFX library

GxEPD2_3C<GxEPD2_750c, GxEPD2_750c::HEIGHT / 4> display(GxEPD2_750c(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 2, /*BUSY=16*/ 5));

// Include fonts from Adafruit_GFX
//#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
//#include <Fonts/FreeMono18pt7b.h>
//#include <Fonts/FreeMono24pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

// Include images:
// We can show images using bitmaps, which usually we store in seperate files
// inside the sketch folder. Those "*.h" files contain the image data.
// We need to include them here to be able to use them.
#include "cryptink2.h"
#include "hackaday_30.h"
#include "supplyframe_30.h"
#include "Arrow_30.h"
#include "Arrow_30_down.h"
#include "BTC1.h"
#include "LTC.h"
#include "DOGE1_DITHER.h"
#include "DOGE1.h"
#include "ADA.h"
#include "ETH_DITHER.h"
#include "BCH1.h"
#include "USDT.h"


float Bitcoin_Price = 10000.00;
String Bitcoin_Change = "xxxxx";    
float Bitcoin_Percent = 0.01;


float LTC_Price = 100.00;
String LTC_Change = "xxxxx";
float LTC_Percent = 10.00;


float DOGE_Price = 0.1;
String DOGE_Change = "xxxxx";
float DOGE_Percent = 1.000;


float ADA_Price = 1.000;
String ADA_Change = "xxxxx";
float ADA_Percent = 10.00;


float ETH_Price = 1000.00;
String ETH_Change = "xxxxx";
float ETH_Percent = 10.00;


float BCH_Price = 100.00;
String BCH_Change = "xxxxx";
float BCH_Percent = 1.000;


float USDT_Price = 1.0001;
String USDT_Change = "xxxxx";
float USDT_Percent = 0.01;



//--------------------Wifi Code----------------------

int countRST = 0;                                                             /* Counting variable for reset function to trigger */
    int ResetPin = 16;                                                            // Have to unpluged the cable to RST pin during uploading code !!! 

    #include <Arduino.h>
    #include <ESP8266WiFi.h>                                                      // library for wifi configuration codes. Need to pre-install the Nodemcu board via board manager             
    #include <ESP8266WiFiMulti.h>
    #include <ESP8266HTTPClient.h>  
    #include <WiFiClient.h>
    
    const char* ssid = "xxx";                                     // key in your wifi-router name (can use handphone to check your wifi full name)
    const char* password =  "xxxx";                                           // key in your wifi-router password
    WiFiClient client;           


const char* host = "api.thingspeak.com";                                      // The main server HTTP BTC1a where you read the website value. If using ThingTHHP app, this value remains
    const int httpPortRead = 80;                                                  /* Port number of the HTTP BTC1a */
    const char* BTCa = "/apps/thinghttp/send_request?api_key=DZHHGW68G722GRCH";    // Bitcoin Price
    const char* BTCb = "/apps/thinghttp/send_request?api_key=VL4911M6MH242JO0";    // Bitcoin change
    const char* BTCc = "/apps/thinghttp/send_request?api_key=ZIU5M5S0M8CE5UR8";    // Bitcoin %

    const char* LTCa = "/apps/thinghttp/send_request?api_key=BFTGXM9EZEQ4J0S3";    // Litecoin Price
    const char* LTCb = "/apps/thinghttp/send_request?api_key=C1PEJ511V9L4PB31";    // Litecoin change
    const char* LTCc = "/apps/thinghttp/send_request?api_key=ZD65GBZLRYCJ2VF0";    // Litecoin %

    
    const char* DOGEa = "/apps/thinghttp/send_request?api_key=8YW4VAIILDSFOJSW";    // DOGEcoin Price
    const char* DOGEb = "/apps/thinghttp/send_request?api_key=VTEC5FX07UCD8H88";    // DOGEcoin change
    const char* DOGEc = "/apps/thinghttp/send_request?api_key=CD1VY31ZK1SW06US";    // DOGEcoin %

    const char* ADAa = "/apps/thinghttp/send_request?api_key=KDY3I8AGDCCO50LH";    // Cardano Price
    const char* ADAb = "/apps/thinghttp/send_request?api_key=LP88T7APRFQERTTG";    // Cardano change
    const char* ADAc = "/apps/thinghttp/send_request?api_key=VDEX9338QL0BOQKG";    // Cardano %

    const char* ETHa = "/apps/thinghttp/send_request?api_key=C4P31PRMKCXL3J14";    // Ethereum Price
    const char* ETHb = "/apps/thinghttp/send_request?api_key=I388QC7ZJJYMUJ4T";    // Ethereum change
    const char* ETHc = "/apps/thinghttp/send_request?api_key=NOQ246E1OPYU78BD";    // Ethereum %

    const char* BCHa = "/apps/thinghttp/send_request?api_key=6SFWFXXUS6BA2FRT";    // BITCOIN Cash Price
    const char* BCHb = "/apps/thinghttp/send_request?api_key=DL89NLXBWR6CCOD9";    // BITCOIN Cash change
    const char* BCHc = "/apps/thinghttp/send_request?api_key=3OAN3428FHEXQT0U";    // BITCOIN Cash %

    const char* USDTa = "/apps/thinghttp/send_request?api_key=NN2MIIVPK36X9MVQ";    // Tether Cash Price
    const char* USDTb = "/apps/thinghttp/send_request?api_key=II4UZRIFL2VQSJQT";    // Tether Cash change
    const char* USDTc = "/apps/thinghttp/send_request?api_key=V1L8JE9AABHYWCDA";    // Tether Cash %
    

    
    HTTPClient http;                                                              /* define the Node MCU variable for HTTP communication*/
    //HTTPClient http2;                                                           // 1 value or 1 http can only read for 1 channel. 
                                                                                  // If you need to read more than 1 value, you have to add more variables: http1,http2....
                                                                               // If you need to read more than 1 value, you have to add more variables: f1, f2...

//--------------------Wifi Code----------------------



void setup()  // Start of setup
{
//--------------------Wifi Code----------------------

Serial.begin(115200);                                                           /* initiate Serial monitor with baud rate 9600 */

          
    pinMode(ResetPin, OUTPUT);                                                    /* to define pin as output function */
    digitalWrite(ResetPin, HIGH);                                                 /* set pin as high output */


    /* 1- WSP8266 WiFi connection */
    
    WiFi.disconnect();                                                            /* disconnects any previous Wifi connection*/
    delay(1000);                                                                  /* wait for 1 second */
    WiFi.begin(ssid, password);                                                   /* initiate Wifi connection with your router */
    while (WiFi.status() != WL_CONNECTED)                                         /* if connection not completed, keep run the codes */
      {   
        delay(1000); Serial.println("Connecting to WiFi.."); 
            
        /* 0- Reset Board */ 
        
        countRST = countRST + 1;                                                  /* add counting time, if waited too long (by default 1 minute), reset the board */
        if (countRST == 60)
        { digitalWrite(ResetPin, LOW); countRST = 0; }  
      }
    Serial.println("Connected to the WiFi network");                              /* once connection completed, continue do the following */              
    Serial.println(WiFi.localIP());                                               /* print IP address of Node Mcu on Serial Monitor */
  

//--------------------Wifi Code----------------------

  
  display.init(115200);  // Initiate the display
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  
  
}  

void loop()  // Start of loop
{



//--------------------Wifi Code----------------------
   countRST = 0;                                                                  /* use to trigger reset board if connection takes too long*/
   
    /* 1- WSP8266 WiFi connection */
          
    while (WiFi.status() != WL_CONNECTED)                                         /* if wifi connection not completed or disconnection */
      { 
        if(countRST ==0)                                                          /* for the first time if disconnection detected*/
        {
        WiFi.disconnect();                                                        /* disconnect any previous connection*/
        delay(1000);                                                              /* wait for 1 second*/
        }
        WiFi.begin(ssid, password);                                               /* initiate Wifi connection with your router */
        Serial.println("Reconnecting to WiFi..");       
        delay(20000);                                                             /* let it has 20 second time for processing */
            
        /* 0- Reset Board */
            
        countRST = countRST + 1;                                                  /* record how many times keep trying to connect*/ 
        if (countRST == 15)                                                       /* if waited too long (by default 5 minutes has reached)*/ 
        { digitalWrite(ResetPin, LOW); countRST = 0; }                            /* reset the board */
      }


    /* 2- Read URI from ThingSpeak ThingHTTP to NodeMCU */
    
    while(!client.connect(host,httpPortRead))                                     /* if failed to connect to the web server*/
      {
        client.connect(host, httpPortRead);                                       /* tries to connect to server*/
        countRST = countRST + 1;                                                  /* record how many tries*/
        delay(10000);                                                             /* wait for 10 seconds*/
        if (countRST == 30)                                                       /* if waited too long (by default 5 minutes has reached)*/
          { 
            WiFi.disconnect();                                                    /* disconnect wifi*/
            delay(2000);                                                          /* wait 2 seconds*/
            WiFi.begin(ssid, password);                                           /* start connect wifi again*/
            countRST = 0;                                                         /*reset the counting time*/
          }
      }

//--------------------------BTC-------------------------------------

 
    if( http.begin(client, host,httpPortRead,BTCa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              Bitcoin_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(Bitcoin_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,BTCb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              Bitcoin_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(Bitcoin_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,BTCc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              Bitcoin_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(Bitcoin_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
//--------------------------BTC-------------------------------------

//--------------------------LTC-------------------------------------
 
    if( http.begin(client, host,httpPortRead,LTCa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              LTC_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(LTC_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,LTCb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              LTC_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(LTC_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,LTCc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              LTC_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(LTC_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
//--------------------------LTC-------------------------------------

//--------------------------DOGE-------------------------------------
    if( http.begin(client, host,httpPortRead,DOGEa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              DOGE_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(DOGE_Price,3);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,DOGEb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              DOGE_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(DOGE_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,DOGEc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              DOGE_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(DOGE_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
//--------------------------DOGE-------------------------------------

//--------------------------ADA-------------------------------------
    if( http.begin(client, host,httpPortRead,ADAa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ADA_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ADA_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,ADAb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ADA_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ADA_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,ADAc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ADA_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ADA_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

//--------------------------ADA-------------------------------------

//--------------------------ETH------------------------------------
    if( http.begin(client, host,httpPortRead,ETHa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ETH_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ETH_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,ETHb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ETH_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ETH_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,ETHc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              ETH_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(ETH_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 


//--------------------------ETH-------------------------------------

//--------------------------BCH-------------------------------------
    if( http.begin(client, host,httpPortRead,BCHa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              BCH_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(BCH_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,BCHb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              BCH_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(BCH_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,BCHc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              BCH_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(BCH_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

//--------------------------BCH-------------------------------------

//--------------------------USDT-------------------------------------
    if( http.begin(client, host,httpPortRead,USDTa))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              USDT_Price = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(USDT_Price,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 
      
    if( http.begin(client, host,httpPortRead,USDTb))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
               String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              //payload.replace("$"  $  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              USDT_Change = payload;                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(USDT_Change);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 

if( http.begin(client, host,httpPortRead,USDTc))                                              // If the connection is ok for first value, for more values this set of code need to duplicate
      {
        int httpCode = http.GET();                                                      /* Check HTTP return code*/
        if (httpCode > 0)                                                               /* If return code is good*/
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {
              
              String payload = http.getString();                                        /* get the return value in string*/                                                     
              //Serial.println(payload);                                                  /* display the raw values get from API link */
              payload.replace(","  ,  "");                                              /* replace comma with nothing, means delete the comma so that can be convert to float value*/
              USDT_Percent = payload.toFloat();                                                   /* convert string to float value. All values after a blank space will automatically deleted */
              Serial.println(USDT_Percent,2);                                                     /* display the final values which to be displayed on ThingSpeak channel later*/
            }
        }
        else 
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();                                                                 /* after Read and Write codes are completed, close the http connection*/
      } 


//--------------------------USDT-------------------------------------


    else 
      {
        Serial.printf("[HTTP} Unable to connect\n");
      }



//--------------------Wifi Code----------------------



 
  display.setFullWindow();  // Set full window mode, meaning is going to update the entire screen
  display.firstPage();  // Tell the graphics class to use paged drawing mode
  do
  { 
    display.setRotation(1);
    display.fillScreen(GxEPD_WHITE);  // Clear previous graphics to start over to print new things.
    
      ///-----------------GRID------------- 
    //display.fillRect(0,0,10,3,GxEPD_BLACK);    
    display.fillRect(0,65,384,5,GxEPD_BLACK); 
    display.fillRect(0,142,384,5,GxEPD_BLACK); 
    display.fillRect(0,219,384,5,GxEPD_BLACK); 
    display.fillRect(0,296,384,5,GxEPD_BLACK); 
    display.fillRect(0,373,384,5,GxEPD_BLACK);
    display.fillRect(0,450,384,5,GxEPD_BLACK);
    display.fillRect(0,527,384,5,GxEPD_BLACK);  
    display.fillRect(0,604,384,5,GxEPD_BLACK);    
    //display.fillRect(0,105,384,2,GxEPD_RED);  // Draw rectangle (x,y,width,height,color)
    //display.fillRect(0,142,384,5,GxEPD_BLACK); 
    //display.fillRect(160,65,1,77,GxEPD_BLACK);  
    //display.fillRect(200,65,1,77,GxEPD_RED);  
    //display.fillRect(310,65,1,77,GxEPD_BLACK); 
   ///-----------------GRID-------------
    
    
    // Format: (POSITION_X, POSITION_Y, IMAGE_NAME, IMAGE_WIDTH, IMAGE_HEIGHT, COLOR)
    // Color options are GxEPD_BLACK, GxEPD_WHITE, GxEPD_RED
    //384x53 
    display.drawBitmap(2,2, gImage_cryptink2, 384,53, GxEPD_RED);   
    display.drawBitmap(0,0, gImage_cryptink2, 384,53, GxEPD_BLACK);  // Print YouTube logo - Black part (POSITION_X, POSITION_Y, IMAGE_NAME, IMAGE_WIDTH, IMAGE_HEIGHT, COLOR)
    display.drawBitmap(324,609, gImage_hackaday_30, 30,30, GxEPD_BLACK);
    display.setCursor(150, 630);  // Set the position to start printing text (x,y)
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.print("Sponsored by");  // Print some text
    display.drawBitmap(354,609, gImage_supplyframe_30, 30,30, GxEPD_BLACK);

 //*********************************BITCOIN ***************************************************
 if(Bitcoin_Percent >= 0)
 {
 //------------------------------BITCOIN UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,70, gImage_BTC1, 72,72, GxEPD_BLACK);
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 116);  // Set the position to start printing text (x,y)
    display.print("BTC");  // Print some text
//------------Bitcoin PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 98);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(Bitcoin_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 98);  // Set the position to start printing text (x,y)
    if (Bitcoin_Price >= 1000000 && Bitcoin_Price < 10000000) display.print(" ,  ,");;
    if (Bitcoin_Price >= 100000 && Bitcoin_Price < 1000000) display.print("   ,");;
    if (Bitcoin_Price >= 10000 && Bitcoin_Price < 100000) display.print("  ,");;
    if (Bitcoin_Price >= 1000 && Bitcoin_Price < 10000) display.print(" ,");;    
//------------Bitcoin Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 130);
    //display.print("$");  // Print some text
    display.print(Bitcoin_Change);  // Print some text
//------------Bitcoin Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 130);
    display.print(Bitcoin_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,110, gImage_Arrow_30, 30,30, GxEPD_BLACK);

 }

 if(Bitcoin_Percent < 0)
 {
 //------------------------------BITCOIN DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,70, gImage_BTC1, 72,72, GxEPD_RED);
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 116);  // Set the position to start printing text (x,y)
    display.print("BTC");  // Print some text
//------------Bitcoin PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 98);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(Bitcoin_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 98);  // Set the position to start printing text (x,y)
    if (Bitcoin_Price >= 1000000 && Bitcoin_Price < 10000000) display.print(" ,  ,");;
    if (Bitcoin_Price >= 100000 && Bitcoin_Price < 1000000) display.print("   ,");;
    if (Bitcoin_Price >= 10000 && Bitcoin_Price < 100000) display.print("  ,");;
    if (Bitcoin_Price >= 1000 && Bitcoin_Price < 10000) display.print(" ,");;    
//------------Bitcoin Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 130);
    //display.print("$");  // Print some text
    display.print(Bitcoin_Change);  // Print some text 
//------------Bitcoin Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 130);
    display.print(Bitcoin_Percent,1);  // Print some text
    display.print("%");
    //------------AAROW DOWN--------------------------
    display.drawBitmap(165,110, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }




 //*********************************LITECOIN ***************************************************
 if(LTC_Percent >= 0)
 {
 //------------------------------LITECOIN UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,147, gImage_LTC, 72,72, GxEPD_BLACK);
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 193);  // Set the position to start printing text (x,y)
    display.print("LTC");  // Print some text
//------------LITECOIN PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 175);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(LTC_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 175);  // Set the position to start printing text (x,y)
    if (LTC_Price >= 1000000 && LTC_Price < 10000000) display.print(" ,  ,");;
    if (LTC_Price >= 100000 && LTC_Price < 1000000) display.print("   ,");;
    if (LTC_Price >= 10000 && LTC_Price < 100000) display.print("  ,");;
    if (LTC_Price >= 1000 && LTC_Price < 10000) display.print(" ,");;    
//------------LITECOIN Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 207);
    //display.print("$");  // Print some text
    display.print(LTC_Change);  // Print some text
//------------LITECOIN Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 207);
    display.print(LTC_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,187, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

 if(LTC_Percent < 0)
  {
 //------------------------------LITECOIN DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,147, gImage_LTC, 72,72, GxEPD_RED);
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 193);  // Set the position to start printing text (x,y)
    display.print("LTC");  // Print some text
//------------LITECOIN PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 175);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(LTC_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 9175);  // Set the position to start printing text (x,y)
    if (LTC_Price >= 1000000 && LTC_Price < 10000000) display.print(" ,  ,");;
    if (LTC_Price >= 100000 && LTC_Price < 1000000) display.print("   ,");;
    if (LTC_Price >= 10000 && LTC_Price < 100000) display.print("  ,");;
    if (LTC_Price >= 1000 && LTC_Price < 10000) display.print(" ,");;    
//------------LITECOIN Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 207);
    //display.print("$");  // Print some text
    display.print(LTC_Change);  // Print some text
//------------LITECOIN Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 207);
    display.print(LTC_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,187, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }

 //*********************************DOGECOIN ***************************************************
 if(DOGE_Percent >= 0)
 {
 //------------------------------DOGECOIN UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawCircle(36, 260, 36, GxEPD_BLACK); // Coin outline For DOGE
    display.drawBitmap(1,224, gImage_DOGE1_DITHER, 72,72, GxEPD_BLACK); 
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 270);  // Set the position to start printing text (x,y)
    display.print("DOGE");  // Print some text
//------------DOGECOIN PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 252);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(DOGE_Price,3);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 252);  // Set the position to start printing text (x,y)
    if (DOGE_Price >= 1000000 && DOGE_Price < 10000000) display.print(" ,  ,");;
    if (DOGE_Price >= 100000 && DOGE_Price < 1000000) display.print("   ,");;
    if (DOGE_Price >= 10000 && DOGE_Price < 100000) display.print("  ,");;
    if (DOGE_Price >= 1000 && DOGE_Price < 10000) display.print(" ,");;    
//------------DOGECOIN Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 284);
    //display.print("$");  // Print some text
    display.print(DOGE_Change);  // Print some text
//------------DOGECOIN Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 284);
    display.print(DOGE_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,264, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

 if(DOGE_Percent < 0)
 {
 //------------------------------DOGECOIN DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawCircle(36, 260, 36, GxEPD_RED); // Coin outline For DOGE
    display.drawBitmap(1,224, gImage_DOGE1_DITHER, 72,72, GxEPD_RED); 
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 270);  // Set the position to start printing text (x,y)
    display.print("DOGE");  // Print some text
//------------DOGECOIN PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 252);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(DOGE_Price,3);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 252);  // Set the position to start printing text (x,y)
    if (DOGE_Price >= 1000000 && DOGE_Price < 10000000) display.print(" ,  ,");;
    if (DOGE_Price >= 100000 && DOGE_Price < 1000000) display.print("   ,");;
    if (DOGE_Price >= 10000 && DOGE_Price < 100000) display.print("  ,");;
    if (DOGE_Price >= 1000 && DOGE_Price < 10000) display.print(" ,");;    
//------------DOGECOIN Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 284);
    //display.print("$");  // Print some text
    display.print(DOGE_Change);  // Print some text
//------------DOGECOIN Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 284);
    display.print(DOGE_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,264, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }

//*********************************ADA ***************************************************
 if(ADA_Percent >= 0)
 {
 //------------------------------ADA UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,301, gImage_ADA, 72,72, GxEPD_BLACK);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 347);  // Set the position to start printing text (x,y)
    display.print("ADA");  // Print some text
//------------cardano PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 329);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(ADA_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 329);  // Set the position to start printing text (x,y)
    if (ADA_Price >= 1000000 && ADA_Price < 10000000) display.print(" ,  ,");;
    if (ADA_Price >= 100000 && ADA_Price < 1000000) display.print("   ,");;
    if (ADA_Price >= 10000 && ADA_Price < 100000) display.print("  ,");;
    if (ADA_Price >= 1000 && ADA_Price < 10000) display.print(" ,");;    
//------------cardano Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 361);
    //display.print("$");  // Print some text
    display.print(ADA_Change);  // Print some text
//------------cardano Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 361);
    display.print(ADA_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,341, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

 if(ADA_Percent < 0)
 {
 //------------------------------ADA DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,301, gImage_ADA, 72,72, GxEPD_RED);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 347);  // Set the position to start printing text (x,y)
    display.print("ADA");  // Print some text
//------------cardano PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 329);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(ADA_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 329);  // Set the position to start printing text (x,y)
    if (ADA_Price >= 1000000 && ADA_Price < 10000000) display.print(" ,  ,");;
    if (ADA_Price >= 100000 && ADA_Price < 1000000) display.print("   ,");;
    if (ADA_Price >= 10000 && ADA_Price < 100000) display.print("  ,");;
    if (ADA_Price >= 1000 && ADA_Price < 10000) display.print(" ,");;    
//------------cardano Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 361);
    //display.print("$");  // Print some text
    display.print(ADA_Change);  // Print some text
//------------cardano Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 361);
    display.print(ADA_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,341, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }


//*********************************Ethereum ***************************************************
 if(ETH_Percent >= 0)
 {
 //------------------------------Ethereum UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,378, gImage_ETH_DITHER, 72,72, GxEPD_BLACK);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 424);  // Set the position to start printing text (x,y)
    display.print("ETH");  // Print some text
//------------Ethereum PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 406);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(ETH_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 406);  // Set the position to start printing text (x,y)
    if (ETH_Price >= 1000000 && ETH_Price < 10000000) display.print(" ,  ,");;
    if (ETH_Price >= 100000 && ETH_Price < 1000000) display.print("   ,");;
    if (ETH_Price >= 10000 && ETH_Price < 100000) display.print("  ,");;
    if (ETH_Price >= 1000 && ETH_Price < 10000) display.print(" ,");;    
//------------Ethereum Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 438);
    //display.print("$");  // Print some text
    display.print(ETH_Change);  // Print some text
//------------Ethereum Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 438);
    display.print(ETH_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,418, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

if(ETH_Percent < 0)
 {
 //------------------------------Ethereum DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,378, gImage_ETH_DITHER, 72,72, GxEPD_RED);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 424);  // Set the position to start printing text (x,y)
    display.print("ETH");  // Print some text
//------------Ethereum PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 406);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(ETH_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 406);  // Set the position to start printing text (x,y)
    if (ETH_Price >= 1000000 && ETH_Price < 10000000) display.print(" ,  ,");;
    if (ETH_Price >= 100000 && ETH_Price < 1000000) display.print("   ,");;
    if (ETH_Price >= 10000 && ETH_Price < 100000) display.print("  ,");;
    if (ETH_Price >= 1000 && ETH_Price < 10000) display.print(" ,");;    
//------------Ethereum Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 438);
    //display.print("$");  // Print some text
    display.print(ETH_Change);  // Print some text
//------------Ethereum Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 438);
    display.print(ETH_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,418, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }

//*********************************BITCOIN CASH ***************************************************
 if(BCH_Percent >= 0)
 {
 //------------------------------BITCOIN CASH UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,455, gImage_BCH1, 72,72, GxEPD_BLACK);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 501);  // Set the position to start printing text (x,y)
    display.print("BCH");  // Print some text
//------------BITCOIN CASH PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 483);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(BCH_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 483);  // Set the position to start printing text (x,y)
    if (BCH_Price >= 1000000 && BCH_Price < 10000000) display.print(" ,  ,");;
    if (BCH_Price >= 100000 && BCH_Price < 1000000) display.print("   ,");;
    if (BCH_Price >= 10000 && BCH_Price < 100000) display.print("  ,");;
    if (BCH_Price >= 1000 && BCH_Price < 10000) display.print(" ,");;    
//------------BITCOIN CASH Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 515);
    //display.print("$");  // Print some text
    display.print(BCH_Change);  // Print some text
//------------BITCOIN CASH Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 515);
    display.print(BCH_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,495, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

if(BCH_Percent < 0)
 {
 //------------------------------BITCOIN CASH DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,455, gImage_BCH1, 72,72, GxEPD_RED);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 501);  // Set the position to start printing text (x,y)
    display.print("BCH");  // Print some text
//------------BITCOIN CASH PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 483);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(BCH_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 483);  // Set the position to start printing text (x,y)
    if (BCH_Price >= 1000000 && BCH_Price < 10000000) display.print(" ,  ,");;
    if (BCH_Price >= 100000 && BCH_Price < 1000000) display.print("   ,");;
    if (BCH_Price >= 10000 && BCH_Price < 100000) display.print("  ,");;
    if (BCH_Price >= 1000 && BCH_Price < 10000) display.print(" ,");;    
//------------BITCOIN CASH Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 515);
    //display.print("$");  // Print some text
    display.print(BCH_Change);  // Print some text
//------------BITCOIN CASH Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 515);
    display.print(BCH_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,495, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }


//*********************************TETHER ***************************************************
 if(USDT_Percent >= 0)
 {
 //------------------------------TETHER UP----------------------------------------
    display.setTextColor(GxEPD_BLACK);  // Set color for text
    display.drawBitmap(1,532, gImage_USDT, 72,72, GxEPD_BLACK);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 578);  // Set the position to start printing text (x,y)
    display.print("USDT");  // Print some text
//------------TETHER PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 560);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(USDT_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 560);  // Set the position to start printing text (x,y)
    if (USDT_Price >= 1000000 && USDT_Price < 10000000) display.print(" ,  ,");;
    if (USDT_Price >= 100000 && USDT_Price < 1000000) display.print("   ,");;
    if (USDT_Price >= 10000 && USDT_Price < 100000) display.print("  ,");;
    if (USDT_Price >= 1000 && USDT_Price < 10000) display.print(" ,");;    
//------------TETHER Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 592);
    //display.print("$");  // Print some text
    display.print(USDT_Change);  // Print some text
//------------TETHER Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 592);
    display.print(USDT_Percent,1);  // Print some text
    display.print("%");
//------------AAROW UP--------------------------
    display.drawBitmap(165,572, gImage_Arrow_30, 30,30, GxEPD_BLACK);
 }

 if(USDT_Percent < 0)
 {
 //------------------------------TETHER DOWN----------------------------------------
    display.setTextColor(GxEPD_RED);  // Set color for text
    display.drawBitmap(1,532, gImage_USDT, 72,72, GxEPD_RED);   
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(75, 578);  // Set the position to start printing text (x,y)
    display.print("USDT");  // Print some text
//------------TETHER PRICE--------------------------
    display.setFont(&FreeMonoBold18pt7b);  // Set font
    display.setCursor(163, 560);  // Set the position to start printing text (x,y)
    display.print("$");  // Print some text
    display.print(USDT_Price,2);  // Print some text
//------------adding commas PRICE--------------------------
    display.setCursor(175, 560);  // Set the position to start printing text (x,y)
    if (USDT_Price >= 1000000 && USDT_Price < 10000000) display.print(" ,  ,");;
    if (USDT_Price >= 100000 && USDT_Price < 1000000) display.print("   ,");;
    if (USDT_Price >= 10000 && USDT_Price < 100000) display.print("  ,");;
    if (USDT_Price >= 1000 && USDT_Price < 10000) display.print(" ,");;    
//------------TETHER Change--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(200, 592);
    //display.print("$");  // Print some text
    display.print(USDT_Change);  // Print some text
//------------TETHER Percent--------------------------
    display.setFont(&FreeMonoBold9pt7b);  // Set font
    display.setCursor(325, 592);
    display.print(USDT_Percent,1);  // Print some text
    display.print("%");
//------------AAROW DOWN--------------------------
    display.drawBitmap(165,572, gImage_Arrow_30_down, 30,30, GxEPD_RED);
 }








  }
  
  while (display.nextPage());  // Print everything we set previously
  // End of screen 2
  int delay_min = 10;
  //delay(delay_min*60*60*1000);
  ESP.deepSleep(60e7);
}  
