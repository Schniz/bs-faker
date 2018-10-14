open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Company", () => {
  test("suffixes", () =>
    expect(Js.Array.isArray(Company.suffixes())) === true
  );
  describe("companyName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Company.companyName())) === "string"
    );
    test("accepts format", () =>
      expect(
        Company.companyName(~format=1, ())
        |> Js.String.split(" - ")  /* format 1 is "something - something" */
        |> Js.Array.length,
      )
      === 2
    );
  });
  test("companySuffix", () =>
    expect(Js.typeof(Company.companySuffix())) === "string"
  );
  test("catchPhrase", () =>
    expect(Js.typeof(Company.catchPhrase())) === "string"
  );
  test("bs", () =>
    expect(Js.typeof(Company.bs())) === "string"
  );
  test("catchPhraseAdjective", () =>
    expect(Js.typeof(Company.catchPhraseAdjective())) === "string"
  );
  test("catchPhraseDescriptor", () =>
    expect(Js.typeof(Company.catchPhraseDescriptor())) === "string"
  );
  test("catchPhraseNoun", () =>
    expect(Js.typeof(Company.catchPhraseNoun())) === "string"
  );
  test("bsAdjective", () =>
    expect(Js.typeof(Company.bsAdjective())) === "string"
  );
  test("bsBuzz", () =>
    expect(Js.typeof(Company.bsBuzz())) === "string"
  );
  test("bsNoun", () =>
    expect(Js.typeof(Company.bsNoun())) === "string"
  );
});
