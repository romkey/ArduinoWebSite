/* 
   BootstrapWebSite.h
   Created by John Romkey - https://romkey.com/
   December 6 2017
 */
#ifndef BOOTSTRAP_WEB_SITE_H
#define BOOTSTRAP_WEB_SITE_H

#include <Arduino.h>

#ifndef WEBSITE_MAX_NAV_LINKS
#define WEBSITE_MAX_NAV_LINKS 4
#endif

class BootstrapWebPage;

struct BootstrapWebSiteNav {
  int count = 0;
  String name[WEBSITE_MAX_NAV_LINKS];
  String href[WEBSITE_MAX_NAV_LINKS];;
};

class BootstrapWebSite {
 public:
  BootstrapWebSite(void);
  BootstrapWebSite(String language);
  BootstrapWebSite(String language, String title);

  bool addPageToNav(String name, String link);

  void addBranding(String brandingImageBase64, String brandingImageType);
 private:
  friend class BootstrapWebPage;

  String _language;
  String _name;

  struct BootstrapWebSiteNav _nav;

  String _navBar = String("");
  String _brandingImageBase64 = "";
  String _brandingImageType = "";
};

#endif // BOOTSTRAP_WEB_SITE_H
