var Page = require("./page");

class SearchPage extends Page {
  get searchInput() {
    return $('[name="q"]');
  }

  get firstSearchRresult() {
    return $("ul").$("li").$("span");
  }

  get firstSearchResultAfterClickEnter() {
    return $("#rso").$("a").$("h3");
  }

  search(text) {
    this.searchInput.setValue(text);
  }

  searchWithClickEnter(text) {
    this.searchInput.setValue(text);
    //click Enter button
    browser.keys("\uE007");
  }

  open(path) {
    return super.open(path);
  }
}

module.exports = new SearchPage();
