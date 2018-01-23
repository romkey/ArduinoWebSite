/* 
   WebSite.h
   Created by John Romkey - https://romkey.com/
   December 6 2017
 */
#ifndef ARDUINO_WEB_SITE_H
#define ARDUINO_WEB_SITE_H

#include <Arduino.h>

#ifndef WEBSITE_MAX_NAV_LINKS
#define WEBSITE_MAX_NAV_LINKS 4
#endif

class WebPage;

struct  WebSiteNav {
  int count = 0;
  String name[WEBSITE_MAX_NAV_LINKS];
  String href[WEBSITE_MAX_NAV_LINKS];;
};


class WebSite {
 public:
  WebSite(void);
  WebSite(String language);
  WebSite(String language, String title);

  bool addPageToNav(String name, String link);

  void addBranding(String brandingImageBase64, String brandingImageType);
 private:
  friend class WebPage;

  String _language;
  String _name;

  struct WebSiteNav _nav;

  String _navBar = String("");
  String _brandingImageBase64 = "";
  String _brandingImageType = "";
};

#endif // ARDUINO_WEB_SITE_H
