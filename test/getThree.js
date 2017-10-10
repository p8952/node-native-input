const assert = require("assert");
const nodeNativeInput = require("../index.js");

describe("getThree", function() {
  it("should get three from native module", function() {
    assert.deepEqual(nodeNativeInput.getThree(), [3, 3]);
  });
});
