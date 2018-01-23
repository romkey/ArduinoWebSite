#include <WebSite.h>
#include <WebPage.h>

WebSite::WebSite(void) : WebSite::WebSite("en", "") {
}

WebSite::WebSite(String language) : WebSite::WebSite(language, "") {
}

WebSite::WebSite(String language1, String name1) {
  _language = language1;
  _name = name1;
}

bool WebSite::addPageToNav(String name, String href) {
  if(_nav.count >= WEBSITE_MAX_NAV_LINKS) {
    return false;
  }
  
  _nav.name[_nav.count] = name;
  _nav.href[_nav.count++] = href;

  _navBar += String("<li class='nav-item'><a class='nav-link' href='") + String(href) + String("'>") + String(name) + String("</a></li>");

  return true;
}

void WebSite::addBranding(String brandingImageBase64, String brandingImageType) {
  _brandingImageBase64 = brandingImageBase64;
  _brandingImageType = brandingImageType;
}
