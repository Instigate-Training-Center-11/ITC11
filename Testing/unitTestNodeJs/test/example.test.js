
const math = require("../index");
const assert = require('assert');

describe('Simple Math Test For Adding Function', () => {
    it('should return 9', () => {
        const result = math.add(4, '5');
        assert.equal(result, 9);
    });

    it('should return 15', () => {
        const result = math.add(14, 1);
        assert.equal(result, 15);
    });
});

describe('Simple Math Test For Subscribe Function', () => {
    it('should return 40', () => {
        const result = math.sub(45, '5');
        assert.equal(result, 40);
    });

    it('should return -8', () => {
        const result = math.sub(10, 18);
        assert.equal(result, -8);
    });
});

describe('Simple Math Test For Multiplying Function', () => {
    it('should return 64', () => {
        const result = math.multiply(32, '2');
        assert.equal(result, 64);
    });

    it('should return -90', () => {
        const result = math.multiply(10, -9);
        assert.equal(result, -90);
    });
});

describe('Simple Math Test For Division Function', () => {
    it('should return 8', () => {
        const result = math.div(32, '4');
        assert.equal(result, 8);
    });

    it('should return -10', () => {
        const result = math.div(50, -5);
        assert.equal(result, -10);
    });

    it('should return Can not division by 0', () => {
        const result = math.div(50, 0);
        assert.equal(result, 'Can not division by 0');
    });
});