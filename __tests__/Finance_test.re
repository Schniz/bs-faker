open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Finance", () => {
  describe(".account", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Finance.account())) === "string"
    );

    test("accepts length", () =>
      expect(Finance.account(~length=3, ()) |> String.length) === 3
    );
  });

  describe(".accountName", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.accountName())) === "string"
    )
  );

  describe(".amount", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Finance.amount())) === "string"
    );

    test("accepts min", () =>
      expect(Js.typeof(Finance.amount(~min=10, ()))) === "string"
    );

    test("accepts max", () =>
      expect(Js.typeof(Finance.amount(~min=10, ~max=20, ()))) === "string"
    );

    test("accepts dec", () =>
      expect(
        Finance.amount(~min=10, ~max=20, ~dec=2, ())
        |> Js.String.split(".")
        |> Array.get(_, 1)
        |> String.length,
      )
      === 2
    );

    test("accepts symbol", () =>
      expect(
        Finance.amount(~min=10, ~max=20, ~dec=2, ~symbol="$", ())
        |> String.sub(_, 0, 1),
      )
      === "$"
    );
  });

  describe(".bic", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.bic())) === "string"
    )
  );

  describe(".bitcoinAddress", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.bitcoinAddress())) === "string"
    )
  );

  describe(".currencyCode", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.currencyCode())) === "string"
    )
  );

  describe(".currencyName", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.currencyName())) === "string"
    )
  );

  describe(".currencySymbol", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.currencySymbol())) === "string"
    )
  );

  describe(".iban", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.iban())) === "string"
    )
  );

  describe(".mask", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Finance.mask())) === "string"
    );

    test("accepts length", () =>
      expect(Finance.mask(~length=3, ()) |> String.length) === 3
    );

    test("accepts parens", () =>
      expect(Finance.mask(~length=1, ~parens=true, ()))
      |> toMatchRe(Js.Re.fromString("\\(\\d\\)"))
    );

    test("accepts ellipsis", () =>
      expect(Finance.mask(~length=1, ~parens=false, ~ellipsis=true, ()))
      |> toMatchRe(Js.Re.fromString("\\.\\.\\.\\d"))
    );

    test("accepts symbol", () =>
      expect(
        Finance.amount(~min=10, ~max=20, ~dec=2, ~symbol="$", ())
        |> String.sub(_, 0, 1),
      )
      === "$"
    );
  });

  describe(".transactionType", () =>
    test("returns string", () =>
      expect(Js.typeof(Finance.transactionType())) === "string"
    )
  );
});