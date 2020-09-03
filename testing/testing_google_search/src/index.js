const remote = require('webdriverio').remote;
 
let browser;

async function test() {
    try {
        browser = await remote({
            capabilities: {
                browserName: 'chrome'
            }
        })

        await browser.navigateTo('https://www.google.com/');
        const searchInput = await browser.$(".gLFyf");
        await searchInput.setValue("testing");
        browser.keys('Enter');
    } catch(err) {
        console.error(err)
        return browser.deleteSession()
    }
}

test();