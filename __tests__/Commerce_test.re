open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Commerce", () => {
  test(".color", () =>
    expect(Js.typeof(Commerce.color())) === "string"
  );
  test(".department", () =>
    expect(Js.typeof(Commerce.department())) === "string"
  );
  test(".productName", () =>
    expect(Js.typeof(Commerce.productName())) === "string"
  );
  test(".productAdjective", () =>
    expect(Js.typeof(Commerce.productAdjective())) === "string"
  );
  test(".productMaterial", () =>
    expect(Js.typeof(Commerce.productMaterial())) === "string"
  );
  test(".product", () =>
    expect(Js.typeof(Commerce.product())) === "string"
  );
  describe(".price", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Commerce.price())) === "string"
    );
    test("accepts min", () =>
      expect(Commerce.price(~min=900, ()) |> float_of_string) >= 900.
    );
    test("accepts max", () =>
      expect(Commerce.price(~max=3, ()) |> float_of_string) <= 3.
    );
    test("accepts decimal", () =>
      expect(Commerce.price(~decimal=0, ()) |> int_of_string) >= 0
    );
    test("accepts symbol", () =>
      expect(Commerce.price(~symbol="$", ()) |> Js.String.startsWith("$")) === true
    );
  });
});
