open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Locale", () => {
  test(".getLocale", () =>
    expect(Locale.getLocale()) === "en"
  );
  test(".setLocale", () => {
    Locale.setLocale(Sk);
    expect(Locale.getLocale()) === "sk";
  });
});
