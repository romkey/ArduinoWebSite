#include <WebSite.h>
#include <WebPage.h>

WebPage::WebPage(WebSite *site1) : WebPage::WebPage(site1, "") { };

WebPage::WebPage(WebSite *site1, String title1) {
  site = site1;
  title = WebPage::HTMLEncode(title1);
}

void WebPage::AddContent(String new_content) {
  content += new_content;
}

String WebPage::GetHTML() {
  return String("<html lang='en'><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1'><link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css'>") +
    String( title == "" ? "" : "<title>" + title + "</title>") +
    String("</head><body><div class='container'><nav class='navbar navbar-expand-lg navbar-light bg-light'><ul class='navbar-nav mr-auto'>") +
    (site->branding_image_base64 == String("") ? String("") : String("<a class='navbar-brand' href='/'><image src='data:\"") + site->branding_image_type + String("\";base64,") + site->branding_image_base64 + String("' height=23 width=23></a>")) + 
    site->nav_bar +
    String("</ul></nav>") +
    content +
    String("</div><script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js'></body></html>");
}

void WebPage::AddHeading(int level, String text) {
  content += "<H" + String(level) + ">" + WebPage::HTMLEncode(text) + "</H" + String(level) + ">";
}

void WebPage::AddParagraph(String text) {
  content += "<P>" + WebPage::HTMLEncode(text) + "</P>";
}

// from https://stackoverflow.com/questions/5665231/most-efficient-way-to-escape-xml-html-in-c-string
String WebPage::HTMLEncode(String original) {
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
