#ifndef ARDUINO_WEB_SITE_H
#define ARDUINO_WEB_SITE_H

#include "Arduino.h"
// #include <WebPage.h>

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
  WebSite(String);
  WebSite(String, String);

  bool AddPageToNav(String, String);
  void AddBrandingImage(unsigned char*);

  struct WebSiteNav *GetNavs(void);

  String nav_bar = String("");
  String branding_image_type;
  String branding_image_base64;

 private:
  String language;
  String name;
  struct WebSiteNav nav;
};

#endif // ARDUINO_WEB_SITE_H
