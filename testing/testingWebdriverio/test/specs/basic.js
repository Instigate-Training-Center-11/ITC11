describe('google.com page', () => {
    it('should have the right title', () => {
        browser.url('https://google.com')
        expect(browser).toHaveTitle('Google');
    })

    it('should have the right title', (done) => {
        browser.url('https://google.com/ncr')
        search_box_element = $('[name=\'q\']')
        search_box_element.setValue("testing\n")

        expect(browser).toHaveTitle("testing - Google Search");
      })

})
