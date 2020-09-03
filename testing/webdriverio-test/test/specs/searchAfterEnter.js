const SearchPage = require("../pageobjects/search.page");

describe("Google search", () => {
  it("containing 'testing' text in search result", () => {
    SearchPage.open("https://www.google.com");
    SearchPage.searchWithClickEnter("testing");

    expect(SearchPage.firstSearchResultAfterClickEnter).toHaveTextContaining(
      "testing",
      {
        ignoreCase: true,
      }
    );
  });
});
