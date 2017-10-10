const assert = require("assert");
const nodeNativeInput = require("../index.js");

describe("getTwo", function() {
  it("should get two from native module", function() {
    assert.deepEqual(nodeNativeInput.getTwo(), [2, 2]);
  });
});
