describe('testing', () => {
    before ('Before', () => {
        cy.visit('https://google.com')
        cy.get('input[name=q]').type('testing')
        cy.get('[type="submit"]').contains('Google').click()
    })
    it('test1',() => {
      cy.get('[data-hveid] h3').first().contains('Testing').click()
    })
})
