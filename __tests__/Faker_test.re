open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.fake", () => {
  test("returns ok(value) on success", () =>
    expect(
      Faker.fake("Hello {{name.firstName}}") |. Belt.Result.getWithDefault("error"),
    )
    |> toMatchRe(Js.Re.fromString("^Hello \\w+$"))
  );

  test("returns error(message) on error", () =>
    expect(
      Faker.fake("Hello {{shouldn't work}}") |. Belt.Result.getWithDefault("error"),
    )
    === "error"
  );
});
