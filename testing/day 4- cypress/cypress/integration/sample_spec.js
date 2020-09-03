describe('First Test', () => {
  it('Visits the Kitchen Sink', () => {
    cy.visit('https://google.am');
    cy.get('input').get('[class="gLFyf gsfi"]').type('test{enter}');
  })
})