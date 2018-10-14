open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Hacker", () => {
  test(".abbreviation", () =>
    expect(Js.typeof(Hacker.abbreviation())) === "string"
  );
  test(".adjective", () =>
    expect(Js.typeof(Hacker.adjective())) === "string"
  );
  test(".noun", () =>
    expect(Js.typeof(Hacker.noun())) === "string"
  );
  test(".verb", () =>
    expect(Js.typeof(Hacker.verb())) === "string"
  );
  test(".ingverb", () =>
    expect(Js.typeof(Hacker.ingverb())) === "string"
  );
  test(".phrase", () =>
    expect(Js.typeof(Hacker.phrase())) === "string"
  );
});
