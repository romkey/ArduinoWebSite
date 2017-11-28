#include <WebSite.h>
#include <WebPage.h>
#include <HTMLEncodedString.h>

WebSite::WebSite(void) : WebSite::WebSite("en", String("")) {
}

WebSite::WebSite(String language) : WebSite::WebSite(language, String("")) {
}

WebSite::WebSite(String language1, HTMLEncodedString name1) {
  language = language1;
  name = name1;
  branding_image_type = String("");
  branding_image_base64 = String("");
}

bool WebSite::AddPageToNav(HTMLEncodedString name, String href) {
  if(nav.count >= WEBSITE_MAX_NAV_LINKS) {
    return false;
  }
  
  nav.name[nav.count] = name;
  nav.href[nav.count++] = href;

  nav_bar += String("<li class='nav-item'><a class='nav-link' href='") + String(href) + String("'>") + String(name) + String("</a></li>");

  return true;
}

struct WebSiteNav *WebSite::GetNavs(void) {
  return &nav;
}
