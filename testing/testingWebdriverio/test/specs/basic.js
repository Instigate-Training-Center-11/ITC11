
describe('google.com page', () => {

    var capabilities = {
        browserName: 'chrome',
        chromeOptions: {
          args: ['--disable-plugins'],
        },
    };

    it('should have the right title', (done) => {
        browser.url('https://google.com')
        expect(browser).toHaveTitle('Google');
    })

    it('should have the right title', (done) => {
        browser.url('https://google.com/ncr')
        search_box_element = $('[name=\'q\']')
        search_box_element.setValue("testing\n")

        expect(browser).toHaveTitle("testing - Google Search");
        var outerHTML = $('.g').getHTML();
        console.log("**********************",outerHTML.includes("testing"));
        browser.saveScreenshot('./screenshot.png');

      })

})


