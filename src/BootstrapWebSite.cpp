#include <BootstrapWebSite.h>
#include <BootstrapWebPage.h>

BootstrapWebSite::BootstrapWebSite(void) : BootstrapWebSite::BootstrapWebSite("en", "") {
}

BootstrapWebSite::BootstrapWebSite(String language) : BootstrapWebSite::BootstrapWebSite(language, "") {
}

BootstrapWebSite::BootstrapWebSite(String language1, String name1) {
  _language = language1;
  _name = name1;
}

bool BootstrapWebSite::addPageToNav(String name, String href) {
  if(_nav.count >= WEBSITE_MAX_NAV_LINKS) {
    return false;
  }
  
  _nav.name[_nav.count] = name;
  _nav.href[_nav.count++] = href;

  _navBar += String("<li class='nav-item'><a class='nav-link' href='") + String(href) + String("'>") + String(name) + String("</a></li>");

  return true;
}

void BootstrapWebSite::addBranding(String brandingImageBase64, String brandingImageType) {
  _brandingImageBase64 = brandingImageBase64;
  _brandingImageType = brandingImageType;
}
