open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Random", () => {
  describe(".alphaNumeric", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Random.alphaNumeric())) === "string"
    );
    test("generates string of provided length", () => {
      let count = 5;
      expect(
        Helpers.getOrRaise(Random.alphaNumeric(~count, ()))
        |> Js.String.length,
      )
      === count;
    });
  });
  describe(".arrayElement", () => {
    test("returns random array element", () => {
      let array: Js.Array.t(int) = [|1, 7, 3, 19, (-3), 3613|];
      let result =
        switch (Random.arrayElement(~array)) {
        | Some(x) => x
        | None => raise(Not_found)
        };
      expect(Js.Array.includes(result, array)) === true;
    });
    test("returns undefined when passed empty array argument", () =>
      expect(Random.arrayElement(~array=[||])) === None
    );
  });
  test(".boolean", () =>
    expect(Js.typeof(Random.boolean())) === "boolean"
  );
  test(".image", () =>
    expect(Js.typeof(Random.image())) === "string"
  );
  test(".locale", () =>
    expect(Js.typeof(Random.locale())) === "string"
  );
  describe(".number", () => {
    test("accepts defaults for optional args", () =>
      expect(Js.typeof(Random.number())) === "number"
    );
    test("accepts min", () =>
      expect(Random.number(~min=15, ())) |> toBeGreaterThanOrEqual(15)
    );
    test("accepts max", () =>
      expect(Random.number(~max=100, ())) |> toBeLessThanOrEqual(100)
    );
    test("accepts precision", () =>
      expect(Random.number(~precision=35, ()) mod 35) === 0
    );
  });
  test(".uuid", () =>
    expect(Js.typeof(Random.uuid())) === "string"
  );
  test(".word", () =>
    expect(Js.typeof(Random.word())) === "string"
  );
  describe(".words", () => {
    test("accepts defaults for optional args", () =>
      expect(Js.typeof(Random.words())) === "string"
    );
    test("accepts count", () =>
      expect(
        Helpers.getOrRaise(Random.words(~count=5, ()))
        |> Js.String.split(" ")
        |> Js.Array.length,
      )
      >= 5
    ); /* Some words consist of multiple space-separated parts */
  });
});