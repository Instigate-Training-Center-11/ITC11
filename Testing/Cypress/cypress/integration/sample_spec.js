describe('My First Test', () => {
    it('Gets, types and asserts', () => {
        cy.visit('https://google.com')

        cy.get('.gLFyf')
        .type('testing\n')

        /* Check in url */
        cy.url()
        .should('include', 'testing')

        /* Check for body <em> element */
        cy.get('.st')
        .children()
        .first()
        .should('contain', 'test')

        /* Check for header element */
        cy.get('.g')
        .first()
        .should('contain', 'testing')

        /* Scroll to bottom of page */
        cy.scrollTo('bottom', { duration: 2000 })

        /* Go to next page */
        cy.get('[aria-label="Page 2"]')
        .click()

        /* Check for fifth element */
        cy.get('.g')
        .eq(4)
        .should('contain', 'testing')

    })
})