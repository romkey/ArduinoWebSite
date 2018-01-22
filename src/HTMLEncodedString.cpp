#include "Arduino.h"
#include "HTMLEncodedString.h"

HTMLEncodedString::HTMLEncodedString(String original) : HTMLEncodedString::HTMLEncodedString(original, true) { }

HTMLEncodedString::HTMLEncodedString(String original, bool encode) {
  if(encode) {
    contents = HTMLEncodedString::encode(original);
  } else {
    contents = original;
  }
}

#ifdef NOOOOOO
HTMLEncodedString::HTMLEncodedString(HTMLEncodedString original) {
  contents = original;
}
#endif

String HTMLEncodedString::getString(void) {
  return contents;
}

// https://stackoverflow.com/questions/5665231/most-efficient-way-to-escape-xml-html-in-c-string
String HTMLEncodedString::encode(String original) {
  String encoded = String("");

  for(size_t pos = 0; pos != original.length(); ++pos) {
     switch(original[pos]) {
    case '&':  encoded += "&amp;";        break;
    case '\"': encoded += "&quot;";       break;
    case '\'': encoded += "&apos;";       break;
    case '<':  encoded += "&lt;";         break;
    case '>':  encoded += "&gt;";         break;
    default:   encoded += original[pos];  break;
    }
  }

  return encoded;
}

