#include <BootstrapWebSite.h>
#include <BootstrapWebPage.h>

BootstrapWebPage::BootstrapWebPage(BootstrapWebSite* site) : BootstrapWebPage::BootstrapWebPage(site, "") { };

BootstrapWebPage::BootstrapWebPage(BootstrapWebSite* site, String title) {
  _site = site;
  _title = title;
}

void BootstrapWebPage::addContent(String content) {
  _content += content;
}

void BootstrapWebPage::addHeading(String heading, int level) {
  _content += "<H1>" + heading + "</H1>";
}

void BootstrapWebPage::addParagraph(String text) {
  _content += "<p>" + text + "</p>";
}

void BootstrapWebPage::addLink(String url, String content) {
  _content += "<a href='" + url + "'>" + content + "</a>";
}

String BootstrapWebPage::getHTML() {
  return String("<html lang='en'><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1'><link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css'>" +
		( _title == "" ? "" : "<title>" + _title + "</title>") +
		"</head><body><div class='container'><nav class='navbar navbar-expand-lg navbar-light bg-light'><ul class='navbar-nav mr-auto'>" +
		( _site->_brandingImageBase64 == "" ? "" : "<a class='navbar-brand' href='#'><image src='data:\"" + _site->_brandingImageType + "\";base64," + _site->_brandingImageBase64 + "' height=23 width=23></a>") +
		_site->_navBar +
		"</ul></nav>" +
		_content +
		"</div><script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js'></body></html>");
}

void BootstrapWebPage::addList(String item1, String item2, String item3, String item4, String item5, String item6, String item7, String item8, String item9, String item10) {
  _content += String("<ul class='list-group'>") +
    ( item1.length() ? BootstrapWebPage::listItem(item1) : "" ) +
    ( item2.length() ? BootstrapWebPage::listItem(item2) : "" ) +
    ( item3.length() ? BootstrapWebPage::listItem(item3) : "" ) +
    ( item4.length() ? BootstrapWebPage::listItem(item4) : "" ) +
    ( item5.length() ? BootstrapWebPage::listItem(item5) : "" ) +
    ( item6.length() ? BootstrapWebPage::listItem(item6) : "" ) +
    ( item7.length() ? BootstrapWebPage::listItem(item7) : "" ) +
    ( item8.length() ? BootstrapWebPage::listItem(item8) : "" ) +
    ( item9.length() ? BootstrapWebPage::listItem(item9) : "" ) +
    ( item10.length() ? BootstrapWebPage::listItem(item10) : "" ) +
    String("</ul>");
}

String BootstrapWebPage::listItem(String item) {
  return String("<li class='list-group-item'>") + item + String("</li>");
}
