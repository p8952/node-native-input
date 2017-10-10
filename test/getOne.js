const assert = require("assert");
const nodeNativeInput = require("../index.js");

describe("getOne", function() {
  it("should get one from native module", function() {
    assert.deepEqual(nodeNativeInput.getOne(), [1, 1]);
  });
});
