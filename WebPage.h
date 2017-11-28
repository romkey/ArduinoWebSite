#ifndef ARDUINO_WEB_PAGE_H
#define ARDUINO_WEB_PAGE_H

#include "Arduino.h"
#include <WebSite.h>
#include <HTMLEncodedString.h>

class WebPage {
 public:
  WebPage(WebSite*);
  WebPage(WebSite*, HTMLEncodedString);

  void AddContent(HTMLEncodedString);
  void AddParagraph(HTMLEncodedString);
  void AddHeading(int, HTMLEncodedString);
  void AddList(void);

  String GetHTML(void);

 private:
  WebSite *site;
  String title;
  String content;
};

#endif // ARDUINO_WEB_PAGE_H
