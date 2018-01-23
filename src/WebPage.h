/* 
   WebPage.h
   Created by John Romkey - https://romkey.com/
   December 6 2017

   MIT License
 */
#ifndef ARDUINO_WEB_PAGE_H
#define ARDUINO_WEB_PAGE_H

#include <Arduino.h>
#include <WebSite.h>

class WebPage {
 public:
  WebPage(WebSite* webSite);
  WebPage(WebSite* webSite, String title);

  void addContent(String content);
  void addHeading(String heading, int level);
  void addHeading(String heading) { addHeading(heading, 1); };
  void addParagraph(String text);

  void addList(String item) { addList(item, "", "", "", "", "", "", "", "", ""); };
  void addList(String item1, String item2) { addList(item1, item2, "", "", "", "", "", "", "", ""); };
  void addList(String item1, String item2, String item3) { addList(item1, item2, item3, "", "", "", "", "", "", ""); };
  void addList(String item1, String item2, String item3, String item4) { addList(item1, item2, item3, item4, "", "", "", "", "", ""); };
  void addList(String item1, String item2, String item3, String item4, String item5) { addList(item1, item2, item3, item4, item5, "", "", "", "", ""); };
  void addList(String item1, String item2, String item3, String item4, String item5, String item6) { addList(item1, item2, item3, item4, item5, item6, "", "", "", ""); };
  void addList(String item1, String item2, String item3, String item4, String item5, String item6, String item7) { addList(item1, item2, item3, item4, item5, item6, item7, "", "", ""); };
  void addList(String item1, String item2, String item3, String item4, String item5, String item6, String item7, String item8) { addList(item1, item2, item3, item4, item5, item6, item7, item8, "", ""); };
  void addList(String item1, String item2, String item3, String item4, String item5, String item6, String item7, String item8, String item9) { addList(item1, item2, item3, item4, item5, item6, item7, item8, item9, ""); };
  void addList(String item1, String item2, String item3, String item4, String item5, String item6, String item7, String item8, String item9, String item10);

  String listItem(String item);

  String getHTML(void);

 private:
  WebSite *_site;
  String _title;
  String _content;
};

#endif // ARDUINO_WEB_PAGE_H
