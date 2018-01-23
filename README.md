# ArduinoWebSite

This library provides simple classes for manging a web site and pages on Arduino projects.

We use [Bootstrap 4](https://getbootstrap.com/) to style the site. Bootstrap is a very popular and powerful web page framework. You've likely seen it in use on dozens of web sites. Bootstrap lets you build good looking web pages but can be verbose and fussy when you write the code for the pages.

Our goal with this library is to help Arduino project users generate simple, good looking pages without having to learn Bootstrap or other web frameworks. We're focussing on just a few, common things that we embed in pages rather than trying to build a complete framework that does every possible thing. Users should be able to quickly build simple sites without having to worry about the details of HTML and CSS.

This library is decoupled from the web server. It focusses solely on page creation and makes no assumptions about the way pages are actually served. It should work with any web server.

# Limitations

In order to save local resources, we load Bootstrap from an external CDN. This will fail if the computer loading pages from the Arduino server is not also connected to the public Internet at the same time.

We use the Arduino `String` type. Memory management `String` is problematic. It may not work well in highly resource-constrained environments.

This library currently does not assist with HTML or URL encoding. HTML needs to escape embedded `<`, `>` and `&` characters. 


# Usage

## WebSite

In this context of this library, a `WebSite` consists of the language of the site (given as a two character ISO language code), the site's name, an optional branding image, and a navigation bar consisting of links to individual pages on the site.

Usage:

```
WebSite site();
WebSite site("en");
WebSite site("en", "My Awesome Arduino Server");
```

## WebPage

Usage:

```
WebSite site("en", "My Groovy Site");
site.addPageToNav("Info", "/info") 

WebPage page(&site, "Info");
page.addHeading("Info");
page.addContent("Uptime " + millis());

```
