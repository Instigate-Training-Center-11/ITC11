const SearchPage = require("../pageobjects/search.page");

describe("Google search", () => {
  it("containing 'testing' text in search list", () => {
    SearchPage.open("https://www.google.com");
    SearchPage.search("testing");

    expect(SearchPage.firstSearchRresult).toHaveTextContaining("testing", {
      ignoreCase: true,
    });
  });
});
