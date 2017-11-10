const assert = require("assert");
const nodeNativeInput = require("../index.js");

describe("getScreenDimensions", function() {
  it("should be able a bitmap image of the screen", function() {
    assert.equal(Buffer.isBuffer(nodeNativeInput.getScreenBitmap()), true);
  });
});
