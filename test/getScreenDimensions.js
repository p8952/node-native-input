const assert = require("assert");
const nodeNativeInput = require("../index.js");

describe("getScreenDimensions", function() {
  it("should be able get the dimensions of the screen", function() {
    assert.equal(Array.isArray(nodeNativeInput.getScreenDimensions()), true);

    assert.equal(nodeNativeInput.getScreenDimensions()[0] >= 0, true);
    assert.equal(nodeNativeInput.getScreenDimensions()[1] >= 0, true);

    assert.equal(nodeNativeInput.getScreenDimensions()[0] < 10000, true);
    assert.equal(nodeNativeInput.getScreenDimensions()[1] < 10000, true);
  });
});
