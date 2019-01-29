/*
 * Modified version of ESP32 HTTPClient Library.
 * 
 * The MIT License (MIT)
 * Copyright (c) 2019 K. Suwatchai (Mobizt)
 * 
 * Copyright (c) 2015 Markus Sattler. All rights reserved.
 * This file is part of the HTTPClient for Arduino.
 * Port to ESP32 by Evandro Luis Copercini (2017), 
 * changed fingerprints to CA verification. 	
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
*/

#ifndef HTTPClientESP32Ex_H_
#define HTTPClientESP32Ex_H_

#include <HTTPClient.h>
#include <Arduino.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

class HTTPClientESP32Ex:public HTTPClient
{
  public:
    HTTPClientESP32Ex();
    ~HTTPClientESP32Ex();
    
    bool http_begin(const char* host, uint16_t port, const char* uri, const char* CAcert);
    bool http_connected(void);
    int http_sendRequest(const char* header, const char* payload);
    WiFiClient* http_getStreamPtr(void);
    uint16_t tcpTimeout = HTTPCLIENT_DEFAULT_TCP_TIMEOUT;

  protected:
    bool http_connect(void);
    bool http_sendHeader(const char* header);
    TransportTraitsPtr http_transportTraits;
    std::unique_ptr<WiFiClient> _tcp;

    char _host[200];
    char _uri[200];
    uint16_t _port = 0;
};



#endif /* HTTPClientESP32Ex_H_ */
