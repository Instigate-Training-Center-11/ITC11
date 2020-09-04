const assert = require('assert');

describe('google.com page', async () => {
    it("Title contain testing word ?: ", () => {
        await browser.url('https://google.com');
        const search = await $("[name='q']");
        await search.setValue("testing");

        const header = await $('h3*=Testing')
        console.log(header.getText());

        assert.equal(await header.getText().includes('testing'), true);
    })
})