#ifndef ARDUINO_HTML_ENCODED_STRING_H
#define ARDUINO_HTML_ENCODED_STRING_H

#include "Arduino.h"

class HTMLEncodedString : public String {
 public:
  HTMLEncodedString(String);
  HTMLEncodedString(String, bool);

  String getString(void);

  static String encode(String);

 private:
  String contents;
};

#endif /* ARDUINO_HTML_ENCODED_STRING_H */
