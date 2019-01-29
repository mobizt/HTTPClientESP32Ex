# HTTPClientESP32Ex
Customized version of ESP32 HTTPClient Library. To allow custom header and payload string sending for http and https connections.

Thhis library intend to use as part of my Firebase-ESP32 and LineNotify-ESP32 libraries for Arduino for sharable WiFi client.

## Usage

```c++
/**
* Initialization of new http connection.
* \param host - Host name without protocols.
* \param port - Server's port.
* \param uri - The URI of resource.
* \param CAcert - The Base64 encode root certificate string
* \return True as default.
* If no certificate string provided, use (const char*)NULL to CAcert param 
*/
bool http_begin(const char* host, uint16_t port, const char* uri, const char* CAcert);

/**
* Check the http connection status.
* \return True if connected.
*/
bool http_connected();

/**
* Establish http connection if header provided and send it, send payload if provided.
* \param header - The header string (constant chars array).
* \param payload - The payload string (constant chars array), optional.
* \return http status code, Return zero if new http connection and header and/or payload sent 
* with no error or no header and payload provided. If obly payload provided, no new http connection was established.
*/
int http_sendRequest(const char* header, const char* payload);

/**
* Send extra header without making new http connection (if http_sendRequest has been called)
* \param header - The header string (constant chars array).
* \return True if header sending success.
* Need to call http_sendRequest with header first. 
*/
bool http_sendHeader(const char* header);

/**
* Get the WiFi client pointer.
* \return WiFi client pointer.
*/
WiFiClient* http_getStreamPtr(void);


```
