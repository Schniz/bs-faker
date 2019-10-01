open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Helpers", () => {
  describe(".slugify", () => {
    test("accepts optional args", () =>
	  expect(Js.typeof(Helpers.slugify())) === "string"
	);
	test("accepts a string argument", () =>
	  expect(Js.typeof(Helpers.slugify(~str="test", ()))) === "string"
	);
  });

  describe(".replaceSymbolWithNumber", () => {
    test("accepts optional args", () =>
	  expect(Js.typeof(Helpers.replaceSymbolWithNumber())) === "string"
	);
	test("accepts a string argument", () =>
	  expect(Js.typeof(Helpers.replaceSymbolWithNumber(~str="test", ()))) === "string"
	);
	test("accepts a string argument and a symbol argument", () =>
	  expect(Js.typeof(Helpers.replaceSymbolWithNumber(~str="test", ~symbol="t", ()))) === "string"
	);
  });
  
  describe(".replaceSymbols", () => {
    test("accepts optional args", () =>
	  expect(Js.typeof(Helpers.replaceSymbols())) === "string"
	);
	test("accepts a string argument", () =>
	  expect(Js.typeof(Helpers.replaceSymbols(~str="test", ()))) === "string"
	);
  });


  test(".createCard", () =>
    expect(Js.typeof(Helpers.createCard())) === "object"
  );

  test(".contextualCard", () => {
	expect(Js.typeof(Helpers.contextualCard())) === "object"
  });

  describe(".randomize", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Helpers.randomize())) === "string"
    );
    test("accepts an array", () =>
      expect(Js.typeof(Helpers.randomize(~arr=[|1,2,3|], ()))) === "number"
    );
  });

  describe(".shuffle", () => {
    test("accepts optional args", () =>
      expect(Helpers.shuffle()) |> toEqual([||])
    );
    test("accepts an array", () =>
      expect(Helpers.shuffle(~o=[|1, 2, 3|], ())) 
	  |> toContain(1)
    );
  });

  describe(".mustache", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Helpers.mustache())) === "string"
    );
    test("accepts a string arg", () =>
      expect(Js.typeof(Helpers.mustache(~str="test", ()))) === "string"
    );
    test("accepts a string and a JS object arg", () =>
      expect(Js.typeof(Helpers.mustache(~str="test", ~data=Js.Dict.empty(), ()))) === "string"
    );
  });
});
