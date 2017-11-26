#ifndef ARDUINO_WEB_PAGE_H
#define ARDUINO_WEB_PAGE_H

#include "Arduino.h"
#include <WebSite.h>

class WebPage {
 public:
  WebPage(WebSite*);
  WebPage(WebSite*, String);

  void AddContent(String);
  void AddParagraph(String);
  void AddHeading(int, String);
  void AddList(void);

  String GetHTML(void);
  String HTMLEncode(String);

 private:
  WebSite *site;
  String title;
  String content;
};

#endif // ARDUINO_WEB_PAGE_H
