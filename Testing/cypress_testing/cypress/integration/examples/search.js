describe('Check whether the user can perform a search in the google.com', () => {
    it("Visit google.com", function() {
        cy.visit('https://www.google.com/');
    });

    it('Search the "testing" keyword',function() {
        cy.get('.gLFyf')
            .type('testing')
            .should('have.value', 'testing')
            .type('{enter}', { force: true });
    });

    it('Verify the search title', function() {
        cy.title().should('eq', 'testing - Google Որոնում');
    });
});